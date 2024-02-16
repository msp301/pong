#ifndef BALL_H
#define BALL_H

#include <SDL_render.h>

#include "position.h"
#include "screen.h"

class Ball {
public:
    explicit Ball(SDL_Renderer* renderer);

    void move();
    void render() const;

private:
    static constexpr int height = SCREEN_HEIGHT / 32;
    static constexpr int width = SCREEN_WIDTH / 32;
    static constexpr int velocity = 10;

    Position* position;
    SDL_Renderer* renderer;
    int velocityX = velocity;
    int velocityY = velocity;
};

#endif //BALL_H
