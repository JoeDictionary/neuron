#include "neuron.h"
#include <QCoreApplication>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

Neuron::Neuron(vector<double> (*func)())
{
    activationFunction = func;
}

double& Neuron::weightRef(int index){
        return weights[index];
    }

vector<double>& Neuron::weightsRef(){
        return weights;
    }

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
