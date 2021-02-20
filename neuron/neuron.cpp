#include<iostream>
#include<math.h>
#include <stdlib.h>
#include <iomanip>
#include <clocale>
using namespace std;

double sigmoid(double x) {
    return 1 / (1 - exp(-x));
}

class Neuron
{
public:
    Neuron(double* x, int n, double (*activation)(double) = (*sigmoid)) {
        this->setweights(x, n);
        this->activationFunc = activation;
    }
    ~Neuron() {
        delete[] weights;
    }

    double(*activationFunc)(double);
    double getweight(int i) {
        return this->weights[i];
    }
    void setweights(double* x, int n) {
        Nw = n;
        if (weights == nullptr) {
            weights = new double[n];
        }
        else {
            delete[] weights;
            weights = new double[n];
        }

        double* ptr = weights;
        for (int i = 0; i < Nw; i++) {
            *(ptr++) = *(x++);
        }
    }
    int getsize() {
        return this->Nw;
    }

    double getactivation(int i) {
        return this->activationFunc(this->weights[i]);
    }

    private:
        double* weights = nullptr;
        int Nw;
};

int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    double w[5] = { 0.5, 0.7, 1.2, 0.7, 1.2 };
    cout << "Содержимое массива весов w..." << endl;
    for (int i = 0; i < sizeof(w)/sizeof(double); i++) {
        cout << w[i] << " ";
    }
    cout << endl << endl;
    

    cout << "Создаем объект класса Neuron: n, и загружаем в него веса w. Функция активации по умолчанию - sigmoid." << endl;
    Neuron* n = new Neuron(w, sizeof(w) / sizeof(double));
    cout << "Выводим содержимое поля weights при помощи соответсвующего метода getweight..." << endl;
    for (int i = 0; i < n->getsize(); i++) {
        cout << n->getweight(i) << " ";
    }
    cout << endl << endl;

    cout << "Выводим содержимое поля weights с применением активационной функции..." << endl;
    for (int i = 0; i < n->getsize(); i++) {
        cout << n->getactivation(i) << " ";
    }
    cout << endl << endl;

    cout << "Меняем содержимое поля weights и выводим новое содержимое..." << endl;
    double w2[10] = { 0.333, 0.7, 1.2, 0.7, 1.2, 0.5, 0.7, 1.2, 0.7, 1.2 };
    n->setweights(w2, sizeof(w2) / sizeof(double));
    
    for (int i = 0; i < n->getsize(); i++) {
        cout << n->getweight(i) << " ";
    }
    cout << endl << endl;

    return 0;  // завершение программы
}