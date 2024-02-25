#include "paddle.h"

Paddle::Paddle(SDL_Renderer *renderer) {
    this->renderer = renderer;
    position = new Position(0, 0);
    box = new SDL_Rect {position->X, position->Y, width, height};
    collisionBox = new CollisionBox(width, height, position);
}

Position* Paddle::getPosition() const {
    return position;
}

void Paddle::move(const Position* position) {
    move(position->X, position->Y);
}

void Paddle::move(const int x, const int y) {
    int coord_x = (x + width > SCREEN_WIDTH) ? SCREEN_WIDTH - width : x;
    coord_x = (coord_x < 0) ? 0 : coord_x;

    int coord_y = (y + height > SCREEN_HEIGHT) ? SCREEN_HEIGHT - height : y;
    coord_y = (coord_y < 0) ? 0 : coord_y;

    box = new SDL_Rect {coord_x, coord_y, width, height};
    position->set(coord_x, coord_y);
}

void Paddle::moveX(const int offset) {
    move(position->X + offset, position->Y);
}

void Paddle::render() const {
    const Uint8 red = (rgbaColour & 0xFF000000) >> 24;
    const Uint8 green = (rgbaColour & 0x00FF0000) >> 16;
    const Uint8 blue = (rgbaColour & 0x0000FF00) >> 8;
    const Uint8 alpha = rgbaColour & 0x000000FF;

    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    SDL_RenderFillRect(renderer, box);
}

void Paddle::setColour(const Uint64 colour) {
    rgbaColour = colour;
}

void Paddle::setName(const std::string &name) {
    this->name = name;
}

void Paddle::setDefendingBoundary(const int boundary) {
    defendingBoundary = boundary;
}