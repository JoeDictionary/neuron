#include <QCoreApplication>
#include <vector>
#include <math.h>
#include <iostream>
#include <neuron.h>
#include <neuralnet.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Neuron myNeuron;

    vector<double> inputVec = {-1, 0, 5, 10};

    vector<double> outputVec = myNeuron.softmaxDeriv(inputVec);
    for (double i : outputVec){
        cout << i << endl;
    }

    return a.exec();

}
