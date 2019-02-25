//
// Created by nosikk on 2/4/2019.
//

#include "functors.h"
#include <algorithm>
#include <vector>

Function* selectFunction(string name) {
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    if (name == "POLYNOMIAL") {
        vector<double> a {1, 2, 3};
        auto polynomialFunction = new PolynomialFunction(a);
        return polynomialFunction;
    } else if (name == "SIN") {
        double w = 1, f = 0;
        auto sinFunction = new SinFunction(w, f);
        return sinFunction;
    } else if (name == "COS") {
        double w = 1, f = 0;
        auto cosFunction = new CosFunction(w, f);
        return cosFunction;
    } else if (name == "SIN_COS_POLYNOMIAL") {
        double sin_w = 1, sin_f = 0;
        double cos_w = 1, cos_f = 0;
        vector<double> a {1, 2, 3};
        auto sinCosPolynomialFunction = new SinCosPolynomialFunction(sin_w, sin_f, cos_w, cos_f, a);
        return sinCosPolynomialFunction;
    } else if (name == "LOGARITHMIC") {
        double base = 2;
        auto logarithmicFunction = new LogarithmicFunction(base);
        return logarithmicFunction;
    } else if (name == "EXPONENTIAL") {
        auto exponentialFunction = new ExponentialFunction();
        return exponentialFunction;
    } else {
        auto function = new Function();
        return function;
    }
};

void sample_integral(Function* fn, double start, double interval, int steps, double &result) {
    double current = start;
    for (int i = 0; i < steps; i++) {
        result += ((fn->operator()(current + interval) + fn->operator()(current)) / 2) * interval;
        current += interval;
    }
};