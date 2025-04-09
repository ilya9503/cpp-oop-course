cmake_minimum_required(VERSION 3.10)

project(2_6_Methods_Outside_Class)

set(CMAKE_CXX_STANDARD 17)

# Если заголовки находятся в той же папке, include_directories не обязателен, но можно добавить:
include_directories(${CMAKE_SOURCE_DIR})

# Указываем исходники прямо (путь не нужен — они рядом с CMakeLists.txt)
add_executable(2_6_Methods_Outside_Class
    pointnd_main.cpp
    pointnd_implementation.cpp
)