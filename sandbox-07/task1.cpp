#include <iostream>
#include <limits>

int main() {
    constexpr long long int_max = std::numeric_limits<int>::max();
    long long factorial = 1;
    int n = 1;

    while (factorial <= int_max / (n + 1)) {
        ++n;
        factorial *= n;
    }

    std::cout << n << '\n';
    return 0;
}
