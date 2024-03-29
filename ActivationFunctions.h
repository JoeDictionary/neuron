#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H
#include <vector>
#include <math.h>

using namespace std;


namespace afunc
{
    double calcX(int indexOfLayer, int indexOfNeuron, vector<double> weights);
    double calcDenominator(vector<double> z);
    double softmax(double x, double denominator);
    double softmaxDeriv(double x, double denominator);
    double lRelu(double x, double useless);
    double lReluDeriv(double x, double useless);
    double lossFunc(double result, double target);
}

#endif // ACTIVATIONFUNCTIONS_H
