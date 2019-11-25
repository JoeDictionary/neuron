#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <math.h>
#include <ActivationFunctions.h>

using namespace std;

class Neuron
{
public:
    Neuron(vector<double> (*func)(vector<double>) = afunc::lRelu);

    double &weightRef(int index);
    vector<double> &weightsRef();
    vector<double> activate(vector<double> z);
    void setActivation(vector<double> (*func)(vector<double>));
    void addToWeights(vector<double>);
    int getNeuronCount();
    vector<double> getNeuronOutput();
    void setInput(double);
    void calculate(vector<double>, int);

private:
    /* Vector of weights on connections to the next layer, also means the amount of neurons in the next
     * layer if in a connected neural network. The first weight corresponds to the first neuron of the next layer
     * and so forth.
     */
    vector<double> weights;
    double value;

    /* Pointer to the activation function set by the constructor.*/
    vector<double> (*activationFunction)(vector<double>);
};

#endif // NEURON_H
