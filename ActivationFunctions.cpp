#include <ActivationFunctions.h>
namespace afunc {/*
    double softmax(vector<double> z){
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
            return outputVec.at(0);
    }

    double softmax_at_index(vector<double> z, int index){
            double output = softmax(z).at(index);
            return output;
    }

    double softmaxDeriv(vector<double> z){
            vector<double> outputVec;
            double softmaxVec = softmax(z);
            for (double i : softmaxVec){
                outputVec.push_back(i * (1 - i));
            }
            return outputVec.at(0);
    }*/

    double lRelu(double i){
        return max(0.1*i, i);
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
