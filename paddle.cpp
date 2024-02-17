#include "paddle.h"

Paddle::Paddle(SDL_Renderer *renderer) {
    this->renderer = renderer;
    position = new Position(0, 0);
}

SDL_Rect* Paddle::getCollisionBox() const {
    SDL_Rect paddle = { position->getX(), position->getY(), width, height};
    return &paddle;
}

Position* Paddle::getPosition() const {
    return position;
}

void Paddle::move(const Position* position) {
    move(position->getX(), position->getY());
}

void Paddle::move(const int x, const int y) {
    int coord_x = (x + width > SCREEN_WIDTH) ? SCREEN_WIDTH - width : x;
    coord_x = (coord_x < 0) ? 0 : coord_x;

    int coord_y = (y + height > SCREEN_HEIGHT) ? SCREEN_HEIGHT - height : y;
    coord_y = (coord_y < 0) ? 0 : coord_y;

    position = new Position(coord_x, coord_y);
}

void Paddle::moveX(const int offset) {
    move(position->getX() + offset, position->getY());
}

void Paddle::render() const {
    const Uint8 red = (rgbaColour & 0xFF000000) >> 24;
    const Uint8 green = (rgbaColour & 0x00FF0000) >> 16;
    const Uint8 blue = (rgbaColour & 0x0000FF00) >> 8;
    const Uint8 alpha = rgbaColour & 0x000000FF;

    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    SDL_RenderFillRect(renderer, getCollisionBox());
}

void Paddle::setColour(const Uint64 colour) {
    rgbaColour = colour;
}
