//
// Created by kamble on 10-01-2024.
//
#include <iostream>
#include "NeuralNetwork.h"
#include "ctime"

NeuralNetwork::NeuralNetwork(int inputCount, int layerCount, Layer *layers) {
    this->inputsCount = inputCount;
    this->layerCount = layerCount;
    this->networkLayers = layers;
    this->outputsCount = layers[layerCount - 1].nodeCount;
    this->weightsMatrices = new Matrix[layerCount];
    this->biasMatrices = new Matrix[layerCount];

    // Iterating over each layer to initialize the weights and biases.
    for (int layerIndex = 0; layerIndex < layerCount; ++layerIndex) {
        if (layerIndex == 0) {
            this->weightsMatrices[layerIndex]
                    = Matrix(this->networkLayers[layerIndex].nodeCount, this->inputsCount);
            this->biasMatrices[layerIndex]
                    = Matrix(this->networkLayers[layerIndex].nodeCount, 1);
            this->weightsMatrices[layerIndex].randomize();
            this->biasMatrices[layerIndex].randomize();
            continue;
        }
        this->weightsMatrices[layerIndex]
                = Matrix(this->networkLayers[layerIndex].nodeCount, this->networkLayers[layerIndex - 1].nodeCount);
        this->biasMatrices[layerIndex]
                = Matrix(this->networkLayers[layerIndex].nodeCount, 1);
        this->weightsMatrices[layerIndex].randomize();
        this->biasMatrices[layerIndex].randomize();

        std::cout << "Layer index: " << layerIndex << std::endl;
        std::cout << "Weights matrix: " << std::endl;
        this->weightsMatrices[layerIndex].printMatrix();
        std::cout << "Bias matrix: " << std::endl;
        this->biasMatrices[layerIndex].printMatrix();
    }
}

void NeuralNetwork::train(double **trainingInputs, double **trainingOutputs, int trainingInputLength,
                          int trainingOutputLength, int trainingSize, int epochs) const {
    // Getting random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomIndex = std::rand() % trainingSize;
    NeuralNetwork::backPropagate(trainingInputs[randomIndex], trainingOutputs[randomIndex]);
}git config --global --add safe.directory C:/Users/kambl/CLionProjects/untitled


void NeuralNetwork::backPropagate(double *trainingInput, double *trainingOutput) const {

}
