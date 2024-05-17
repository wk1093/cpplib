#pragma once
#include "str.hpp"

/*@DOC
@SECTION(files)
@FILE
This file contains the implementation of the `debug_print` macro.
*/

#define _CPPLIB_DEBUG_PRINT_0(a) std::cout << #a << ": " << a << std::endl
#define _CPPLIB_DEBUG_PRINT_1(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_0(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_2(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_1(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_3(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_2(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_4(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_3(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_5(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_4(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_6(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_5(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_7(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_6(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_8(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_7(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_9(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_8(__VA_ARGS__)
#define _CPPLIB_DEBUG_PRINT_10(a, ...) std::cout << #a << ": " << a << std::endl; _CPPLIB_DEBUG_PRINT_9(__VA_ARGS__)

#define _CPPLIB_DEBUG_PRINT_CHOOSER(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define _CPPLIB_DEBUG_PRINT_NARGS(...) _CPPLIB_DEBUG_PRINT_CHOOSER(__VA_ARGS__, _CPPLIB_DEBUG_PRINT_10, _CPPLIB_DEBUG_PRINT_9, _CPPLIB_DEBUG_PRINT_8, _CPPLIB_DEBUG_PRINT_7, _CPPLIB_DEBUG_PRINT_6, _CPPLIB_DEBUG_PRINT_5, _CPPLIB_DEBUG_PRINT_4, _CPPLIB_DEBUG_PRINT_3, _CPPLIB_DEBUG_PRINT_2, _CPPLIB_DEBUG_PRINT_1, _CPPLIB_DEBUG_PRINT_0)(__VA_ARGS__)

/*@DOC
@SECTION(macros)
@MACRO
Prints the expression given with its value.
> #### WARNING
> This macro can only print up to 10 arguments.
> And it will fail if you try to print a type that does not have an `operator<<` defined.

Example:
```cpp
vec<int> v = {1, 2, 3, 4};
debug_print(v, v[0]);
// Output:
// v: vec{1, 2, 3, 4}
// v[0]: 1
```
*/
#define debug_print(...) _CPPLIB_DEBUG_PRINT_NARGS(__VA_ARGS__)


