cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SandboxGame)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Configurar directorios de búsqueda para las dependencias
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/deps") # Directorio donde se instalarán las dependencias

# Encontrar las bibliotecas necesarias
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(GLM REQUIRED)

# Archivos fuente
set(SOURCES
    main.cpp
)

# Crear el ejecutable
add_executable(SandboxGame ${SOURCES})

# Incluir directorios
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})

# Enlazar las bibliotecas necesarias
target_link_libraries(SandboxGame
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
)
