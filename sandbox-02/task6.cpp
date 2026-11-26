#include <cstdint>
#include <iostream>

std::uint32_t pack(int r, int g, int b) {
    const std::uint32_t red = static_cast<std::uint32_t>(r) & 0xFFu;
    const std::uint32_t green = static_cast<std::uint32_t>(g) & 0xFFu;
    const std::uint32_t blue = static_cast<std::uint32_t>(b) & 0xFFu;
    return (red << 16) | (green << 8) | blue;
}

int main() {
    std::cout << std::hex << pack(255, 136, 0) << ' '
              << pack(0, 128, 255) << '\n';
    return 0;
}
