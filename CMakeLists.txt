cmake_minimum_required(VERSION 3.5)

project(Potato)
set (CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(googletest)

file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("debug mode")
    add_definitions(-DPOTATO_DEBUG)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

add_library(Potato STATIC ${SRC})
add_executable(potato "src/main.cpp")

add_subdirectory(spdlog)
target_link_libraries(Potato spdlog::spdlog)

add_subdirectory(test)

target_link_libraries(potato Potato)
