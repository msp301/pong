#include "debug_system.h"

#include <iostream>

DebugSystem::DebugSystem(Ball *ball, Paddle *player, Paddle *opponent) : ball(ball), player(player), opponent(opponent) {
}

void DebugSystem::toggle() {
    enabled = !enabled;
}

void DebugSystem::printInfo() const {
    if (!enabled) return;

    std::cout << "Ball position:" << ball->position->toString() << std::endl;
    std::cout << player->name << " position:" << player->getPosition()->toString() << std::endl;
    std::cout << opponent->name << " position:" << opponent->getPosition()->toString() << std::endl;
}

