#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H
#include <vector>
#include <math.h>

using namespace std;


namespace afunc
{
    vector<double> softmax(vector<double> z);
    vector<double> softmaxDeriv(vector<double> z);
    vector<double> lRelu(vector<double> z);
    vector<double> lReluDeriv(vector<double> z);
}

#endif // ACTIVATIONFUNCTIONS_H
