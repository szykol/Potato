cmake_minimum_required(VERSION 3.5)

file(GLOB TEST_SRC
    "*.h"
    "*.cpp"
)

add_executable(Test ${TEST_SRC})

target_link_libraries(Test PUBLIC gtest_main Potato)

add_test(Name Test COMMAND Test)