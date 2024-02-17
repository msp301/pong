#ifndef BALL_H
#define BALL_H

#include <SDL_render.h>

#include "collider.h"
#include "collision_box.h"
#include "position.h"
#include "screen.h"

class Ball final {
public:
    explicit Ball(SDL_Renderer* renderer);

    SDL_Rect* box;
    CollisionBox* collisionBox;

    void move(const std::vector<CollisionBox*> &colliders);
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