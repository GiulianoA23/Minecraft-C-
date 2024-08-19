#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

// Función para inicializar GLFW y crear una ventana.
GLFWwindow* initGLFW(int width, int height, const char* title) {
    if (!glfwInit()) {
        std::cerr << "Error inicializando GLFW" << std::endl;
        return nullptr;
    }

    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "Error creando la ventana GLFW" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = true;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Error inicializando GLEW" << std::endl;
        return nullptr;
    }

    glEnable(GL_DEPTH_TEST);
    return window;
}

// Función para definir un cubo.
std::vector<float> createCube(float x, float y, float z) {
    return {
        x, y, z,  1.0f, 1.0f, 1.0f, // Vertice 1
        x+1, y, z,  1.0f, 1.0f, 1.0f, // Vertice 2
        x+1, y+1, z,  1.0f, 1.0f, 1.0f, // Vertice 3
        x, y+1, z,  1.0f, 1.0f, 1.0f, // Vertice 4
        // Otros vértices del cubo...
    };
}

// Función para inicializar los datos de vóxeles.
std::vector<float> initWorld() {
    std::vector<float> world;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                auto cube = createCube(i, j, k);
                world.insert(world.end(), cube.begin(), cube.end());
            }
        }
    }
    return world;
}

// Función principal.
int main() {
    GLFWwindow* window = initGLFW(800, 600, "Sandbox Básico en C++");
    if (!window) return -1;

    std::vector<float> world = initWorld();

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, world.size() * sizeof(float), &world[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Renderizar aquí el mundo de vóxeles.

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
