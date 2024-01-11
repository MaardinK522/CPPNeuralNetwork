//
// Created by kamble on 10-01-2024.
//

#ifndef UNTITLED_LAYER_H
#define UNTITLED_LAYER_H

#include "string"

class Layer { ;

public:
    int nodeCount;
    std::string activationFunction;

    Layer(int nodeCount, std::string activationFunction);

    Layer() {
        this->nodeCount = 0;
        this->activationFunction = "sigmoid";
    }
};


#endif //UNTITLED_LAYER_H
