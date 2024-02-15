#include <iostream>
#include <SDL2/SDL.h>

#include "opponent.h"
#include "paddle.h"
#include "screen.h"

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

    const auto* player_position = new Position(SCREEN_WIDTH / 4, SCREEN_HEIGHT);
    const auto* opponent_position = new Position(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 16);
    auto *player = new Paddle(renderer);
    auto *opponent = new Opponent(renderer);

    player->move(player_position);
    opponent->move(opponent_position);

    int velocityX = 0;

    SDL_Event e;
    bool quit = false;
    while (quit == false) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_a:
                        std::cout << player->getPosition()->getX() << std::endl;
                        player->moveX(-10);
                        opponent->moveX(-10);
                        break;
                    case SDLK_e:
                        std::cout << player->getPosition()->getX() << std::endl;
                        player->moveX(10);
                        opponent->moveX(10);
                        break;

                    case SDLK_h:
                        velocityX += 10;
                        break;
                    case SDLK_n:
                        velocityX -= 10;
                        break;
                    default:
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        player->render();
        opponent->render();

        // Render ball
        constexpr int ballHeight = SCREEN_HEIGHT / 32;
        constexpr int ballWidth = SCREEN_WIDTH / 32;

        SDL_Rect ball = {(SCREEN_WIDTH / 2) + velocityX, SCREEN_HEIGHT / 2, ballWidth, ballHeight};
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &ball);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
