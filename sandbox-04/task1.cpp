#include <iostream>

int collatz_steps(int n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        ++steps;
    }
    return steps;
}

int main() {
    int longest_number = 1;
    int longest_steps = 0;

    for (int n = 1; n < 100; ++n) {
        const int steps = collatz_steps(n);
        if (steps > longest_steps) {
            longest_number = n;
            longest_steps = steps;
        }
    }

    std::cout << longest_number << ' ' << longest_steps << '\n';
    return 0;
}
