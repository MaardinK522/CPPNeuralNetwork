#include <iostream>
#include "SFML/Graphics.hpp"
#include "matrix/Matrix.h"
#include "network/NeuralNetwork.h"
#include "network/ActivationFunctionSchema.h"

void testingMatrixLibs() {
    Matrix matrix(5, 5);
    Matrix matrix1(5, 5);

    std::cout << "Matrix 1" << std::endl;
    matrix.randomize();
    matrix.printMatrix();

    std::cout << "Matrix 2" << std::endl;
    matrix1.randomize();
    matrix1.printMatrix();

    std::cout << "Result matrix" << std::endl;
    Matrix result = matrix + matrix1;
    result.printMatrix();

    result.mapMatrix(TAN_H.getEquation());
    std::cout << "After mapping sigmoid: " << std::endl;
    result.printMatrix();
}

void drawDemoSFML() {
    std::cout << "Starting SFML program" << std::endl;
    float mouseX;
    float mouseY;
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
//    drawDemoSFML();
    testingMatrixLibs();
//    testingNeuralNetwork();
    return 0;
}
