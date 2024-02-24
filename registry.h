#ifndef REGISTRY_H
#define REGISTRY_H

#include <map>
#include <typeinfo>
#include <string>
#include <vector>

template<typename T>
std::map<std::string, std::vector<T*>> componentsRegistry = {};

template<typename T>
std::map<int, std::map<std::string, T*>> entitiesRegistry;

template<typename T>
void registerCompoment(T *component) {
    componentsRegistry<T>[typeid(component).name()].push_back(component);
}

template<typename T>
void registerEntityComponent(int id, T *component) {
    entitiesRegistry<T>[id][typeid(component).name()] = component;
}

template<typename T>
T* getEntityComponent(int id) {
    return entitiesRegistry<T>[id][typeid(T).name()];
}



#endif //REGISTRY_H
