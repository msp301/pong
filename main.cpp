#include <iostream>
#include <SDL2/SDL.h>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

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

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Failed to create renderer! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    int offset = 0;

    SDL_Event e;
    bool quit = false;
    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        const Uint8* keyState = SDL_GetKeyboardState(nullptr);
        if (keyState[SDL_SCANCODE_A]) {
            offset -= 2;
        }
        if (keyState[SDL_SCANCODE_E]) {
            offset += 2;
        }

        const int pos_x = (SCREEN_WIDTH + offset) / 4;

        constexpr int height = SCREEN_HEIGHT / 16;
        constexpr int width = SCREEN_WIDTH / 4;

        // Render player
        SDL_Rect player = {pos_x, SCREEN_HEIGHT - height, width, height};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &player);

        // Render opponent
        SDL_Rect opponent = {pos_x, height, width, height};
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &opponent);

        // Render ball
        constexpr int ballHeight = SCREEN_HEIGHT / 32;
        constexpr int ballWidth = SCREEN_WIDTH / 32;

        SDL_Rect ball = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ballWidth, ballHeight};
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &ball);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
