#include "neuron.h"
#include <QCoreApplication>
#include <iostream>
using namespace std;


Neuron::Neuron(vector<double> (*func)(vector<double>))
{
    activationFunction = func;
}

double& Neuron::weightRef(int index){
        return weights[index];
    }

vector<double>& Neuron::weightsRef(){
        return weights;
    }

vector<double> Neuron::activate(vector<double> z){
    vector<double> outputVec = activationFunction(z);
    return outputVec;
}

void Neuron::setActivation(vector<double> (*func)(vector<double>))
{
    activationFunction = func;
}










