#include "paddle.h"

Paddle::Paddle(SDL_Renderer *renderer) {
    this->renderer = renderer;
    position = Position{0, 0};
}

void Paddle::move(const Position position) {
    move(position.X, position.Y);
}

void Paddle::move(const int x, const int y) {
    int coord_x = (x + width > SCREEN_WIDTH) ? SCREEN_WIDTH - width : x;
    coord_x = (x - width < 0) ? 0 : coord_x;

    int coord_y = (y + height > SCREEN_HEIGHT) ? SCREEN_HEIGHT - height : y;
    coord_y = (y - height < 0) ? 0 : coord_y;

    position = Position{coord_x, coord_y};
}

void Paddle::render() const {
    const SDL_Rect paddle = { position.X, position.Y, width, height};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &paddle);
}
