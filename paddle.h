#ifndef PADDLE_H
#define PADDLE_H

#include <SDL_render.h>
#include <string>

#include "collider.h"
#include "collision_box.h"
#include "position.h"
#include "screen.h"

class Paddle {
Uint64 rgbaColour = 0xFF0000FF;

public:
    explicit Paddle(SDL_Renderer* renderer);

    SDL_Rect* box;
    CollisionBox* collisionBox;

    std::string name = "Player";
    int gameScore = 0;
    int defendingBoundary = SCREEN_HEIGHT;

    [[nodiscard]] Position* getPosition() const;

    void move(const Position* position);
    void move(int x, int y);
    void moveX(int offset);

    void render() const;
protected:
    void setColour(Uint64 colour);

void setName(const std::string &name);

void setDefendingBoundary(int boundary);

static constexpr int height = SCREEN_HEIGHT / 16;
    static constexpr int width = SCREEN_WIDTH / 4;
    Position* position;
private:
    SDL_Renderer* renderer;
};

#endif //PADDLE_H
