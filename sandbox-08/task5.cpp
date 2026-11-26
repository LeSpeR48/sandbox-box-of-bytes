#include <cstdint>
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

bool check_nmea(const char* sentence) {
    if (sentence == nullptr || sentence[0] != '$') {
        return false;
    }

    std::uint8_t checksum = 0;
    int position = 1;
    while (sentence[position] != '\0' && sentence[position] != '*') {
        checksum ^= static_cast<std::uint8_t>(sentence[position]);
        ++position;
    }

    if (sentence[position] != '*') {
        return false;
    }
    if (sentence[position + 1] == '\0'
        || sentence[position + 2] == '\0') {
        return false;
    }

    const int high = hex_digit_value(sentence[position + 1]);
    const int low = hex_digit_value(sentence[position + 2]);
    if (high < 0 || low < 0 || sentence[position + 3] != '\0') {
        return false;
    }

    const int expected = high * 16 + low;
    return checksum == expected;
}

int main() {
    const char* valid =
        "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    const char* changed =
        "$GPGGA,123519,4807.039,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    std::cout << check_nmea(valid) << ' ' << check_nmea(changed) << '\n';
    return 0;
}
