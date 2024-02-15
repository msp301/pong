#ifndef OPPONENT_H
#define OPPONENT_H
#include "paddle.h"

class Opponent : public Paddle {
public:
    explicit Opponent(SDL_Renderer *renderer) : Paddle(renderer) {
        setColour(0x0000FFFF);
    }
protected:
    static constexpr Uint64 rgbaColour = 0x0000FFFF;
};

#endif //OPPONENT_H
