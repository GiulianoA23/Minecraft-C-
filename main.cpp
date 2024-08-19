// main.cpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

const int CHUNK_SIZE = 16;
const int WORLD_SIZE = 10;

struct Block {
    int type;
    bool solid;
};

class Chunk {
public:
    Chunk(int x, int z) {
        m_x = x;
        m_z = z;
        m_blocks.resize(CHUNK_SIZE * CHUNK_SIZE);
        generateBlocks();
    }

    void draw(sf::RenderWindow& window) {
        for (int x = 0; x < CHUNK_SIZE; x++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                if (m_blocks[x + z * CHUNK_SIZE].solid) {
                    sf::RectangleShape block(sf::Vector2f(32, 32));
                    block.setPosition(m_x * CHUNK_SIZE * 32 + x * 32, m_z * CHUNK_SIZE * 32 + z * 32);
                    block.setFillColor(sf::Color(100, 100, 100));
                    window.draw(block);
                }
            }
        }
    }

private:
    void generateBlocks() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < m_blocks.size(); i++) {
            m_blocks[i].type = (dis(gen) < 0.5) ? 0 : 1;
            m_blocks[i].solid = (m_blocks[i].type == 0);
        }
    }

    int m_x, m_z;
    std::vector<Block> m_blocks;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WORLD_SIZE * CHUNK_SIZE * 32, WORLD_SIZE * CHUNK_SIZE * 32), "Sandbox Game");

    std::vector<Chunk> chunks;
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int z = 0; z < WORLD_SIZE; z++) {
            chunks.emplace_back(x, z);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (const auto& chunk : chunks) {
            chunk.draw(window);
        }
        window.display();
    }

    return 0;
}
