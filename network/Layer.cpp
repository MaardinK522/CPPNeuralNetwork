//
// Created by kamble on 10-01-2024.
//

#include "Layer.h"

#include <utility>

Layer::Layer(int nodeCount, std::string activationFunction) {
    this->nodeCount = nodeCount;
    this->activationFunction = std::move(activationFunction);
}
