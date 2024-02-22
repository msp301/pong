#ifndef PONG_ENTITY_H
#define PONG_ENTITY_H

class Entity {
    inline static int entityCount = 0;
    int id_;

public:
    explicit Entity();

    decltype(id_)& id() { return id_; };
};

#endif //PONG_ENTITY_H
