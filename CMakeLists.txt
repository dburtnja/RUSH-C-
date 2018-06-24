cmake_minimum_required(VERSION 3.9)
project(RUSH)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(RUSH
        Asteroid.cpp
        Asteroid.hpp
        Board.cpp
        Board.hpp
        Bullet.cpp
        Bullet.hpp
        Enemy.cpp
        Enemy.hpp
        main.cpp
        Player.cpp
        Player.hpp
        Space_object.cpp
        Space_object.hpp
        Window.cpp
        Window.hpp Asteroid.cpp Asteroid.hpp Boss.cpp Boss.hpp)
