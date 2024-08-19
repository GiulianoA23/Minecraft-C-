#include <SDL2/SDL.h>
#include <SFML/Graphics.hpp>
#include "Sandbox.h"

int main(int argc, char** argv) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error inicializando SDL: %s", SDL_GetError());
        return 1;
    }

    // Crear ventana
    SDL_Window* window = SDL_CreateWindow("Sandbox", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error creando ventana: %s", SDL_GetError());
        return 1;
    }

    // Crear renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error creando renderizador: %s", SDL_GetError());
        return 1;
    }

    // Inicializar Sandbox
    Sandbox sandbox;
    sandbox.init(renderer);

    // Bucle principal
    bool running = true;
    while (running) {
        // Procesar eventos
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Actualizar Sandbox
        sandbox.update();

        // Dibujar Sandbox
        sandbox.draw(renderer);

        // Actualizar pantalla
        SDL_RenderPresent(renderer);
        SDL_Delay(16); // 60 FPS
    }

    // Liberar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}