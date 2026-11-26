#include <iostream>
#include <limits>

int next_pow2(int x) {
    if (x <= 1) {
        return 1;
    }

    int power = 1;
    while (power < x) {
        if (power > std::numeric_limits<int>::max() / 2) {
            return -1;
        }
        power <<= 1;
    }
    return power;
}

int main() {
    std::cout << next_pow2(5) << ' '
              << next_pow2(64) << ' '
              << next_pow2(100) << '\n';
    return 0;
}
