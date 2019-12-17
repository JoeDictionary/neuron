#ifndef NEURALNET_H
#define NEURALNET_H
#include <neuron.h>
#include <ActivationFunctions.h>

class NeuralNet
{
public:
    NeuralNet(vector< pair <int, double (*)(double)> > topology);
    vector<vector<Neuron>> net;

    int layerCount = 0;

    // 2b returns the output, in other words the last layer
    vector<Neuron> getOutput();

    // 2c
    vector<Neuron> getOutputFromInput(vector<double> input);

    void setupNeuralNetwork();
    void print();

    void backPropagate(vector<double>, int);

private:
    void addLayer(int neurons, double (*func)(double));

};

#endif // NEURALNET_H
