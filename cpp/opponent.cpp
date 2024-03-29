#include <random>

#include "opponent.h"

void Opponent::performMove(const int offset, const Position* ballPosition, const Position* previousBallPosition) {
    if (previousBallPosition == nullptr) return;
    if (ballPosition->Y > previousBallPosition->Y) return;

    if (ballPosition->Y <= position->Y) {
        if (position->X + width >= SCREEN_WIDTH / 2) return moveX(-offset);
        if (position->X - width <= SCREEN_WIDTH / 2) return moveX(offset);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, offset);
    const int chosenOffset = distrib(gen);

    const int paddleCentre = position->X + (width / 2);
    if (ballPosition->X > paddleCentre) return moveX(chosenOffset);
    if (ballPosition->X < paddleCentre) return moveX(-chosenOffset);
}
