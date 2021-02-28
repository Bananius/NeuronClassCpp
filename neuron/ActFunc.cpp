#include "ActFunc.h"

namespace ActFunc {

    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    double sigmoidprime(double x) {
        return sigmoid(x) * (1.0 - sigmoid(x));
    }

    double tanh(double x) {
        return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
    }

    double tanhprime(double x) {
        return 1 - (tanh(x) * tanh(x));
    }

    double max_activation(double x) {
        if (x > 0) {
            return x;
        }
        return (double)0;
    }

    double max_prime(double x) {
        return (double)(x > 0);
    }
}