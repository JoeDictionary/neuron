#ifndef NEURALNET_H
#define NEURALNET_H
#include <neuron.h>
#include <ActivationFunctions.h>

class NeuralNet
{
public:
    NeuralNet(vector<int> topology);
    vector<vector<Neuron*>> net;

private:

};

#endif // NEURALNET_H
