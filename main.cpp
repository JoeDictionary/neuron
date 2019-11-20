#include <QCoreApplication>
#include <vector>
#include <math.h>
#include <iostream>
#include <neuron.h>
#include <neuralnet.h>
using namespace std;

vector<double> softmax(vector<double> z){
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
        return outputVec;
    }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Neuron myNeuron(softmax);
    vector<double> inputVec = {-1, 0, 5, 10};

    vector<double> outputVec = myNeuron.activate(inputVec);
    for (double i : outputVec){
        cout << i << endl;
    }

    return a.exec();

}
