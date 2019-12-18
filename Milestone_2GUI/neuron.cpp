#include "neuron.h"
#include <QCoreApplication>
#include <iostream>
using namespace std;

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









