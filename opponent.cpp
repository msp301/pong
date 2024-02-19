#include "opponent.h"

void Opponent::performMove(const int offset, const Position* ballPosition, const Position* previousBallPosition) {
    if (previousBallPosition == nullptr) return;
    if (ballPosition->Y > previousBallPosition->Y) return;

    const int paddleCentre = position->X + (width / 2);
    if (ballPosition->X > paddleCentre) return moveX(offset);
    if (ballPosition->X < paddleCentre) return moveX(-offset);
}
