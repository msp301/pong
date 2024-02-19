cmake_minimum_required(VERSION 3.27.8)
project(pong)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

add_executable(pong main.cpp
        paddle.cpp
        paddle.h
        position.h
        screen.h
        opponent.cpp
        opponent.h
        position.cpp
        ball.cpp
        ball.h
        collider.h
        collision_box.h
        collision_box.cpp
        collision_system.h
        position.cpp
        game_system.h
        game_system.cpp
        controller.h)
target_link_libraries(pong ${SDL2_LIBRARIES})
