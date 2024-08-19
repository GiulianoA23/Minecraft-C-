cmake_minimum_required(VERSION 3.10)
project(SandboxGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

add_executable(${PROJECT_NAME} game.cpp)

target_link_libraries(${PROJECT_NAME} SFML::Graphics SFML::Window SFML::System)