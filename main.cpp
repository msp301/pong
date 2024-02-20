#include <iostream>
#include <SDL2/SDL.h>

#include "ball.h"
#include "controller.h"
#include "game_system.h"
#include "opponent.h"
#include "paddle.h"
#include "screen.h"

constexpr int FPS = 60;
constexpr int TICKS_PER_FRAME = 1000 / FPS;

int main(int argv, char **args) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    const SDL_Scancode leftScanCode = SDL_GetScancodeFromKey(SDLK_a);
    const SDL_Scancode rightScanCode = SDL_GetScancodeFromKey(SDLK_e);

    SDL_GameController* controller = nullptr;

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

    const auto *player_position = new Position(SCREEN_WIDTH / 4, SCREEN_HEIGHT);
    const auto *opponent_position = new Position(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 16);
    auto *player = new Paddle(renderer);
    auto *opponent = new Opponent(renderer);
    auto *ball = new Ball(renderer);

    player->move(player_position);
    opponent->move(opponent_position);

    SDL_Event e;
    bool quit = false;
    while (quit == false) {
        const Uint32 startTicks = SDL_GetTicks();

        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_JOYAXISMOTION:
                    if (controller && e.jaxis.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller))) {
                        constexpr int JOYSTICK_DEAD_ZONE = 8000;
                        if (e.jaxis.value < -JOYSTICK_DEAD_ZONE) {
                            player->moveX(-5);
                        } else if (e.jaxis.value > JOYSTICK_DEAD_ZONE) {
                            player->moveX(5);
                        }
                    }
                    break;
                case SDL_CONTROLLERDEVICEADDED:
                    if (!controller) {
                        controller = SDL_GameControllerOpen(e.cdevice.which);
                        std::cout << "Controller added: " << SDL_GameControllerName(controller) << std::endl;
                    }
                    break;
                case SDL_CONTROLLERDEVICEREMOVED:
                    if (controller && e.cdevice.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller))) {
                        const char* controllerName = SDL_GameControllerName(controller);
                        destroyController(controller);
                        controller = nullptr;
                        std::cout << "Controller removed: " << controllerName << std::endl;
                    }
                    break;
                default:
                    break;
            }
        }

        if (controller) {
            if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)) {
                player->moveX(-10);
            } else if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)) {
                player->moveX(10);
            }
        }

        const Uint8* keyState = SDL_GetKeyboardState(nullptr);
        if (keyState[leftScanCode]) player->moveX(-10);
        if (keyState[rightScanCode]) player->moveX(10);

        float avgFPS = frames / (SDL_GetTicks() / 1000.f);
        if (avgFPS > 2000000) avgFPS = 0;
        // std::cout << "Average Frames Per Second " << avgFPS << std::endl;

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        player->render();

        opponent->performMove(10, ball->position, ball->previousPosition);
        opponent->render();

        std::vector collisionBoxes{player->collisionBox, opponent->collisionBox};
        ball->move(collisionBoxes);
        ball->render();

        SDL_RenderPresent(renderer);
        frames++;

        updateScore(ball, player, opponent);
        ball->resetCollisions();

        if (const Uint32 endTicks = SDL_GetTicks(); endTicks - startTicks < TICKS_PER_FRAME) {
            SDL_Delay(TICKS_PER_FRAME - (endTicks - startTicks));
        }
    }

    destroyController(controller);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
