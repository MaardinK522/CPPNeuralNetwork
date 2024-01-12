//
// Created by kamble on 12-01-2024.
//

#ifndef UNTITLED_ACTIVATIONFUNCTIONSCHEMA_H
#define UNTITLED_ACTIVATIONFUNCTIONSCHEMA_H

#pragma once

#include "iostream"
#include "functional"
#include "cmath"
#include "Activations.h"
#include "MapAble.h"

struct ActivationFunctionSchema {
public:
    ActivationFunctionSchema(Activations name, MapAble equation, MapAble derivative)
            : activationFunctionName(name),
              equation(std::move(equation)),
              derivative(std::move(derivative)) {}

    Activations getActivationFunctionName() {
        return this->activationFunctionName;
    }

    MapAble getEquation() {
        return this->equation;
    }

    MapAble getDerivative() {
        return this->derivative;
    }

private:
    Activations activationFunctionName;
    MapAble equation;
    MapAble derivative;
};


#endif //UNTITLED_ACTIVATIONFUNCTIONSCHEMA_H
