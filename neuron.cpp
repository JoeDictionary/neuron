#include "neuron.h"
#include <QCoreApplication>
#include <iostream>
#include <random>
#include <ctime>

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

/* Calculates a neuron's input value for the activation function (from second layer (index: 1) on possible)*/
double Neuron::calcX(int ilayer, vector<double>& weights, vector<double> layer, int neuronAmt){
    double x = 0;
    for (int i = 0; i < neuronAmt; i++ ){
        x = x + weights[ilayer-1][i] * layer[ilayer-1][i];
         //! WIE WERDEN WEIGHTS GESPEICHERT, ilayer soll index von einem layer sein; Hab ich einen Denkfehler
     }
      return x;
}
/* 1d)
 * Calculates the output-gradient or hidden-gradient depending on which layer a neuron is. */
//! So wann ist mit f(x) softmax und wann lrelu gemeint
double Neuron::getGradient(int target, int ilayer, vector<double> prevLayer){
    // output-layer gradient
    double grad = 0;
    if (ilayer == layer.size()){ // if das ausgewöhlte Layer = letzes Layer
           grad = (target - softmax(currentVal, calcDenominator(layer[ilayer]))) * softmaxDeriv(currentVal, calcDenominator(layer[ilayer]));
        }
    // hidden-layer gradient
    else {
        for (int i = 0; i < prevLayer.size(); i++){
            grad = grad + (target - lrelu(layer[ilayer-1][i]) * lreluDeriv(layer[ilayer-1][i])) * weight;
        }
        grad = grad * lrelu(layer[ilayer]);
    }
    return grad;
}

void assignRandomWeights(double PrevLayerAmt){
    for (int i = 0; i < LayerAmt; i++){
        for (int j = 0; j < PrevLayerAmt; j++){
            weights[i].push_back(randWeight(PrevLayerAmt));
        }
    }
}










