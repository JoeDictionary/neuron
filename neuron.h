#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <math.h>
#include <ActivationFunctions.h>

using namespace std;

// 1a)

class Neuron
{
public:
    Neuron(double (*func)(double, double));

    /* Returns reference to an element of the 'weights' vector specified by the 'index' input. */
    double &weightRef(int index);

    /* Returns reference to the 'weights' vector. */
    vector<double> &weightsRef();

    /* Activates the neuron's 'currentVal'. Has an input for the denominator if the activation function is softmax. */
    double activate(double x, double denominator);

    /* Sets activation function of the neuron. */
    void setActivation(double (*func)(double, double));

    /* Pointer to the activation function set by the constructor. */
    double (*activationFunction)(double, double);

    /* Calculates and returns output layer gradient for a neuron */
    double getOutputGrad(int target);

    /* Calculates and returns hidden layer gradient for a neuron */
    double getHiddenGrad(int target, int indexOfLayer, int indexOfNeuron);

    /* List of "processed" results of neurons from the previous layer. Every result is the neuron's 'currentVal'
     * multiplied with the weight that leads to this neuron. */
    vector<double> interimResults;

    /* Value currently held by the neuron. */
    double currentVal;

private:
    /* Vector of weights on connections to the next layer. Length should be equal to the amount of neurons in the next
     * layer. The first weight corresponds to the first neuron of the next layer and so forth. */
    vector<double> weights;
};

#endif // NEURON_H
