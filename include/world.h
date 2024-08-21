#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <glm/glm.hpp>

enum class BlockType {
    Air,
    Grass,
    Stone,
    // ... otros tipos de bloques
};

class World {
public:
    World();
    void update();
    void render();

private:
    static const int WORLD_SIZE = 128; // Ajusta el tamaño del mundo según sea necesario
    BlockType blocks[WORLD_SIZE][WORLD_SIZE][WORLD_SIZE];

    // Función para generar el terreno (implementación en world.cpp)
    void generateTerrain();
};

#endif