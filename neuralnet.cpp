#include "neuralnet.h"
#include "neuron.h"
#include "ActivationFunctions.h"
#include <iostream>

/* Constructor 'NeuralNet' accepts a topology, which is a vector filled with <int, function> pairs, which is
 * where the function must take a vector<double> as input and also return a vector<double>.
 * Every pair represents a layer in the neural network, where the first part of the pair is the amount of neurons in
 * that layer and the second part is the activation function used by the neurons in that layer.
 * The first pair in the vector of pairs represents the input layer, the last pait represents the output layer and
 * every pair inbetween represents a hidden layer.
 */
NeuralNet::NeuralNet(vector< pair <int, double (*)(double)> > topology)
{
    layerCount = 0;
    /* Fills the 'net' vector with vectors<Neuron> to represent a neural network. */
    for(pair <int, double (*)(double)> i : topology){
        addLayer(i.first, i.second);
        layerCount++;
    }

}

void NeuralNet::addLayer(int neuronAmt, double (*func)(double))
{
    net.push_back(vector<Neuron>(neuronAmt, Neuron()));
}

//2b gibt den output des neuronalen Netzwerkes zurueck als ein Vektor von Vektoren von Neuronen: vector<vector<Neuron>>
vector<Neuron> NeuralNet::getOutput()
{
    return net.at(layerCount);
}

//set the count of weights in each Neuron class equal to the number of neurons in previous layer respectively
void NeuralNet::setupNeuralNetwork(){
    int cnt=0;
    int lastLayerCount = net.at(0).size();

    for(vector<Neuron> &layer : net){
        if(cnt++==0){continue;}
        for(Neuron &neuron : layer){
            neuron.setWeightLength(lastLayerCount);
        }
        lastLayerCount = layer.size();
    }
}

//2c berechnet den Output fuer eine bestimmte Eingabe
vector<Neuron> NeuralNet::getOutputFromInput(vector<double> input)
{
   //populate first neuron_layer vector with values from input layer
   vector<Neuron> firstLayer = net.at(0);
   int index = 0;
    for(Neuron &neuron : firstLayer){
        neuron.setInput(input.at(index++));
    }

    //now the values in the first layer are set to this method's input

    //go through all the layers in net, start with index 1, as we calculate values at this index based on the previous index
    for(int index_layer = 1; index_layer<net.size(); index_layer++){
        vector<Neuron> currentLayer = net.at(index_layer);

        //go through all the Neurons in the current layer
        for(int index_neuron_in_currlayer = 0; index_neuron_in_currlayer<currentLayer.size(); index_neuron_in_currlayer++){
            Neuron currentNeuron = currentLayer.at(index_neuron_in_currlayer);

            double sum = 0;
            int index_prev_layer = 0;

            //harvest all the values from the previous layer
            for(Neuron &oneOfpreviousLayersNeurons : net.at(index_layer-1)){

                sum += currentNeuron.weights.at(index_prev_layer) * oneOfpreviousLayersNeurons.value;
                index_prev_layer++;
            }
            //run relu function with the sum of the previous layer values*weights
            currentNeuron.setInput(afunc::lRelu(sum));
        }
    }
/*
        int currNeuron = 0;
        //backup liaison values
        vector<vector<double>> values_bcp;
        for(vector<double> value_arr : values){
            values_bcp.push_back(value_arr);
            //std::cout << "\nBACKING UP " << value_arr[0] << values_bcp.size() << endl;
        }
        values.clear();*/
/*
        //set liaison to the size of the next layer
        for(Neuron n : net.at(currLayer+1)){
            vector<double> tmp;
            values.push_back(tmp);
        }
        //now liaison vector has the same size as the next layer
*/
/*        for(vector<double> value_arr : values_bcp){
            std::cout << "\n [ ";
            for(double v : value_arr){
                std::cout << " " << v << " ";
            }
            std::cout << " ]";
        }*/

        //go through neurons in each layer
/*        for(Neuron neuron : layer){
std::cout << "\n\n neurons in layer: " << layer.size() << endl;
            //set activation function as per layer; all layers use lRelu, output layer uses softmax
            neuron.setActivation(currLayer == layerCount ? afunc::lRelu : afunc::softmax);

            std::cout << "aaaa" << endl;

            double currval = 0;
            //read input from liaison vector (read outputs from previous layer connected to this neuron)
            //and add them into a single value;
            vector<double> this_neurons_inputs = values_bcp.at(currNeuron);
            for(double connected_output : this_neurons_inputs){
                currval += connected_output;
            }
            std::cout << "bbbb" << endl;

            //set input for the current neuron
            neuron.setInput(currval);

            std::cout << "cccc" << values_bcp.at(currNeuron)[0] << endl;
            //apply relevant function
            neuron.calculate(values_bcp.at(currNeuron),currNeuron);

            std::cout << "dddd" << endl;
            //we probably want to increase weight values during the learning phase..?
            //neuron.addToWeights();

            //multiply this result with all the weights facing outward from this neuron
            std::cout << "eeee" << endl;
            values.push_back(neuron.getNeuronOutput());

            currNeuron++;
        }

        //index counter for layer currently processed
        currLayer++;
    }*/

    // return the output layer;

    for(Neuron n: net.at(layerCount-1)){
        cout << endl << n.value;
    }

    return net.at(layerCount-1);
}
