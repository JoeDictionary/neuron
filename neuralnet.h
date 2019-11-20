#ifndef NEURALNET_H
#define NEURALNET_H
#include <neuron.h>
#include <ActivationFunctions.h>

class NeuralNet
{
public:
    NeuralNet(vector< pair <int, vector<double> (*)(vector<double>)> > topology);
    vector<vector<Neuron>> net;

private:
    void addLayer(int neurons, vector<double> (*func)(vector<double>));

};

#endif // NEURALNET_H
