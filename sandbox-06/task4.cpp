#include <cstdint>
#include <iostream>

std::uint8_t pack(const bool buttons[8]) {
    std::uint8_t result = 0;
    for (int i = 0; i < 8; ++i) {
        if (buttons[i]) {
            result = static_cast<std::uint8_t>(result | (1u << i));
        }
    }
    return result;
}

int main() {
    const bool buttons[8] = {true, false, false, true, true, false, false, false};
    const std::uint8_t packed = pack(buttons);

    std::cout << static_cast<unsigned int>(packed) << '\n';
    for (int i = 0; i < 8; ++i) {
        std::cout << ((packed >> i) & 1u)
                  << (i == 7 ? '\n' : ' ');
    }
    return 0;
}
