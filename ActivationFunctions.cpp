#include <ActivationFunctions.h>
namespace afunc {

    double calcDenominator(vector<double> z) {
        double denominator = 0;
        for (double i : z){
            denominator += exp(i);
        }
        return denominator
    }

    double softmax(double x, double denominator){
            return exp(x) / denominator;
    }

    double softmaxDeriv(double x, double denominator){
        double S = softmax(x, denominator);
            return S*(1 - S);
    }

    vector<double> lRelu(vector<double> z){
        vector<double> outputVec;
        for (double i : z){
            outputVec.push_back(max(0.1*i, i));
        }
        return outputVec;
    }

    vector<double> lReluDeriv(vector<double> z){
        vector<double> outputVec;

        for(double i : z){
            if(i >= 0){
                outputVec.push_back(1);
            } else {
                outputVec.push_back(0.01);
            }
        }
        return outputVec;
    }
}
