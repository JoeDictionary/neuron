#include "neuralnet.h"
#include "neuron.h"
#include "ActivationFunctions.h"

/* Constructor 'NeuralNet' accepts a topology, which is a vector filled with <int, function> pairs, which is
 * where the function must take a vector<double> as input and also return a vector<double>.
 * Every pair represents a layer in the neural network, where the first part of the pair is the amount of neurons in
 * that layer and the second part is the activation function used by the neurons in that layer.
 * The first pair in the vector of pairs represents the input layer, the last pait represents the output layer and
 * every pair inbetween represents a hidden layer.
 */
NeuralNet::NeuralNet(vector< pair <int, vector<double> (*)(vector<double>)> > topology)
{
    layerCount = 0;
    /* Fills the 'net' vector with vectors<Neuron> to represent a neural network. */
    for(pair <int, vector<double> (*)(vector<double>)> i : topology){
        addLayer(i.first, i.second);
        layerCount++;
    }

}

void NeuralNet::addLayer(int neuronAmt, vector<double> (*func)(vector<double>))
{
    net.push_back(vector<Neuron>(neuronAmt, Neuron(func)));
}

//2b gibt den output des neuronalen Netzwerkes zurueck als ein Vektor von Vektoren von Neuronen: vector<vector<Neuron>>
vector<Neuron> NeuralNet::getOutput()
{
    return net.at(layerCount);
}

//2c berechnet den Output fuer eine bestimmte Eingabe
vector<Neuron> NeuralNet::getOutputFromInput(vector<double> input)
{
    // set first layer to input
    //net.at(0) = input;

    //iteratively activate the neurons
    int currLayer = 0;

    //create a temporary vector to store output of n-th layer to be used as inputs during the next iteration
    vector<vector<double>> values;
    values.clear();

    //populate liaison vector with values from input layer
    for(double n : input){
        vector<double> tmp;
        tmp.push_back(n);
        values.push_back(tmp);
    }

    //go through layers
    for(vector<Neuron> layer : net){

        //index counter for layer currently processed
        currLayer++;

        int currNeuron = 0;
        //go through neurons in each layer
        for(Neuron neuron : layer){

            //set activation function as per layer; all layers use lRelu, output layer uses softmax
            neuron.setActivation(currLayer == layerCount ? afunc::lRelu : afunc::softmax);

            double currval = 0;
            //read input from liaison vector (read outputs from previous layer connected to this neuron)
            //and add them into a single value;
            for(double connected_output : values.at(currNeuron)){
                currval += connected_output;
            }

            //set input for the current neuron
            neuron.setInput(currval);

            //apply relevant function
            neuron.calculate(values.at(currNeuron),currNeuron);

            //we probably want to increase weight values during the learning phase..?
            //neuron.addToWeights();

            //multiply this result with all the weights facing outward from this neuron
            values.push_back(neuron.getNeuronOutput());

            currNeuron++;
        }
    }

    // return the output layer;
    return net.at(layerCount);
}
