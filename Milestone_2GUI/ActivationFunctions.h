#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H
#include <vector>
#include <math.h>

using namespace std;


namespace afunc
{
    double calcDenominator(vector<double> z);
    double softmax(double x, double denominator);
    double softmaxDeriv(double x, double denominator);
    double lRelu(double x, double useless);
    double lReluDeriv(double x, double useless);
}

#endif // ACTIVATIONFUNCTIONS_H
