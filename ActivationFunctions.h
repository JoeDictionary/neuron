#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H
#include <vector>
#include <math.h>

using namespace std;


namespace afunc
{
    double calcDenominator(vector<double> z);
    double softmax(double, double);
    double softmaxDeriv(double z);
    double lRelu(double);
    double lReluDeriv(double z);

    double fast_sigmoid(double);
    double fast_sigmoid_deriv(double);
    //double softmax_at_index(double, int);
    //double lRelu_at_index(double, int);
}

#endif // ACTIVATIONFUNCTIONS_H
