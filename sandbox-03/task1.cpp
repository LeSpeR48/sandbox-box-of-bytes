#include <iostream>

const int* max_ptr(const int* a, int n) {
    if (a == nullptr || n <= 0) {
        return nullptr;
    }

    const int* maximum = a;
    for (int i = 1; i < n; ++i) {
        if (a[i] > *maximum) {
            maximum = &a[i];
        }
    }
    return maximum;
}

int main() {
    const int values[] = {3, 9, 2, 9, 5};
    const int* maximum = max_ptr(values, 5);
    if (maximum != nullptr) {
        std::cout << *maximum << ' ' << (maximum - values) << '\n';
    }
    return 0;
}
