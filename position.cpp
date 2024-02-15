#include "position.h"
#include "screen.h"

Position::Position(const int x, const int y) {
    int coord_x = (x > SCREEN_WIDTH) ? SCREEN_WIDTH : x;
    coord_x = (x < 0) ? 0 : coord_x;

    int coord_y = (y > SCREEN_HEIGHT) ? SCREEN_HEIGHT : y;
    coord_y = (y < 0) ? 0 : coord_y;

    X = coord_x;
    Y = coord_y;
}

int Position::getX() const {
    return X;
}

int Position::getY() const {
    return Y;
}
