#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "world.h"
#include "player.h"

// ... otras cabeceras necesarias

int main() {
    // Inicializar GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Crear ventana
    GLFWwindow* window = glfwCreateWindow(800, 600, "Minecraft Clone", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Inicializar GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Crear el mundo y el jugador
    World world;
    Player player;

    // Bucle principal del juego
    while (!glfwWindowShouldClose(window)) {
        // Procesar eventos
        glfwPollEvents();

        // Actualizar el juego
        world.update();
        player.update();

        // Renderizar
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // ... código de renderizado (llamar a las funciones de renderizado de world y player)

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}