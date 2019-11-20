#ifndef NEURON_H
#define NEURON_H
#include <vector>
using namespace std;


class Neuron
{
public:
    Neuron(vector<double> (*func)());
    double &weightRef(int index);
    vector<double> &weightsRef();
    vector<double> softmax(vector<double> z);
    vector<double> softmaxDeriv(vector<double> z);

private:
    /* Vector of weights on connections to the next layer, also means the amount of neurons in the next
     * layer if in a connected neural network. The first weight corresponds to the first neuron of the next layer
     * and so forth.
     */
    vector<double> weights;
    /* Pointer to the activation function set by the constructor.*/
    vector<double> (*activationFunction)();
};

#endif // NEURON_H
