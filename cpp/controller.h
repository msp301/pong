#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL_joystick.h>

inline void destroyController(SDL_GameController* controller) {
    if (controller != nullptr) {
        SDL_GameControllerClose(controller);
    }
}

#endif //CONTROLLER_H
