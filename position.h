#ifndef POSITION_H
#define POSITION_H

struct Position {
    Position(const int x, const int y) : X(x), Y(y) {};

    void set(const int x, const int y) { X = x; Y = y; }

    int X;
    int Y;
};

#endif //POSITION_H
