#include <iostream>

int max_of(const int* a, int n) {
    if (a == nullptr || n <= 0) {
        return 0;
    }

    int maximum = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > maximum) {
            maximum = a[i];
        }
    }
    return maximum;
}

int main() {
    const int data[] = {5, 42, 7, 1, 9, 13, 2, 8, 30, 11};
    const int count = static_cast<int>(sizeof(data) / sizeof(data[0]));
    std::cout << count << ' ' << max_of(data, count) << '\n';
    return 0;
}
