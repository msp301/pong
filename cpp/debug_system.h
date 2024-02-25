#ifndef DEBUG_SYSTEM_H
#define DEBUG_SYSTEM_H

#include "ball.h"
#include "paddle.h"

class DebugSystem {
public:
    DebugSystem(Ball* ball, Paddle* player, Paddle* opponent);

    void toggle();

    void printInfo() const;

private:
    bool enabled = false;
    Ball* ball;
    Paddle* player;
    Paddle* opponent;
};

#endif //DEBUG_SYSTEM_H
