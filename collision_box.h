#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H
#include "position.h"

class CollisionBox {
public:
    CollisionBox(const int width, const int height, Position* position) : width(width), height(height), position(position) {}

    int width = 0;
    int height = 0;
    Position* position;
};

#endif //COLLISIONBOX_H
