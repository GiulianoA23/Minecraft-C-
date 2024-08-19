// game.cpp
#include <SFML/Graphics.hpp>
#include <iostream>

// Constants
const int WIDTH = 800;
const int HEIGHT = 600;
const int BLOCK_SIZE = 32;

// Block class
class Block {
public:
    int x, y;
    sf::RectangleShape shape;

    Block(int x, int y) : x(x), y(y) {
        shape.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
        shape.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
        shape.setFillColor(sf::Color::Green);
    }
};

// Game class
class Game {
public:
    Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Sandbox Game") {
        // Create a 2D array to store blocks
        blocks.resize(HEIGHT / BLOCK_SIZE, std::vector<Block>(WIDTH / BLOCK_SIZE));

        // Create some blocks
        for (int y = 0; y < blocks.size(); y++) {
            for (int x = 0; x < blocks[y].size(); x++) {
                if (y % 2 == 0 && x % 2 == 0) {
                    blocks[y][x] = Block(x, y);
                }
            }
        }
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // Handle user input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                // Move camera up
                camera.y -= 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                // Move camera down
                camera.y += 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                // Move camera left
                camera.x -= 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                // Move camera right
                camera.x += 1;
            }

            // Draw blocks
            window.clear();
            for (int y = 0; y < blocks.size(); y++) {
                for (int x = 0; x < blocks[y].size(); x++) {
                    if (blocks[y][x].shape.getPosition().x + BLOCK_SIZE > camera.x &&
                        blocks[y][x].shape.getPosition().x < camera.x + WIDTH &&
                        blocks[y][x].shape.getPosition().y + BLOCK_SIZE > camera.y &&
                        blocks[y][x].shape.getPosition().y < camera.y + HEIGHT) {
                        window.draw(blocks[y][x].shape);
                    }
                }
            }

            // Update window
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    std::vector<std::vector<Block>> blocks;
    sf::Vector2f camera = sf::Vector2f(0, 0);
};

int main() {
    Game game;
    game.run();
    return 0;
}