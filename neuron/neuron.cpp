#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <vector>

#include "ActFunc.h"

#define N 9
#define newline cout<<endl
using namespace std;
using namespace ActFunc;

class Neuron
{
    public:
        Neuron(double* x, int n,
            double (*activation)(double) = (*sigmoid),
            double (*activationprime)(double) = (*sigmoidprime)) {

            this->activationFunc = activation;
            this->activationprimeFunc = activationprime;
            this->setweights(x, n);
        }

        Neuron(std::vector<double> x,
            double (*activation)(double) = (*sigmoid),
            double (*activationprime)(double) = (*sigmoidprime)) {

            this->activationFunc = activation;
            this->activationprimeFunc = activationprime;
            this->setweights(x);
        }

        ~Neuron() {}

        double getweight(int i) {
            return this->weights[i];
        }

        void setweights(double* w, int n) {
            double* ptr = w;
            for (int i = 0; i < n; i++) {
                weights.push_back(*(ptr++));
            }
        }

        void setweights(std::vector<double> x) {
            weights = x;
        }

        int summatory(double* inputvector, int sizeH) {
            if (sizeH != weights.size()) {
                return 0;
            }

            double scalarS = 0;
            for (int i = 0; i < sizeH; i++) {
                scalarS += inputvector[i] * weights[i];
            }
            this->summ = scalarS;
            return 1;
        }

        bool summatory(std::vector<double> inputvector) {
            if (inputvector.size() != weights.size()) {
                return 0;
            }

            double scalarS = 0;
            for (int i = 0; i < inputvector.size(); i++) {
                scalarS += inputvector[i] * weights[i];
            }
            this->summ = scalarS;
            return 1;
        }

        double output_activation(std::vector<double> inputvector) {
            if (this->summatory(inputvector)) {
                this->activate = this->activationFunc(this->summ);
                return 1;
            }
            else {
                return 0;
            }
        }

        double output_activation(double* inputvector, int sizeH) {
            if (this->summatory(inputvector, sizeH)) {
                this->activate = this->activationFunc(this->summ);
                return 1;
            }
            else {
                return 0;
            }
        }

    //private:
        double (*activationFunc)(double);
        double (*activationprimeFunc)(double);
        std::vector<double> weights;
        double summ;
        double activate;
};

int main()
{

    double w[3] = { 1.5, -0.7, -1.2 };
    std::vector<double> w2 = { 0.1, -0.2, -0.3 };

    double xm[3] = { 1.1, 2.0, 3.0 };
    std::vector<double> xv = { 1.1, 2.0, 1.0 };
    std::vector<double> xv2 = { 1.1, 2.0, 3.0, 4.0 };

    Neuron* n = new Neuron(w, sizeof(w) / sizeof(double));
    //for (int i = 0; i < n->weights.size(); i++) {
    //    cout << n->weights[i] << " ";
    //}

    newline;
    if (n->output_activation(xv)) {
        cout << "Summatory result:  " << n->summ;
        newline;
        cout << "Activation result:  " << n->activate;
    }
    else {
        cout << "ERROR";
    }

    newline;
    newline;

    if (n->output_activation(xv2)) {
        cout << "Activation result:  " << n->activate;
    }
    else {
        cout << "ERROR";
    }
    newline;
    newline;

    Neuron* n2 = new Neuron(w2, ActFunc::tanh, tanhprime);
    if (n2->output_activation(xv)) {
        cout << "Summatory result:  " << n2->summ;
        newline;
        cout << "Activation result:  " << n2->activate;
    }
    else {
        cout << "ERROR";
    }
    newline;
    newline;

    return 0;
}