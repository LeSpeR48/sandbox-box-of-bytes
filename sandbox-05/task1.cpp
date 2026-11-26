#include <cctype>
#include <iostream>

bool is_palindrome(const char* s) {
    if (s == nullptr) {
        return false;
    }

    const char* left = s;
    const char* right = s;
    while (*right != '\0') {
        ++right;
    }
    if (right == s) {
        return true;
    }
    --right;

    while (left < right) {
        const unsigned char left_char = static_cast<unsigned char>(*left);
        const unsigned char right_char = static_cast<unsigned char>(*right);
        if (std::tolower(left_char) != std::tolower(right_char)) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main() {
    std::cout << is_palindrome("Level") << ' '
              << is_palindrome("Radar") << ' '
              << is_palindrome("hello") << '\n';
    return 0;
}
