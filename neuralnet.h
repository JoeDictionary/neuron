#ifndef NEURALNET_H
#define NEURALNET_H
#include <neuron.h>
#include <ActivationFunctions.h>

class NeuralNet
{
public:
    NeuralNet(vector< pair <int, vector<double> (*)(vector<double>)> > topology);
    vector<vector<Neuron>> net;

    int layerCount = 0;

    // 2b returns the output, in other words the last layer
    vector<Neuron> getOutput();

    // 2c
    vector<Neuron> getOutputFromInput(vector<double> input);

private:
    void addLayer(int neurons, vector<double> (*func)(vector<double>));

};

#endif // NEURALNET_H
