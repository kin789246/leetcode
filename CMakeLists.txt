cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)

include(CTest)
enable_testing()
set(SRC_FILES
   leetcode-133_Clone_Graph.cpp
   )
add_executable(${PROJECT_NAME} ${SRC_FILES})

set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -pedantic-errors")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
