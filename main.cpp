#include <iostream>
#include <SDL2/SDL.h>

#include "ball.h"
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

    int frames = 0;

    const auto* player_position = new Position(SCREEN_WIDTH / 4, SCREEN_HEIGHT);
    const auto* opponent_position = new Position(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 16);
    auto *player = new Paddle(renderer);
    auto *opponent = new Opponent(renderer);
    auto *ball = new Ball(renderer);

    player->move(player_position);
    opponent->move(opponent_position);

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
                    default:
                        break;
                }
            }
        }

        float avgFPS = frames / (SDL_GetTicks() / 1000.f);
        if (avgFPS > 2000000) avgFPS = 0;
        std::cout << "Average Frames Per Second " << avgFPS << std::endl;

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        player->render();
        opponent->render();

        ball->move();
        ball->render();

        SDL_RenderPresent(renderer);
        frames++;
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
