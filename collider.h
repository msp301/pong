#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL_rect.h>
#include <vector>

class Collider {
public:
    virtual ~Collider() = default;

    [[nodiscard]] virtual SDL_Rect* getCollisionBox() const = 0;

    [[nodiscard]] bool isColliding(const std::vector<Collider*>& colliders) const {
        SDL_Rect* thisCollisionBox = this->getCollisionBox();
        for (auto collider: colliders) {
            if (SDL_HasIntersection(thisCollisionBox, collider->getCollisionBox()) == SDL_TRUE) {
                return true;
            }
        }
        return false;
    }
};

#endif //COLLIDER_H
