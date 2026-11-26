#include <iostream>

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void tokenize(const char* line) {
    int position = 0;
    bool first = true;

    while (line[position] != '\0') {
        if (!first) {
            std::cout << ' ';
        }
        first = false;

        if (is_digit(line[position])) {
            std::cout << "Number(";
            while (is_digit(line[position])) {
                std::cout << line[position];
                ++position;
            }
            std::cout << ')';
        } else if (is_letter(line[position])) {
            std::cout << "Ident(";
            while (is_letter(line[position])) {
                std::cout << line[position];
                ++position;
            }
            std::cout << ')';
        } else {
            std::cout << "Punct(" << line[position] << ')';
            ++position;
        }
    }
    std::cout << '\n';
}

int main() {
    tokenize("ab=7");
    tokenize("count=12+x");
    return 0;
}
