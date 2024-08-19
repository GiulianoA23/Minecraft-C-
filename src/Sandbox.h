#ifndef SANDBOX_H
#define SANDBOX_H

#include <SFML/Graphics.hpp>

class Sandbox {
public:
    Sandbox();
    ~Sandbox();

    void init(SDL_Renderer* renderer);
    void update();
    void draw(SDL_Renderer* renderer);

private:
    sf::RectangleShape block;
};

#endif // SANDBOX_H