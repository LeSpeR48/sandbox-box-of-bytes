#include <iostream>

void swap_ptr(int* x, int* y) {
    const int temporary = *x;
    *x = *y;
    *y = temporary;
}

void sort3(int* a, int* b, int* c) {
    if (*a > *b) {
        swap_ptr(a, b);
    }
    if (*b > *c) {
        swap_ptr(b, c);
    }
    if (*a > *b) {
        swap_ptr(a, b);
    }
}

int main() {
    int a = 3;
    int b = 1;
    int c = 2;
    sort3(&a, &b, &c);
    std::cout << a << ' ' << b << ' ' << c << '\n';

    a = 9;
    b = 9;
    c = 1;
    sort3(&a, &b, &c);
    std::cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}
