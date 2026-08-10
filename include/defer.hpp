#pragma once
#include <utility>

namespace ext
{
namespace detail
{
template <typename F> 
class defer_raii final
{
public:
  // copy/move construction and any kind of assignment would lead to the cleanup function getting
  // called twice. We can't have that.
  defer_raii(defer_raii &&) = delete;
  defer_raii(const defer_raii &) = delete;
  defer_raii &operator=(const defer_raii &) = delete;
  defer_raii &operator=(defer_raii &&) = delete;

  // construct the object from the given callable
  template <typename FF> constexpr explicit defer_raii(FF &&f) noexcept : cleanup_function(std::forward<FF>(f)) {}

  // when the object goes out of scope call the cleanup function
  __attribute__((always_inline)) ~defer_raii() noexcept { cleanup_function(); }

private:
  const F cleanup_function;
};
}  // namespace detail

struct ADDExpression 
{
  template <typename F> constexpr __attribute__((always_inline)) detail::defer_raii<F> operator+(F&& f) const noexcept
  {
    return detail::defer_raii<F>{std::forward<F>(f)};
  }
};

#define DEFER_ACTUALLY_JOIN(x, y) x##y
#define DEFER_JOIN(x, y) DEFER_ACTUALLY_JOIN(x, y)
#ifdef __COUNTER__
  #define UNIQUE_VARNAME(x) DEFER_JOIN(x, __COUNTER__)
#else
  #define UNIQUE_VARNAME(x) DEFER_JOIN(x, __LINE__)
#endif

// #define defer(lambda__) [[maybe_unused]] const auto& UNIQUE_VARNAME(defer_object) = ext::defer([&]() lambda__)
#define defer const auto& UNIQUE_VARNAME(defer_object) [[maybe_unused]] = ext::ADDExpression() + [&]() noexcept
}  // namespace ext
