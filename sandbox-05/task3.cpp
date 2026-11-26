#include <iostream>

int main() {
    const int matrix[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int transposed[4][3] = {};

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 4; ++column) {
            transposed[column][row] = matrix[row][column];
        }
    }

    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 3; ++column) {
            if (column != 0) {
                std::cout << ' ';
            }
            std::cout << transposed[row][column];
        }
        std::cout << '\n';
    }
    return 0;
}
