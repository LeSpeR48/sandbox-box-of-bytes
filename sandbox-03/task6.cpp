#include <iostream>

int sum(const int* begin, const int* end) {
    int total = 0;
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

int main() {
    const int values[] = {1, 2, 3};
    std::cout << sum(values, values + 3) << ' '
              << sum(values, values) << '\n';
    return 0;
}
