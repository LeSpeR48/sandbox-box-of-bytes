#include <iostream>

int fib(int n) {
    if (n < 2) {
        return n;
    }

    int previous = 0;
    int current = 1;
    for (int i = 2; i <= n; ++i) {
        const int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int main() {
    std::cout << fib(10) << ' ' << fib(40) << '\n';
    return 0;
}
