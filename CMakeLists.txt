cmake_minimum_required(VERSION 3.5)

project(Potato)
set (CMAKE_CXX_STANDARD 17)

enable_testing()

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("debug mode")
    add_definitions(-DPOTATO_DEBUG)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)

add_subdirectory(googletest)
add_subdirectory(spdlog)
add_subdirectory(test)

file(GLOB POTATO_SRC
    "src/*.h"
    "src/*.cpp"
)
list(REMOVE_ITEM POTATO_SRC "src/main.cpp")
add_executable(potato "src/main.cpp")
add_library(PotatoLib STATIC ${POTATO_SRC})

target_link_libraries(PotatoLib spdlog::spdlog)
target_link_libraries(potato PotatoLib)
