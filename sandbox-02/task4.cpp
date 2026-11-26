#include <iostream>
#include <limits>

bool bit_is_set(int value, int n) {
    if (n < 0 || n >= std::numeric_limits<unsigned int>::digits) {
        return false;
    }
    return (static_cast<unsigned int>(value) & (1u << n)) != 0;
}

int main() {
    const int value = 6;
    std::cout << bit_is_set(value, 0) << ' '
              << bit_is_set(value, 1) << ' '
              << bit_is_set(value, 2) << '\n';
    return 0;
}
