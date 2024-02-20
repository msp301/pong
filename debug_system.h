#ifndef DEBUG_SYSTEM_H
#define DEBUG_SYSTEM_H

#include "ball.h"
#include "paddle.h"

class DebugSystem {
    DebugSystem(Ball* ball, Paddle* player, Paddle* opponent);

    void printInfo();

private:
    bool enabled = false;
    Ball* ball;
    Paddle* player;
    Paddle* opponent;
};

#endif //DEBUG_SYSTEM_H
