#include <cstdint>
#include <iostream>

constexpr std::uint8_t UP = 1u << 0;
constexpr std::uint8_t DOWN = 1u << 1;
constexpr std::uint8_t LEFT = 1u << 2;
constexpr std::uint8_t RIGHT = 1u << 3;
constexpr std::uint8_t BTN_A = 1u << 4;
constexpr std::uint8_t BTN_B = 1u << 5;

void print_pad(std::uint8_t pad) {
    bool first = true;
    const auto print_button = [&first, pad](std::uint8_t mask, const char* name) {
        if ((pad & mask) != 0) {
            if (!first) {
                std::cout << ' ';
            }
            std::cout << name;
            first = false;
        }
    };

    print_button(UP, "UP");
    print_button(DOWN, "DOWN");
    print_button(LEFT, "LEFT");
    print_button(RIGHT, "RIGHT");
    print_button(BTN_A, "A");
    print_button(BTN_B, "B");
    std::cout << '\n';
}

int main() {
    print_pad(0x19);
    print_pad(0x22);
    return 0;
}
