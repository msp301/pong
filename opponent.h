#ifndef OPPONENT_H
#define OPPONENT_H
#include "paddle.h"

class Opponent final : public Paddle {
public:
    explicit Opponent(SDL_Renderer *renderer) : Paddle(renderer) {
        setColour(0x0000FFFF);
    }

    void performMove(int offset, const Position* ballPosition, const Position* previousBallPosition);
protected:
    static constexpr Uint64 rgbaColour = 0x0000FFFF;
};

#endif //OPPONENT_H
