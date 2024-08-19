cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SandboxGame)

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Archivos fuente
set(SOURCES src/main.cpp)

# Incluir directorios (si tienes archivos de cabecera)
include_directories(include)

# Crear el ejecutable
add_executable(SandboxGame ${SOURCES})

# Enlazar bibliotecas necesarias (GLFW, GLEW, OpenGL)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)

target_link_libraries(SandboxGame OpenGL::GL GLEW::GLEW GLFW::GLFW)
