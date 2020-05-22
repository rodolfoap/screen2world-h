cmake_minimum_required(VERSION 3.10)
project(transform_h)

# Force C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Binary calculate_h will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

find_package(OpenCV REQUIRED)

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

add_executable(calculate_h calculate_h.cpp)
add_executable(transform transform.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(calculate_h ${OpenCV_LIBS} stdc++fs)
target_link_libraries(transform ${OpenCV_LIBS} stdc++fs)
