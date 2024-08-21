#include "player.h"
#include <GLFW/glfw3.h>

Player::Player() {
    // Inicializar las propiedades del jugador
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    velocity = glm::vec3(0.0f);
    speed = 5.0f;
}

void Player::update() {
    // Obtener las entradas del teclado
    float moveForward = 0.0f;
    float moveRight = 0.0f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        moveForward = 1.0f;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        moveForward = -1.0f;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        moveRight = -1.0f;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        moveRight = 1.0f;

    // Calcular el nuevo movimiento
    glm::vec3 newPosition = position + glm::vec3(moveRight, 0.0f, moveForward) * speed * deltaTime;

    // Comprobar colisiones (implementar más adelante)
    // ...

    // Actualizar la posición
    position = newPosition;
}

void Player::render() {
    // Renderizar el modelo del jugador (implementar más adelante)
    // ...
}