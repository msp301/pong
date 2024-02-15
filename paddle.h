#ifndef PADDLE_H
#define PADDLE_H

#include <SDL_render.h>

#include "position.h"
#include "screen.h"

class Paddle {
static constexpr int height = SCREEN_HEIGHT / 16;
static constexpr int width = SCREEN_WIDTH / 4;

public:
    explicit Paddle(SDL_Renderer* renderer);

    void move(Position position);
    void move(int x, int y);

    void render() const;
private:
    Position position{};
    SDL_Renderer* renderer;
};

#endif //PADDLE_H
