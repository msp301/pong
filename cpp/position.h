#ifndef POSITION_H
#define POSITION_H

#include <string>

struct Position {
    Position(const int x, const int y) : X(x), Y(y) {};

    void set(const int x, const int y) { X = x; Y = y; }
    [[nodiscard]] std::string toString() const;

    int X;
    int Y;
};

#endif //POSITION_H
