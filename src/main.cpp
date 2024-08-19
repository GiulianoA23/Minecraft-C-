#include <iostream>
#include "world.h"

int main() {
    World world;
    world.generate();
    world.render();

    std::cout << "Game initialized!" << std::endl;
    return 0;
}
