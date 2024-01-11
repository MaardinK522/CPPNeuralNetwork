//
// Created by kamble on 10-01-2024.
//

#ifndef UNTITLED_NEURALNETWORK_H
#define UNTITLED_NEURALNETWORK_H

#include "Layer.h"
#include "../matrix/Matrix.h"

class NeuralNetwork {
private:
    int inputsCount;
    int outputsCount;
    int layerCount;
    Layer *networkLayers;
    Matrix *weightsMatrices;
    Matrix *biasMatrices;

    NeuralNetwork() {
        this->inputsCount = 0;
        this->layerCount = 0;
        this->networkLayers = nullptr;
        this->outputsCount = 0;
        this->weightsMatrices = nullptr;
        this->biasMatrices = nullptr;
    };

public:

    NeuralNetwork(int inputCount, int layerCount, Layer *layers);

    double *processInputs(double *inputs, int inputsLength);

    void backPropagate(double *trainingInput, double *trainingOutput) const;

    void train(double **trainingInputs, double **trainingOutputs, int trainingInputLength, int trainingOutputLength,
               int trainingSize, int epochs) const;
};


#endif //UNTITLED_NEURALNETWORK_H
