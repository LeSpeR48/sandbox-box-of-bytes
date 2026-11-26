#include <iostream>

int find_last(const int* a, int n, int x) {
    if (a == nullptr || n <= 0) {
        return -1;
    }

    for (int i = n; i > 0; --i) {
        if (a[i - 1] == x) {
            return i - 1;
        }
    }
    return -1;
}

int main() {
    const int values[] = {4, 2, 4, 4, 1};
    std::cout << find_last(values, 5, 4) << ' '
              << find_last(values, 5, 9) << '\n';
    return 0;
}
