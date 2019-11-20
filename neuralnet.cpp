#include "neuralnet.h"

NeuralNet::NeuralNet(vector<int> topology)
{

    for(int num : topology){
        vector<Neuron*> neuronVec = {};
        for(int i = 0; i < num; i++){
            neuronVec.push_back(new Neuron());
        }
        net.push_back(neuronVec);
    }
}
