#pragma once
#include "vec.hpp"
#include <functional>

/*@DOC
@SECTION(files)
@FILE
This file contains the implementation of the `map` function.
*/

namespace cpp {
/*@DOC
@SECTION(functions)
@FUNCTION
Applies a function to each element of a vector and returns a new vector with the results.

Example:
```cpp
vec<int> v = {1, 2, 3, 4};
str s = join(", ", map<str>(v, to_str<int>));
// s == "1, 2, 3, 4"

// Some compilers may require you to specify both template arguments:
// str s = join(", ", map<str, int>(v, to_str<int>));
```
*/
    template<typename T, typename F>
    vec<T> map(const vec<F> &v, std::function<T(F)> f) {
        vec<T> r;
        for (const auto &x: v) {
            r.push_back(f(x));
        }
        return r;
    }
}