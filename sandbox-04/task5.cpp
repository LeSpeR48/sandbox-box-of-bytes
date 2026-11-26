#include <iostream>

int main() {
    for (unsigned i = 10;; --i) {
        std::cout << i << (i == 0 ? '\n' : ' ');
        if (i == 0) {
            break;
        }
    }
    return 0;
}
