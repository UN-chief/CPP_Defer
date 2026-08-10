#CPP_Defer

C++ defer based on C++ RAll makes the code simpler

基于C++RAll机制的C++ defer，让代码更加简洁


Testing on Clang shows near-zero overhead with excellent optimization capability from Clang.

目前在clang上测试几乎没有开销，clang能优化得很好

GCC introduces minor runtime overhead, which can likely be eliminated by enabling dedicated compilation flags.

在gcc上测试有一点点开销，可能要加特定的编译选项才能优化掉那一点开销

MSVC untested.

msvc暂未进行测试


See src/main.cpp for usage instructions.
使用方法见src/main.cpp
