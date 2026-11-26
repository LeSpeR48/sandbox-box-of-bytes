#include <iostream>

int hex_digit_value(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}

int hex_value(const char* text) {
    if (text == nullptr || text[0] != '0' || text[1] != 'x') {
        return -1;
    }

    int value = 0;
    int digits = 0;
    for (int i = 2; text[i] != '\0'; ++i) {
        const int digit = hex_digit_value(text[i]);
        if (digit < 0) {
            return -1;
        }
        value = value * 16 + digit;
        ++digits;
    }
    return digits > 0 ? value : -1;
}

int main() {
    std::cout << hex_value("0x41") << ' '
              << hex_value("0xff") << ' '
              << hex_value("0x1A2") << '\n';
    return 0;
}
