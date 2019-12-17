#include <ActivationFunctions.h>
namespace afunc {

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

    double lRelu(double i){
        return max(0.1*i, i);
    }

    double lReluDeriv(double i){
        if(i >= 0){
            return 1;
        } else {
            return 0;
        }
    }

    double fast_sigmoid(double x){
        return 1 / (1 + exp(-x));
    }

    double fast_sigmoid_deriv(double x){
        double S = fast_sigmoid(x);
        return S*(1 - S);
    }
/*
    double lRelu_at_index(vector<double> z, int index){
            double output = lRelu(z).at(index);
            return output;
    }

    double lReluDeriv(vector<double> z){
        vector<double> outputVec;

        for(double i : z){
            if(i >= 0){
                outputVec.push_back(1);
            } else {
                outputVec.push_back(0.01);
            }
        }
        return outputVec.at(0);
    }*/
}
