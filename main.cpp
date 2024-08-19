#include <SFML/Graphics.hpp>
#include <vector>

// Clase para representar un cubo
class Cubo {
public:
    sf::RectangleShape forma;
    int x, y;

    Cubo(int x, int y) : x(x), y(y) {
        forma.setSize(sf::Vector2f(50, 50));
        forma.setPosition(x, y);
        forma.setFillColor(sf::Color::Red);
    }
};

int main() {
    // Inicializar la ventana
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Sandbox");

    // Vector para almacenar los cubos
    std::vector<Cubo> cubos;

    // Bucle principal
    while (ventana.isOpen()) {
        // Manejar eventos
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }

        // Dibujar los cubos
        ventana.clear();
        for (const auto& cubo : cubos)
            ventana.draw(cubo.forma);

        // Verificar si se ha presionado una tecla
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            // Agregar un nuevo cubo
            cubos.push_back(Cubo(100 + cubos.size() * 60, 100));
        }

        // Verificar si se ha presionado la tecla 'D'
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            // Eliminar el último cubo
            if (!cubos.empty())
                cubos.pop_back();
        }

        // Actualizar la ventana
        ventana.display();
    }

    return 0;
}