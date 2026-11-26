#include <cstdint>
#include <iostream>

std::uint8_t mirror(std::uint8_t b) {
    std::uint8_t result = 0;
    for (int i = 0; i < 8; ++i) {
        result = static_cast<std::uint8_t>((result << 1) | (b & 1u));
        b >>= 1;
    }
    return result;
}

int main() {
    std::cout << std::hex
              << static_cast<unsigned int>(mirror(0x01)) << ' '
              << static_cast<unsigned int>(mirror(0xA0)) << ' '
              << static_cast<unsigned int>(mirror(0x3C)) << '\n';
    return 0;
}
