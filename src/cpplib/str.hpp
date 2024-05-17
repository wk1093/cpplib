#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "vec.hpp"

/*@DOC
@SECTION(files)
@FILE
This file contains the implementation of the `str` class and some string related functions.
*/

namespace cpp {

    class str;
/*@DOC
@SECTION(functions)
@FUNCTION
This function converts a value to a str object.
*/
    template <typename T>
    str to_str(const T& t);

/*@DOC
@SECTION(classes)
@CLASS
This class is a wrapper around std::string. It is used to provide a more convenient interface for working with strings.
*/
    class str : public std::string {
    public:
        using std::string::string;
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes an empty string.
*/
        str() : std::string() {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the string with a C string.
*/
        str(const char *s) : std::string(s) {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the string with a C++ standard string.
*/
        str(const std::string &s) : std::string(s) {}

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Initializes the string with an initializer list.
*/
        str(std::initializer_list<char> l) : std::string(l) {}
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Concatenates two strings.
*/
        str operator+(const str &other) const {
            str s = *this;
            s += other;
            return s;
        }
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Concatenates a string and a C string.
*/
        str operator+(const char *other) const {
            str s = *this;
            s += other;
            return s;
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Concatenates a string and a character.
*/
        str operator+(char other) const {
            str s = *this;
            s += other;
            return s;
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Repeats the string n times.
*/
        str operator*(int n) const {
            str s;
            for (int i = 0; i < n; i++) {
                s += *this;
            }
            return s;
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Joins a list with this string as a seperator.
Not recommended for use, use the global join function.
*/
        template <typename T>
        [[nodiscard]] str join(const T &iterable) const {
            str s;
            bool first = true;
            for (const auto &x : iterable) {
                if (!first) {
                    s += *this;
                }
                s += x;
                first = false;
            }
            return s;
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Joins an initializer list with this string as a seperator.
Not recommended for use, use the global join function.
*/
        template <typename T>
        str join(const std::initializer_list<T> &iterable) const {
            return join(std::vector<T>(iterable));
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Returns the string as a C string.
*/
        operator const char*() const {
            return this->c_str();
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Formats the string with the given arguments using {} as placeholders.
*/
        template <typename... Args>
        str format(const Args... args) const {
            // C formatting using %s, %d, etc.
            std::string s = *this;
            std::ostringstream ss;
            size_t num_args = sizeof...(args);
            int i = 0;
            int n = s.size();
            int i_args = 0;
            vec<str> a = {to_str(args)...};
            while (i < n) {
                if (s[i] == '{' && i + 1 < n) {
                    if (s[i + 1] == '{') {
                        ss << '{';
                        i += 2;
                    } else if (s[i + 1] == '}') {
                        if (i_args + 1 > num_args) {
                            std::cerr << "Not enough arguments in format call!" << std::endl;
                        }
                        ss << a[i_args++];

                        i += 2;
                    } else {
                        ss << s[i];
                        i++;
                    }
                } else {
                    ss << s[i];
                    i++;
                }
            }
            if (i_args < num_args) {
                std::cerr << "Too many arguments in format call!" << std::endl;
            }

            return ss.str();
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Returns the string in lowercase.
*/
        str lower() const {
            str s = *this;
            for (char &c : s) {
                if ('A' <= c && c <= 'Z') {
                    c = c - 'A' + 'a';
                }
            }
            return s;
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Returns the string in uppercase.
*/
        str upper() const {
            str s = *this;
            for (char &c : s) {
                if ('a' <= c && c <= 'z') {
                    c = c - 'a' + 'A';
                }
            }
            return s;
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Returns the string with leading and trailing whitespace removed.
*/
        str strip() const {
            str s = *this;
            int i = 0;
            int n = s.size();
            while (i < n && std::isspace(s[i])) {
                i++;
            }
            int j = n - 1;
            while (j >= 0 && std::isspace(s[j])) {
                j--;
            }
            return s.substr(i, j - i + 1);
        }
/*@DOC
@SECTION(classes)
@CLASS_FUNC
Returns the string with leading whitespace removed.
*/
        str lstrip() const {
            str s = *this;
            int i = 0;
            int n = s.size();
            while (i < n && std::isspace(s[i])) {
                i++;
            }
            return s.substr(i);
        }

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Returns the string with trailing whitespace removed.
*/
        str rstrip() const {
            str s = *this;
            int j = s.size() - 1;
            while (j >= 0 && std::isspace(s[j])) {
                j--;
            }
            return s.substr(0, j + 1);
        }

        using std::string::replace;

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Replaces all instances of old with new in the string.
*/
        [[nodiscard]] str replace(const str &old, const str &new_) const {
            str s = *this;
            size_t pos = 0;
            while ((pos = s.find(old, pos)) != std::string::npos) {
                s.replace(pos, old.size(), new_);
                pos += new_.size();
            }
            return s;
        }

        using std::string::find;
        using std::string::rfind;
        using std::string::substr;

/*@DOC
@SECTION(classes)
@CLASS_FUNC
Splits the string by the given separator.
*/
        [[nodiscard]] vec<str> split(const str &sep) const {
            cpp::vec<str> v;
            str s = *this;
            size_t pos = 0;
            while ((pos = s.find(sep)) != std::string::npos) {
                v.push_back(s.substr(0, pos));
                s = s.substr(pos + sep.size());
            }
            v.push_back(s);
            return v;
        }
    };
// already documented above
    template <typename T>
    inline str to_str(const T& t) {
        std::ostringstream oss;
        oss << t;
        return oss.str();
    }

/*@DOC
@SECTION(functions)
@FUNCTION
Prints the given string formatted with the given arguments.
*/
    template <typename... Args>
    inline void print(const str &s, Args... args) {
        std::cout << s.format(args...);
    }
/*@DOC
@SECTION(functions)
@FUNCTION
Prints the given string formatted with the given arguments and a newline at the end.
*/
    template <typename... Args>
    inline void println(const str &s, Args... args) {
        std::cout << s.format(args...) << std::endl;
    }

/*@DOC
@SECTION(functions)
@FUNCTION
A str literal.
*/
    inline str operator""_s(const char *s, unsigned long long n) {
        return {s, n};
    }

/*@DOC
@SECTION(functions)
@FUNCTION
Joins a string vector with a string seperator
*/
    inline str join(const str &s, const vec<str> &v) {
        return s.join(v);
    }

/*@DOC
@SECTION(functions)
@FUNCTION
Joins a string initializer list with a string seperator
*/
    inline str join(const str &s, const std::initializer_list<str> &v) {
        return s.join(v);
    }

/*@DOC
@SECTION(functions)
@FUNCTION
Splits a string by a separator
*/
    inline vec<str> split(const str &s, const str &sep) {
        return s.split(sep);
    }

/*@DOC
@SECTION(functions)
@FUNCTION
Formats a string with the given arguments. Same as `str::format`.
*/
    template <typename... Args>
    inline str format(const str& format_str, Args... args) {
        return format_str.format(args...);
    }
}