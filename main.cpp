#include <iostream>
#include <vector>
#include <string>

// Estructura para representar un bloque en el mundo
struct Block {
    int x, y, z;
    char tipo; // 'A' para aire, 'T' para tierra, 'P' para piedra
};

// Clase para representar el mundo
class Mundo {
public:
    std::vector<std::vector<std::vector<Block>>> bloques;
    int ancho, alto, profundidad;

    Mundo(int ancho, int alto, int profundidad) : ancho(ancho), alto(alto), profundidad(profundidad) {
        bloques.resize(ancho, std::vector<std::vector<Block>>(alto, std::vector<Block>(profundidad)));
    }

    void generarMundo() {
        for (int x = 0; x < ancho; x++) {
            for (int y = 0; y < alto; y++) {
                for (int z = 0; z < profundidad; z++) {
                    if (y == 0) {
                        bloques[x][y][z].tipo = 'T'; // Tierra en la base
                    } else if (y == alto - 1) {
                        bloques[x][y][z].tipo = 'P'; // Piedra en la cima
                    } else {
                        bloques[x][y][z].tipo = 'A'; // Aire en el medio
                    }
                }
            }
        }
    }

    void imprimirMundo() {
        for (int y = 0; y < alto; y++) {
            for (int x = 0; x < ancho; x++) {
                for (int z = 0; z < profundidad; z++) {
                    std::cout << bloques[x][y][z].tipo << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Mundo mundo(10, 10, 10);
    mundo.generarMundo();
    mundo.imprimirMundo();

    return 0;
}
