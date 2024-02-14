#include <iostream>
#include <SDL2/SDL.h>

constexpr int SCREEN_HEIGHT = 640;
constexpr int SCREEN_WIDTH = 480;

int main(int argv, char **args) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Failed to create window! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;
    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
