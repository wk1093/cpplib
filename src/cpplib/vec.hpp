#pragma once

#include <vector>
#include <ostream>

/*@DOC
@SECTION(files)
@FILE
This file contains the implementation of the `vec` class and some vector related functions.
*/

namespace cpp {
    template <typename T>
    class vec;
/*@DOC
@SECTION(classes)
@CLASS
This class is a wrapper around std::vector. It is used to provide a more convenient interface for working with vectors.
*/
    template <typename T>
    class vec : public std::vector<T> {
    public:
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the vector with no elements.
*/
        vec() : std::vector<T>() {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the vector with a C++ standard vector.
*/
        vec(const std::vector<T> &v) : std::vector<T>(v) {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the vector with an initializer list.
*/
        vec(std::initializer_list<T> l) : std::vector<T>(l) {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the vector with n elements, all set to val.
*/
        vec(size_t n, const T &val) : std::vector<T>(n, val) {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the vector with n elements.
*/
        vec(size_t n) : std::vector<T>(n) {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Returns the vector as a C++ standard vector.
*/
        operator std::vector<T>() const {
            return *this;
        }

        using std::vector<T>::operator[];
        using std::vector<T>::begin;
        using std::vector<T>::end;
        using std::vector<T>::size;
        using std::vector<T>::push_back;
        using std::vector<T>::pop_back;
    };
}
/*@DOC
@SECTION(functions)
@FUNCTION
Outputs the vector in the human-readable format `vec{elem1, elem2, ...}`.
*/
template <typename T>
std::ostream& operator<<(std::ostream& os, cpp::vec<T> v) {
    os << "vec{";
    bool f = true;
    for (const T& i : v) {
        if (!f) {
            os << ", ";
        }
        f = false;
        os << i;
    }
    os << "}";
    return os;
}