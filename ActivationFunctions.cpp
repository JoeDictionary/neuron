#include <ActivationFunctions.h>
namespace afunc {

// 1b)
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
}
