#include "neuralnet.h"

/* Constructor 'NeuralNet' accepts a topology, which is a vector filled with <int, function> pairs, which is
 * where the function must take a vector<double> as input and also return a vector<double>.
 * Every pair represents a layer in the neural network, where the first part of the pair is the amount of neurons in
 * that layer and the second part is the activation function used by the neurons in that layer.
 * The first pair in the vector of pairs represents the input layer, the last pait represents the output layer and
 * every pair inbetween represents a hidden layer.
 */
NeuralNet::NeuralNet(vector< pair <int, vector<double> (*)(vector<double>)> > topology)
{
    /* Fills the 'net' vector with vectors<Neuron> to represent a neural network. */
    for(pair <int, vector<double> (*)(vector<double>)> i : topology){
        addLayer(i.first, i.second);
    }
}

void NeuralNet::addLayer(int neuronAmt, vector<double> (*func)(vector<double>))
{
    net.push_back(vector<Neuron>(neuronAmt, Neuron(func)));
}

