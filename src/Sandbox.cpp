#include "Sandbox.h"

Sandbox::Sandbox() {}

Sandbox::~Sandbox() {}

void Sandbox::init(SDL_Renderer* renderer) {
    block.setSize(sf::Vector2f(32, 32));
    block.setFillColor(sf::Color::Red);
}

void Sandbox::update() {
    // Actualizar bloque
    block.setPosition(100, 100);
}

void Sandbox::draw(SDL_Renderer* renderer) {
    // Dibujar bloque
    SDL_RenderCopy(renderer, NULL, NULL, block.getGlobalBounds().getCenter());
}