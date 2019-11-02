cmake_minimum_required(VERSION 3.5)

project(Potato)

enable_testing()

add_subdirectory(googletest)

file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)

add_library(Potato STATIC ${SRC})

add_subdirectory(spdlog)
target_link_libraries(Potato spdlog::spdlog)

add_subdirectory(test)

add_executable(potato "src/main.cpp")
target_link_libraries(potato Potato)