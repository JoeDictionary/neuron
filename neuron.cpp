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
/*
vector<double> Neuron::softmax(vector<double> z){
        vector<double> outputVec;
        vector<double> numerators;
        double denominator = 0;

        for(double i : z){
            double power = exp(i);
            denominator += power;
            numerators.push_back(power);
        }

        for (double i : numerators) {
            outputVec.push_back(i / denominator);
        }
        return outputVec;
    }

vector<double> Neuron::softmaxDeriv(vector<double> z){
        vector<double> outputVec;
        vector<double> softmaxVec = softmax(z);
        for (double i : softmaxVec){
            outputVec.push_back(i * (1 - i));
        }
        return outputVec;
    }

vector<double> Neuron::lRelu(vector<double> z){
    vector<double> outputVec;
    for (double i : z){
        outputVec.push_back(max(0.1*i, i));
    }
    return outputVec;
}


vector<double> Neuron::lReluDeriv(vector<double> z){
    vector<double> outputVec;

    for(double i : z){
        if(i >= 0){
            outputVec.push_back(1);
        } else {
            outputVec.push_back(0.01);
        }
    }
}
*/

vector<double> Neuron::activate(vector<double> z){
    vector<double> outputVec = activationFunction(z);
    return outputVec;
}

void Neuron::setActivation(vector<double> (*func)(vector<double>))
{
    activationFunction = func;
}










