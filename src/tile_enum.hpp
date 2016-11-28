#ifndef TILEENUM_HPP
#define TILEENUM_HPP

enum class Tile : char {
    Error = -1,
    Background,
    Empty,
    Target,
    Wall,
    Box,
    ArrangedBox
};

#endif // TILEENUM_HPP
