#include "neuron.h"
#include <QCoreApplication>
#include <iostream>
using namespace std;

// 1a)

Neuron::Neuron(double (*func)(double, double))
{
    activationFunction = func;
}

double& Neuron::weightRef(int index){
        return weights[index];
    }

vector<double>& Neuron::weightsRef(){
        return weights;
    }

double Neuron::activate(double x, double denominator){
    return activationFunction(x, denominator);
}

void Neuron::setActivation(double (*func)(double, double))
{
    activationFunction = func;
}

double Neuron::getOutputGrad(int target)
{
    return (target - softmax(currentVal, calcDenominator(net[net.size()-1]))) * softmaxDeriv(currentVal, calcDenominator(net[net.size()-1]));
}

double Neuron::getHiddenGrad(int target, int indexOfLayer, int indexOfNeuron)
{
    double grad = 0;
    for (int i = 0; i < net[indexOfLayer-1].size(); i++){
        grad = grad + (target - lrelu(currentVal.net[indexOfLayer - 1][i]) * lreluDeriv(currentVal.net[indexOfLayer - 1][i])) * weights[i to indexOfNeuron];
    }
    return grad * lrelu(currentVal.net[indexOfLayer][indexOfNeuron]);
}











