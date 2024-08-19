cmake_minimum_required(VERSION 3.10)
project(Sandbox)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

find_package(SFML 2.5.1 COMPONENTS graphics window REQUIRED)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})