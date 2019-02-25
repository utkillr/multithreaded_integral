//
// Created by nosikk on 2/4/2019.
//

#ifndef INTEGRAL_UTIL_H
#define INTEGRAL_UTIL_H

#include <string>
#include "functors.h"

Function* selectFunction(string name);
void sample_integral(Function* fn, double start, double interval, int steps, double &result);

#endif //INTEGRAL_UTIL_H
