//
// Created by kamble on 10-01-2024.
//

#include "Layer.h"

#include <utility>

Layer::Layer(int nodeCount, ActivationFunctionSchema activationFunction)
        : nodeCount(nodeCount), activationFunction(std::move(activationFunction)) {}
