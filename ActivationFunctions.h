#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H
#include <vector>
#include <math.h>

using namespace std;


namespace afunc
{
    double softmax(double x, double denominator);
    double softmaxDeriv(double x, double denominator);
    double lRelu(double x);
    double lReluDeriv(double x);
}

#endif // ACTIVATIONFUNCTIONS_H
