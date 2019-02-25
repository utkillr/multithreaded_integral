//
// Created by nosikk on 2/4/2019.
//

#include "functors.h"
#include <cmath>
#include <sstream>

double Function::operator() (double x) {
    return x;
};
string Function::name() {
    return "Function";
};
string Function::representation() {
    return "x";
}


PolynomialFunction::PolynomialFunction(vector<double> a) : Function() {
    this->a = move(a);
}
double PolynomialFunction::operator() (double x) {
    double result = 0;
    for (int i = 0; i < a.size(); i++) {
        result += a[i] * pow(x, (double)(a.size() - i - 1));
    }
    return result;
}
string PolynomialFunction::name() {
    return "PolynomialFunction";
};
string PolynomialFunction::representation() {
    ostringstream result;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] != 0) {
            if (a[i] == 1) {
                result << "x^" << a.size() - i - 1 << " + ";
            } else {
                result << a[i] << "x^" << a.size() - i - 1 << " + ";
            }
        }
    }
    result << a[a.size() - 1];
    return result.str();
}


SinFunction::SinFunction(double w, double f) : Function() {
    this->w = w;
    this->f = f;
}
double SinFunction::operator() (double x) {
    return sin(w * x + f);
}
string SinFunction::name() {
    return "SinFunction";
};
string SinFunction::representation() {
    if (w == 0 && f == 0) {
        return "sin(0)";
    }
    ostringstream result;
    result << "sin(";
    if (w == 0) {
        result << "x";
    } else {
        if (w == 1) {
            result << "x";
        } else {
            result << w << "x";
        }
    }
    if (f == 0) {
        result << ")";
    } else {
        result << " + " << f << ")";
    }
    return result.str();
}


CosFunction::CosFunction(double w, double f) {
    this->w = w;
    this->f = f;
}
double CosFunction::operator() (double x) {
    return cos(w * x + f);
}
string CosFunction::name() {
    return "CosFunction";
};
string CosFunction::representation() {
    if (w == 0 && f == 0) {
        return "cos(0)";
    }
    ostringstream result;
    result << "cos(";
    if (w == 0) {
        result << "x";
    } else {
        if (w == 1) {
            result << "x";
        } else {
            result << w << "x";
        }
    }
    if (f == 0) {
        result << ")";
    } else {
        result << " + " << f << ")";
    }
    return result.str();
}


SinCosPolynomialFunction::SinCosPolynomialFunction(double sin_w, double sin_f, double cos_w, double cos_f, vector<double> a) : Function() {
    sinFunction = new SinFunction(sin_w, sin_f);
    cosFunction = new CosFunction(cos_w, cos_f);
    polynomialFunction = new PolynomialFunction(move(a));
}
double SinCosPolynomialFunction::operator() (double x) {
    return sinFunction->operator()(x) * cosFunction->operator()(x) + polynomialFunction->operator()(x);
}
string SinCosPolynomialFunction::name() {
    return "SinCosPolynomialFunction";
};
string SinCosPolynomialFunction::representation() {
    ostringstream result;
    result << sinFunction->representation() << " * " << cosFunction->representation() << " + " << polynomialFunction->representation();
    return result.str();
}
SinCosPolynomialFunction::~SinCosPolynomialFunction() {
    delete sinFunction;
    delete cosFunction;
    delete polynomialFunction;
}


LogarithmicFunction::LogarithmicFunction(double base) {
    this->base = base;
}
double LogarithmicFunction::operator() (double x) {
    if (x == 0) {
        x =0.00001;
    }
    return log(x) / log(base);
}
string LogarithmicFunction::name() {
    return "LogarithmicFunction";
};
string LogarithmicFunction::representation() {
    ostringstream result;
    result << "log_" << base << "(x)";
    return result.str();
}


double ExponentialFunction::operator() (double x) {
    return exp(x);
}
string ExponentialFunction::name() {
    return "ExponentialFunction";
};
string ExponentialFunction::representation() {
    return "e^x";
}
