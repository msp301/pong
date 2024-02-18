#include "opponent.h"

void Opponent::performMove(const int offset, const Position* ballPosition, Position* previousBallPosition) {
    int paddleCentre = position->X + (width / 2);
    if (ballPosition->X > paddleCentre) return moveX(offset);
    if (ballPosition->X < paddleCentre) return moveX(-offset);
}
