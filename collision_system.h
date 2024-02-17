#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <SDL_rect.h>
#include <vector>

#include "collision_box.h"

inline bool isColliding(const CollisionBox* thisCollisionBox, const std::vector<CollisionBox*>& colliders) {
    const SDL_Rect thisRect = {thisCollisionBox->position->X, thisCollisionBox->position->Y, thisCollisionBox->width, thisCollisionBox->height};
    for (const auto collider: colliders) {
        SDL_Rect colliderRect = {collider->position->X, collider->position->Y, collider->width, collider->height};
        if (SDL_HasIntersection(&thisRect, &colliderRect) == SDL_TRUE) {
            return true;
        }
    }
    return false;
}

#endif //COLLISION_SYSTEM_H
