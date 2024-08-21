#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>

class Player {
public:
    Player();
    void update();
    void render();

private:
    glm::vec3 position;
    glm::vec3 velocity;
    float speed;

    // Referencia a la ventana GLFW (para obtener las entradas del teclado)
    GLFWwindow* window;
};

#endif