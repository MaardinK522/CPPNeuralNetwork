//
// Created by kamble on 10-01-2024.
//
#include <iostream>
#include "NeuralNetwork.h"
#include "ctime"
#include "functional"
#include <cmath>


NeuralNetwork::NeuralNetwork(int inputCount, int layerCount, Layer *layers) {
    this->inputsCount = inputCount;
    this->layersCount = layerCount;
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

//        std::cout << "Layer index: " << layerIndex << std::endl;
//        std::cout << "Weights matrix: " << std::endl;
//        this->weightsMatrices[layerIndex].printMatrix();
//        std::cout << "Bias matrix: " << std::endl;
//        this->biasMatrices[layerIndex].printMatrix();
    }
}

void NeuralNetwork::train(double **trainingInputs, double **trainingOutputs, int trainingInputLength,
                          int trainingOutputLength, int trainingSize, int epochs) const {
    // Getting random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < epochs; ++i) {
        int randomIndex = std::rand() % trainingSize;
        NeuralNetwork::backPropagate(
                trainingInputs[randomIndex],
                trainingInputLength,
                trainingOutputs[randomIndex],
                trainingOutputLength
        );
    }
}


void NeuralNetwork::backPropagate(double *trainingInput, int trainingInputSize, double *trainingOutput,
                                  int trainingOutputSize) const {
}

double *NeuralNetwork::processInputs(const double *inputs, int inputsLength) const {
    if (inputsLength != this->inputsCount)
        throw std::runtime_error("Mismatch length of inputs to the network.");
    Matrix inputMatrix = transpose(Matrix(1, inputsCount, new double *{const_cast<double *>(inputs)}));
    auto *outputMatrices = new Matrix[this->layersCount];
    for (int layerIndex = 0; layerIndex < this->layersCount; ++layerIndex) {
        if (layerIndex == 0)
            outputMatrices[layerIndex]
                    = matrixMultiplication(this->weightsMatrices[layerIndex], inputMatrix);
        else
            outputMatrices[layerIndex]
                    = matrixMultiplication(this->weightsMatrices[layerIndex],
                                           outputMatrices[layerIndex - 1]);
        outputMatrices[layerIndex] += this->biasMatrices[layerIndex];
        outputMatrices[layerIndex].mapMatrix(this->networkLayers[layerIndex].activationFunction.getEquation());
    }
    std::cout << "Processing inputs: " << std::endl;
    return transpose(outputMatrices[this->layersCount - 1]).getColumn(0);
}
