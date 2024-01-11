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
} SIGMOID(
        Activations::SIGMOID,
        [](double x) {
            return 1 / (1 + exp(-x));
        },
        [](double y) {
            return y * (1 - y);
        }
), RE_LU(
        Activations::RE_LU,
        [](double x) {
            return std::max(0.0, x);
        },
        [](double y) {
            return y < 0 ? 0.0 : 1.0;
        }
), TAN_H(
        Activations::TAN_H,
        [](double x) {
            return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
        },
        [](double y) {
            return 1 - (y * y);
        }
);

#endif //UNTITLED_ACTIVATIONFUNCTIONSCHEMA_H
