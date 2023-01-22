project(rsa)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.15)
#for gtest:
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main main.cpp Calc.cpp )
target_link_libraries(main ${GTEST_BOTH_LIBRARIES})