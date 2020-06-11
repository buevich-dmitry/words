cmake_minimum_required(VERSION 3.0)
project(words)

set(CMAKE_CXX_STANDARD 17)

add_library(text_processing text_processing.h text_processing.cpp)

add_executable(main main.cpp)
add_executable(test_text_processing test.cpp)

target_link_libraries(main text_processing)
target_link_libraries(test_text_processing text_processing)

# Boost
find_package(Boost COMPONENTS program_options filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(text_processing ${Boost_LIBRARIES})

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(test_text_processing ${GTEST_LIBRARIES} pthread)