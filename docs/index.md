# CppLib

Simple library for C++ projects.

## Files


### `debug.hpp`

This file contains the implementation of the `debug_print` macro.

### `map.hpp`

This file contains the implementation of the `map` function.

### `str.hpp`

This file contains the implementation of the `str` class and some string related functions.

### `vec.hpp`

This file contains the implementation of the `vec` class and some vector related functions.

### `cpp`

This file includes all the headers from the cpplib library.
To use the library, you need to use `cpp::` before the functions and classes.

### `ezcpp`

This file includes all the headers from the cpplib library.
This version of the library does not require you to use `cpp::` before the functions and classes.

## Classes


### `str`
```cpp
class str : public std::string;
```

This class is a wrapper around std::string. It is used to provide a more convenient interface for working with strings.

```cpp
str() : std::string();
```

Initializes an empty string.

```cpp
str(const char *s) : std::string(s);
```

Initializes the string with a C string.

```cpp
str(const std::string &s) : std::string(s);
```

Initializes the string with a C++ standard string.

```cpp
str(std::initializer_list<char> l) : std::string(l);
```

Initializes the string with an initializer list.

```cpp
str operator+(const str &other) const;
```

Concatenates two strings.

```cpp
str operator+(const char *other) const;
```

Concatenates a string and a C string.

```cpp
str operator+(char other) const;
```

Concatenates a string and a character.

```cpp
str operator*(int n) const;
```

Repeats the string n times.

```cpp
template <typename T> [[nodiscard]] str join(const T &iterable) const;
```

Joins a list with this string as a seperator.
Not recommended for use, use the global join function.

```cpp
template <typename T> str join(const std::initializer_list<T> &iterable) const;
```

Joins an initializer list with this string as a seperator.
Not recommended for use, use the global join function.

```cpp
operator const char*() const;
```

Returns the string as a C string.

```cpp
template <typename... Args> str format(const Args... args) const;
```

Formats the string with the given arguments using {} as placeholders.

```cpp
str lower() const;
```

Returns the string in lowercase.

```cpp
str upper() const;
```

Returns the string in uppercase.

```cpp
str strip() const;
```

Returns the string with leading and trailing whitespace removed.

```cpp
str lstrip() const;
```

Returns the string with leading whitespace removed.

```cpp
str rstrip() const;
```

Returns the string with trailing whitespace removed.

```cpp
[[nodiscard]] str replace(const str &old, const str &new_) const;
```

Replaces all instances of old with new in the string.

```cpp
[[nodiscard]] vec<str> split(const str &sep) const;
```

Splits the string by the given separator.

### `vec`
```cpp
template <typename T> class vec : public std::vector<T>;
```

This class is a wrapper around std::vector. It is used to provide a more convenient interface for working with vectors.

```cpp
vec() : std::vector<T>();
```

Initializes the vector with no elements.

```cpp
vec(const std::vector<T> &v) : std::vector<T>(v);
```

Initializes the vector with a C++ standard vector.

```cpp
vec(std::initializer_list<T> l) : std::vector<T>(l);
```

Initializes the vector with an initializer list.

```cpp
vec(size_t n, const T &val) : std::vector<T>(n, val);
```

Initializes the vector with n elements, all set to val.

```cpp
vec(size_t n) : std::vector<T>(n);
```

Initializes the vector with n elements.

```cpp
operator std::vector<T>() const;
```

Returns the vector as a C++ standard vector.

## Functions


### `map`
```cpp
template<typename T, typename F> vec<T> map(const vec<F> &v, std::function<T(F)> f);
```

Applies a function to each element of a vector and returns a new vector with the results.

Example:
```cpp
vec<int> v = {1, 2, 3, 4};
str s = join(", ", map<str>(v, to_str<int>));
// s == "1, 2, 3, 4"

// Some compilers may require you to specify both template arguments:
// str s = join(", ", map<str, int>(v, to_str<int>));
```

### `to_str`
```cpp
template <typename T> str to_str(const T& t);
```

This function converts a value to a str object.

### `print`
```cpp
template <typename... Args> inline void print(const str &s, Args... args);
```

Prints the given string formatted with the given arguments.

### `println`
```cpp
template <typename... Args> inline void println(const str &s, Args... args);
```

Prints the given string formatted with the given arguments and a newline at the end.

### `_s`
```cpp
inline str operator""_s(const char *s, unsigned long long n);
```

A str literal.

### `join`
```cpp
inline str join(const str &s, const vec<str> &v);
```

Joins a string vector with a string seperator

### `join`
```cpp
inline str join(const str &s, const std::initializer_list<str> &v);
```

Joins a string initializer list with a string seperator

### `split`
```cpp
inline vec<str> split(const str &s, const str &sep);
```

Splits a string by a separator

### `format`
```cpp
template <typename... Args> inline str format(const str& format_str, Args... args);
```

Formats a string with the given arguments. Same as `str::format`.

### `operator<<`
```cpp
template <typename T> std::ostream& operator<<(std::ostream& os, cpp::vec<T> v);
```

Outputs the vector in the human-readable format `vec{elem1, elem2, ...}`.

## Macros


### `debug_print`
```cpp
#define debug_print(...)
```

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