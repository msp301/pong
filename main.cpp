#include <iostream>
#include <SDL2/SDL.h>

int main(int argv, char** args) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    std::cout << "Hello, World!" << std::endl;

    while (1) {
    }

    return 0;
}
