#ifndef PONG_ENTITY_H
#define PONG_ENTITY_H
#include "registry.h"

class Entity {
    inline static int entityCount = 0;
    int id_;

public:
    explicit Entity();

    decltype(id_)& id() { return id_; };

    template<typename T>
    void set(T *component) {
        registerEntityComponent(id_, component);
    }

    template<typename T>
    T* get() {
        return getEntityComponent<T>(id_);
    }
};

#endif //PONG_ENTITY_H
