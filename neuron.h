#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <math.h>
#include <ActivationFunctions.h>

using namespace std;

class Neuron
{
public:
    /* Function overload if lRelu is selected as activation function. */
    Neuron(double (*func)(double));
    /* Function overload if softmax is selected as activation function, which needs a denominator. */
    Neuron(double (*func)(double, double));

    double &weightRef(int index);
    vector<double> &weightsRef();
    vector<double> activate(vector<double> z);
    void setActivation(vector<double> (*func)(vector<double>));
    void assignRandomWeights();

    /* Pointer to the activation function set by the constructor.*/
    vector<double> (*activationFunction)(vector<double>);

    double containedValue;

private:
    /* Vector of weights on connections to the next layer, also means the amount of neurons in the next
     * layer if in a connected neural network. The first weight corresponds to the first neuron of the next layer
     * and so forth.
     */
    vector<double> weights;
};

#endif // NEURON_H
