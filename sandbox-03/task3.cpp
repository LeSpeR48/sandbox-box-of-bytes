#include <iostream>

void reverse(int* a, int n) {
    if (a == nullptr || n <= 1) {
        return;
    }

    int* left = a;
    int* right = a + n - 1;
    while (left < right) {
        const int temporary = *left;
        *left = *right;
        *right = temporary;
        ++left;
        --right;
    }
}

int main() {
    int values[] = {1, 2, 3, 4, 5};
    reverse(values, 5);

    for (int i = 0; i < 5; ++i) {
        if (i != 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
    return 0;
}
