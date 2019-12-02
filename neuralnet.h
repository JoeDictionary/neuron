#ifndef NEURALNET_H
#define NEURALNET_H
#include <neuron.h>
#include <ActivationFunctions.h>

class NeuralNet
{
public:
    NeuralNet(vector< pair <int, double (*)(double, double)>> topology);

    vector<vector<Neuron>> net;
    vector<double> activateLayer(vector<Neuron>& layer);

private:
    void addLayer(int neurons, double (*func)(double, double));
};

#endif // NEURALNET_H
