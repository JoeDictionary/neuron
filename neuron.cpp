#include "neuron.h"
#include <QCoreApplication>
#include <iostream>
using namespace std;


Neuron::Neuron(/*vector<double> (*func)(double)*/)
{
    //activationFunction = func;
}

double& Neuron::weightRef(int index){
        return weights[index];
    }

vector<double>& Neuron::weightsRef(){
        return weights;
    }
/*
// multiply all weights with this neuron's output
void Neuron::addToWeights(vector<double> arr){
    for(int i=0; i<arr.size(); i++){
        weights.at(i) *= arr.at(i);
    }
}*/

// get count of weights in this layer, should equal the number of neurons in the next layer
int Neuron::getNeuronCount(){
    return weights.size();
}

// multiply current neuron value by all weights of this neuron and return it as a vector
vector<double> Neuron::getNeuronOutput(){
    //test currentValue
    double currentValue = 1.0;
    vector<double> output;
    for(double weight: weights){
        output.push_back(weight*currentValue);
    }
    return output;
}

vector<double> Neuron::activate(vector<double> z){
    vector<double> outputVec = activationFunction(z);
    return outputVec;
}

void Neuron::setActivation(vector<double> (*func)(vector<double>))
{
    activationFunction = func;
}

void Neuron::setInput(double newInput){
    this->value=newInput;
}

void Neuron::setValue(double newInput){
    this->value=newInput;
}

// apply our function to the neuron's input
void Neuron::calculate(vector<double> inputs, int position){
    this->value=activationFunction(inputs).at(position);
}

void Neuron::setWeightLength(int length){
    this->weights.clear();
    for(int i=0; i<length; i++){
        this->weights.push_back(1.0);
    }
}








