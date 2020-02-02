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

file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(potato "src/main.cpp")
add_library(PotatoLib STATIC ${SRC})
target_link_libraries(PotatoLib spdlog::spdlog)
target_include_directories(PotatoLib PUBLIC asio/asio/include)

target_link_libraries(potato PotatoLib)
