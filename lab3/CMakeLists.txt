cmake_minimum_required(VERSION 3.10)
project(OOP_LAB3)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

add_executable(main main.cpp penta.cpp hexa.cpp octa.cpp array.cpp)

add_executable(tests tests.cpp penta.cpp hexa.cpp octa.cpp array.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)