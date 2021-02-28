#pragma once

#include <math.h>

#ifndef _ACT_FUNC_H
#define _ACT_FUNC_H

namespace ActFunc {
    double sigmoid(double x);
    double sigmoidprime(double x);
    double tanh(double x);
    double tanhprime(double x);
    double max_activation(double x);
    double max_prime(double x);
}

#endif // !1
