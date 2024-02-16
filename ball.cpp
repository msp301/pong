#include "ball.h"

#include <SDL_render.h>

Ball::Ball(SDL_Renderer *renderer) {
    this->renderer = renderer;
    position = new Position(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Ball::move() {
    int x = position->getX();
    int y = position->getY();

    if (x <= 0)                   velocityX = velocity;
    if (x + width > SCREEN_WIDTH) velocityX = -velocity;

    if (y <= 0)                     velocityY = velocity;
    if (y + height > SCREEN_HEIGHT) velocityY = -velocity;

    position = new Position(x + velocityX, y + velocityY);
}

void Ball::render() const {
    const SDL_Rect ball = {position->getX(), position->getY(), width, height};
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &ball);
}
