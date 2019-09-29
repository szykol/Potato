cmake_minimum_required(VERSION 3.5)

project(Potato)

file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)

add_library(Potato STATIC ${SRC})

add_executable(potato "src/main.cpp")
target_link_libraries(potato Potato)