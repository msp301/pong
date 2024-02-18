#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

#include <iostream>
#include <ostream>

#include "paddle.h"
#include "position.h"

inline void updateScore(const Position* ballPosition, const std::vector<Paddle*> &players) {
    for (const auto player: players) {
        if ((player->defendingBoundary <= 0 && ballPosition->Y <= player->defendingBoundary) || ballPosition->Y >= player->defendingBoundary) {
            player->gameScore++;
            std::cout << player->name << ": " << player->gameScore << std::endl;
        }
    }
}

#endif //GAME_SYSTEM_H
