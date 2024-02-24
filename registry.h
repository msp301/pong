#ifndef REGISTRY_H
#define REGISTRY_H

#include <map>
#include <typeinfo>
#include <string>
#include <vector>

template<typename T>
static std::map<const char*, T*> data {};

template<typename T>
static std::map<const char*, std::vector<T*>> componentsRegistry {};

template<typename T>
static std::map<int, std::map<const char*, T*>> entitiesRegistry {};

template<typename T>
void registerComponent(T *component) {
    data<T>[typeid(component).name()] = component;
    componentsRegistry<T>[typeid(component).name()].push_back(component);
}

template<typename T>
void registerEntityComponent(int id, T *component) {
    entitiesRegistry<T>[id][typeid(component).name()] = component;
}

template<typename T>
T* getEntityComponent(int id) {
    std::map<const char*, T*> test = entitiesRegistry<std::map<const char*, T*>>[id];
    return entitiesRegistry<T>[id][typeid(T).name()];
}

#endif //REGISTRY_H
