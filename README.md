#CPP_Defer

C++ defer based on C++ RAll makes the code simpler

基于C++RAll机制的C++ defer，让代码更加简洁

Testing on Clang shows nearly zero overhead; Clang is capable of near-perfect optimization.

GCC introduces minor runtime overhead, which can likely be eliminated by enabling dedicated compilation flags.

MSVC untested.

目前在clang上测试几乎没有开销，clang几乎能进行完美优化

在gcc上测试有一点点开销，可能要加特定的编译选项才能优化掉那一点开销

msvc暂未进行测试
