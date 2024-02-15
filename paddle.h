#ifndef PADDLE_H
#define PADDLE_H

#include <SDL_render.h>

#include "position.h"
#include "screen.h"

class Paddle {
static constexpr int height = SCREEN_HEIGHT / 16;
static constexpr int width = SCREEN_WIDTH / 4;
Uint64 rgbaColour = 0xFF0000FF;

public:
    explicit Paddle(SDL_Renderer* renderer);

    [[nodiscard]] Position* getPosition() const;

    void move(const Position* position);
    void move(int x, int y);
    void moveX(int offset);

    void render() const;
protected:
    void setColour(Uint64 colour);
private:
    Position* position;
    SDL_Renderer* renderer;
};

#endif //PADDLE_H
