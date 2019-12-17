#include <ActivationFunctions.h>
namespace afunc {

    /* Calculates a neuron's input value for the activation function (from second layer (index: 1) on possible)*/
    double calcX(int indexOfLayer, int indexOfNeuron, vector<double> weights){
        double x = 0;
        for (int i = 0; i < net[indexOfLayer - 1].size(); i++ ){
            x = x + (weights[i to indexOfNeuron] * net[indexOfLayer - 1][i]);
             //! Wie werden die weights gespeichert
        }
        return x;
    }
    double calcDenominator(vector<double> z) {
        double denominator = 0;
        for (double i : z){
            denominator += exp(i);
        }
        return denominator;
    }

    double softmax(double x, double denominator){
        return exp(x) / denominator;
    }

    double softmaxDeriv(double x, double denominator){
        double S = softmax(x, denominator);
        return S*(1 - S);
    }

    double lRelu(double x, double useless){
        return max(0.1*x, x);
    }

    double lReluDeriv(double x, double useless){
            if(x >= 0){
                return 1;
            } else {
                return 0.01;
            }
    }

    double lossFunc(double result, double target) {
        return -log(abs(target - result));
    }
}
