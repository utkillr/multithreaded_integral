//
// Created by nosikk on 2/4/2019.
//

#ifndef INTEGRAL_FUNCTORS_H
#define INTEGRAL_FUNCTORS_H

#include <string>
#include <vector>

using namespace std;

class Function {
public:
    Function() = default;
    virtual double operator() (double x);
    virtual string name();
    virtual string representation();
    ~Function() = default;
};

class PolynomialFunction: virtual public Function {
// a0x^n + ... + anx^0
private:
    vector<double> a;
public:
    PolynomialFunction(vector<double> a);
    virtual double operator() (double x);
    virtual string name();
    virtual string representation();
    ~PolynomialFunction() = default;
};

class SinFunction: virtual public Function {
// sin(x)
private:
    double w, f;
public:
    SinFunction(double w, double f);
    virtual double operator() (double x);
    virtual string name();
    virtual string representation();
    ~SinFunction() = default;
};

class CosFunction: virtual public Function {
// cos(x)
private:
    double w, f;
public:
    CosFunction(double w, double f);
    virtual double operator() (double x);
    virtual string name();
    virtual string representation();
    ~CosFunction() = default;
};

class SinCosPolynomialFunction: virtual public Function {
// sin(x)cos(x) + poly
private:
    SinFunction *sinFunction;
    CosFunction *cosFunction;
    PolynomialFunction *polynomialFunction;
public:
    SinCosPolynomialFunction(double sin_w, double sin_f, double cos_w, double cos_f, vector<double> a);
    virtual double operator() (double x);
    virtual string name();
    virtual string representation();
    ~SinCosPolynomialFunction();
};

class LogarithmicFunction: public Function {
private:
    double base;
public:
    LogarithmicFunction(double base);
    virtual double operator() (double x);
    virtual string name();
    virtual string representation();
    ~LogarithmicFunction() = default;
};

class ExponentialFunction: public Function {
public:
    ExponentialFunction() = default;
    virtual double operator() (double x);
    virtual string name();
    virtual string representation();
    ~ExponentialFunction() = default;
};

#endif //INTEGRAL_FUNCTORS_H
