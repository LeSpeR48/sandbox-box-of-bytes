#include <iostream>

int insertion_sort(int* a, int n) {
    int shifts = 0;
    for (int i = 1; i < n; ++i) {
        const int value = a[i];
        int position = i;
        while (position > 0 && a[position - 1] > value) {
            a[position] = a[position - 1];
            --position;
            ++shifts;
        }
        a[position] = value;
    }
    return shifts;
}

int main() {
    int values[] = {5, 4, 3, 2, 1};
    const int size = static_cast<int>(sizeof(values) / sizeof(values[0]));
    const int shifts = insertion_sort(values, size);

    for (int i = 0; i < size; ++i) {
        std::cout << values[i] << ' ';
    }
    std::cout << shifts << '\n';
    return 0;
}
