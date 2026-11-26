#include <iostream>

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool parse_number(const char* text, int& position, int& value) {
    const int start = position;
    value = 0;
    while (is_digit(text[position])) {
        value = value * 10 + (text[position] - '0');
        ++position;
    }
    return position > start;
}

bool evaluate(const char* text, int& result, int& error_position) {
    int position = 0;
    int left = 0;
    int right = 0;

    if (!parse_number(text, position, left)) {
        error_position = position;
        return false;
    }

    const char operation = text[position];
    if (operation != '+' && operation != '-' && operation != '*') {
        error_position = position;
        return false;
    }
    ++position;

    if (!parse_number(text, position, right)) {
        error_position = position;
        return false;
    }
    if (text[position] != '\0') {
        error_position = position;
        return false;
    }

    if (operation == '+') {
        result = left + right;
    } else if (operation == '-') {
        result = left - right;
    } else {
        result = left * right;
    }
    return true;
}

void print_result(const char* expression) {
    int result = 0;
    int error_position = 0;
    if (evaluate(expression, result, error_position)) {
        std::cout << result << '\n';
    } else {
        std::cout << "error at " << error_position << '\n';
    }
}

int main() {
    print_result("12+34");
    print_result("7*6x");
    return 0;
}
