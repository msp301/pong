#include "ball.h"

#include <SDL_render.h>
#include <vector>

#include "collision_system.h"

Ball::Ball(SDL_Renderer *renderer) {
    this->renderer = renderer;
    position = new Position(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    box = new SDL_Rect {position->X, position->Y, width, height};
    collisionBox = new CollisionBox(width, height, position);
}

void Ball::move(const std::vector<CollisionBox*>& colliders) {
    int x = position->X;
    int y = position->Y;

    if (x <= 0)                   velocityX = velocity;
    if (x + width > SCREEN_WIDTH) velocityX = -velocity;
    if (isColliding(this->collisionBox, colliders)) {
        if (previousPosition && previousPosition->X > position->X) velocityX = velocity;
        if (previousPosition && previousPosition->X < position->X) velocityX = -velocity;
    }

    if (y <= 0) {
        velocityY = velocity;
        boundaryYCollision = 0;
    }
    if (y + height > SCREEN_HEIGHT) {
        velocityY = -velocity;
        boundaryYCollision = SCREEN_HEIGHT;
    }
    if (isColliding(this->collisionBox, colliders)) {
        if (previousPosition && previousPosition->Y > position->Y) velocityY = velocity;
        if (previousPosition && previousPosition->Y < position->Y) velocityY = -velocity;
    }

    box = new SDL_Rect {x + velocityX, y + velocityY, width, height};
    position->set(x + velocityX, y + velocityY);
    previousPosition = new Position(x, y);
}

void Ball::render() const {
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, box);
}

void Ball::resetCollisions() {
    boundaryYCollision = -1;
}