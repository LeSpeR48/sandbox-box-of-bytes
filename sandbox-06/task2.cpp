#include <iostream>

enum class Dir {
    North,
    East,
    South,
    West
};

Dir turn_right(Dir direction) {
    switch (direction) {
    case Dir::North:
        return Dir::East;
    case Dir::East:
        return Dir::South;
    case Dir::South:
        return Dir::West;
    case Dir::West:
        return Dir::North;
    }
    return Dir::North;
}

int main() {
    Dir direction = Dir::North;
    for (int i = 0; i < 5; ++i) {
        direction = turn_right(direction);
        std::cout << static_cast<int>(direction)
                  << (i == 4 ? '\n' : ' ');
    }
    return 0;
}
