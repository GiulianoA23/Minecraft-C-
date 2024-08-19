#include <SFML/Graphics.hpp>
#include <vector>

struct Block {
    sf::Vector2i position;
    sf::Color color;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sandbox Game");
    window.setFramerateLimit(60);

    std::vector<Block> blocks;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2i blockPos = { mousePos.x / 32, mousePos.y / 32 };
                    blocks.push_back({ blockPos, sf::Color::White });
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2i blockPos = { mousePos.x / 32, mousePos.y / 32 };
                    for (auto it = blocks.begin(); it != blocks.end(); ++it) {
                        if (it->position == blockPos) {
                            blocks.erase(it);
                            break;
                        }
                    }
                }
            }
        }

        window.clear();
        for (const auto& block : blocks) {
            sf::RectangleShape shape(sf::Vector2f(32, 32));
            shape.setPosition(block.position.x * 32, block.position.y * 32);
            shape.setFillColor(block.color);
            window.draw(shape);
        }
        window.display();
    }

    return 0;
}
