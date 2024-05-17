#include <ezcpp>

int main() {
    vec<int> v = {1, 2, 3};

    str s = join(", ", map<str>(v, to_str<int>));

    // print the string
    print("s: {}", s);
}
