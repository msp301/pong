#include "debug_system.h"

#include <iostream>

DebugSystem::DebugSystem(Ball *ball, Paddle *player, Paddle *opponent) : ball(ball), player(player), opponent(opponent) {
}

void DebugSystem::printInfo() {
    std::cout << "Ball position:" << ball->position->X << " " << ball->position->Y;
}
