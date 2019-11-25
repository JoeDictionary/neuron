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
    double softmax_at_index(vector<double>, int);
    double lRelu_at_index(vector<double>, int);
}

#endif // ACTIVATIONFUNCTIONS_H
