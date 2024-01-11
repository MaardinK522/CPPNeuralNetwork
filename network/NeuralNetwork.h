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
    int layersCount;
    Layer *networkLayers;
    Matrix *weightsMatrices;
    Matrix *biasMatrices;

    NeuralNetwork() {
        this->inputsCount = 0;
        this->layersCount = 0;
        this->networkLayers = nullptr;
        this->outputsCount = 0;
        this->weightsMatrices = nullptr;
        this->biasMatrices = nullptr;
    };

public:

    NeuralNetwork(
            int inputCount,
            int layerCount,
            Layer *layers
    );

    double *processInputs(
            const double *inputs,
            int inputsLength
    ) const;

    void train(
            double **trainingInputs,
            double **trainingOutputs,
            int trainingInputLength,
            int trainingOutputLength,
            int trainingSize,
            int epochs
    ) const;

    void backPropagate(
            double *trainingInput,
            int trainingInputSize,
            double *trainingOutput,
            int trainingOutputSize
    ) const;
};

#endif //UNTITLED_NEURALNETWORK_H
