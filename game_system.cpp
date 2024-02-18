#include "game_system.h"

#include <iostream>

#include "ball.h"

void updateScore(const Ball* ball, Paddle* player, Paddle* opponent) {
    if (ball->boundaryYCollision == player->defendingBoundary) {
        opponent->gameScore++;
        std::cout << opponent->name << ": " << opponent->gameScore << std::endl;
    } else if (ball->boundaryYCollision == opponent->defendingBoundary) {
        player->gameScore++;
        std::cout << player->name << ": " << player->gameScore << std::endl;
    }
}
