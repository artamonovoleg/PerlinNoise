cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME PerlinNoise)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(MY_DIRECTORIES
    PPM/
    )
include_directories(${MY_DIRECTORIES})
set(SOURCE_FILES
        main.cpp
        PerlinNoise.cpp
        PPM/PPM.cpp
      )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
link_directories(${PROJECT_NAME} PRIVATE ${MY_DIRECTORIES})