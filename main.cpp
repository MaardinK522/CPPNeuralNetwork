#include <iostream>
#include "SFML/Graphics.hpp"
#include "matrix/Matrix.h"
#include "network/NeuralNetwork.h"

void testingMatrixLibs() {
    Matrix matrix(5, 5);
    Matrix matrix1(8, 5);

    std::cout << "Matrix 1" << std::endl;
    matrix.printMatrix();

    std::cout << "Matrix 2" << std::endl;
    matrix1.randomize();
    matrix1.printMatrix();

    std::cout << "Result matrix" << std::endl;
    matrix + matrix1;
    matrix.printMatrix();
}

void drawDemoSFML() {
    std::cout << "Starting SFML program" << std::endl;
    float mouseX = 0;
    float mouseY = 0;
    sf::RenderWindow window(sf::VideoMode(500, 500), "My Demo frame");
    sf::RectangleShape rect(sf::Vector2f(10, 10));
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        mouseX = event.mouseMove.x;
        mouseY = event.mouseMove.y;
        rect.setPosition(mouseX, mouseY);
        window.draw(rect);
        window.display();
    }
}

void testingNeuralNetwork() {
    int layerCount = 5;
    auto *layers = new Layer[5];
    for (int a = 0; a < layerCount; ++a) {
        layers[a] = Layer(a + 1, "sigmoid");
    }
    NeuralNetwork(10, layerCount, layers);
}

int main() {
    testingNeuralNetwork();
    return 0;
}
