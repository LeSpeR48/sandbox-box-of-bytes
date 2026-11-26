#include <cstdint>
#include <cstring>
#include <iostream>
#include <limits>

static_assert(sizeof(float) == sizeof(std::uint32_t),
              "This program requires a 32-bit float.");
static_assert(std::numeric_limits<float>::is_iec559,
              "This program requires an IEEE 754 float.");

void print_fields(float value) {
    std::uint32_t bits = 0;
    std::memcpy(&bits, &value, sizeof(bits));

    const std::uint32_t sign = (bits >> 31) & 1u;
    const std::uint32_t exponent = (bits >> 23) & 0xFFu;
    std::cout << sign << ' ' << exponent << '\n';
}

int main() {
    print_fields(-2.5f);
    print_fields(1.0f);
    return 0;
}
