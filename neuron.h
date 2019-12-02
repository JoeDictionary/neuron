#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <math.h>
#include <ActivationFunctions.h>

using namespace std;

class Neuron
{
public:
    Neuron(double (*func)(double, double));

    double &weightRef(int index);
    vector<double> &weightsRef();
    double activate(double z);
    void setActivation(double (*func)(double));
    void assignRandomWeights();

    /* Pointer to the activation function set by the constructor.*/
    double (*activationFunction)(double);

    double containedValue;

private:
    /* Vector of weights on connections to the next layer, also means the amount of neurons in the next
     * layer if in a connected neural network. The first weight corresponds to the first neuron of the next layer
     * and so forth. */
    vector<double> weights;
};

#endif // NEURON_H
