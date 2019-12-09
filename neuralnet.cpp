#include "neuralnet.h"

NeuralNet::NeuralNet(vector< pair <int, double (*)(double, double)> > topology)
{
    /* Fills the 'net' vector with vectors<Neuron> to represent a neural network. */
    for(pair <int, double (*)(double, double)> i : topology){
        addLayer(i.first, i.second);
    }
}

void NeuralNet::addLayer(int neuronAmt, double (*func)(double, double))
{
    vector<Neuron> layer;
    for (int i = 0; i < neuronAmt; i++){
        Neuron p(func);
        layer.push_back(p);
    }
    net.push_back(layer);
}

vector<double> NeuralNet::activateLayer(vector<Neuron>& layer)
{
    /*
    vector<double> (*aFunc)(vector<double>) = layer[0].activationFunction;
    vector<double> rawLayer;
    vector<double> activatedLayer;

    // Fill 'rawLayer' with not activated values from the 'layer' neurons.
    for (Neuron i : layer){
        rawLayer.push_back(i.containedValue);
    }

    activatedLayer = aFunc(rawLayer);

    for (int i = 0; i < activatedLayer.size(); i++) {
        (layer[i]).containedValue = activatedLayer[i];
    }
    */
}

double NeuralNet::randWeight()
{

}
