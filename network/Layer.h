//
// Created by kamble on 10-01-2024.
//

#ifndef UNTITLED_LAYER_H
#define UNTITLED_LAYER_H

#include "ActivationFunctionSchema.h"


static ActivationFunctionSchema SIGMOID(
        Activations::SIGMOID,
        [](double x) {
            return 1 / (1 + exp(-x));
        },
        [](double y) {
            return y * (1 - y);
        }
);
static ActivationFunctionSchema RE_LU(
        Activations::RE_LU,
        [](double x) {
            return std::max(0.0, x);
        },
        [](double y) {
            return y < 0 ? 0.0 : 1.0;
        }
);
static ActivationFunctionSchema TAN_H(
        Activations::TAN_H,
        [](double x) {
            return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
        },
        [](double y) {
            return 1 - (y * y);
        }
);

class Layer {

public:
    int nodeCount;
    ActivationFunctionSchema activationFunction;

    Layer(int nodeCount, ActivationFunctionSchema activationFunction);

    Layer() : activationFunction(SIGMOID), nodeCount(0) {}
};


#endif //UNTITLED_LAYER_H
