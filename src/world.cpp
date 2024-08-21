#include "world.h"
#include <noise/noise.h>

World::World() {
    // Generar el mundo utilizando ruido Perlin
    noise::module::Perlin perlin;
    perlin.SetFrequency(0.05);
    perlin.SetOctaveCount(4);
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int z = 0; z < WORLD_SIZE; z++) {
            float y = perlin.GetValue(x, z) * 32 + 64;
            for (int y = 0; y < y; y++) {
                // Colocar un bloque de tierra
                blocks[x][y][z] = BlockType::Grass;
            }
        }
    }
}

void World::update() {
    // Actualizar el mundo (por ejemplo, si hay bloques que se rompen)
    // ...
}

void World::render() {
    // Renderizar los bloques del mundo
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int y = 0; y < WORLD_SIZE; y++) {
            for (int z = 0; z < WORLD_SIZE; z++) {
                if (blocks[x][y][z] != BlockType::Air) {
                    // Renderizar el bloque
                    // ...
                }
            }
        }
    }
}