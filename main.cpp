#include <QCoreApplication>
#include <vector>
#include <math.h>
#include <iostream>
#include <neuron.h>
#include <neuralnet.h>
#include <ActivationFunctions.h>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Neuron myNeuron;
    vector<double> inputVec = {-1, 0, 5, 10};

    vector<double> outputVec = myNeuron.activate(inputVec);
    for (double i : outputVec){
        cout << i << endl;
    }

    NeuralNet myNet({10, 4, 2});
    cout << "Hello, World!" << endl;
    cout << afunc::softmax(inputVec)[0] << endl;

    return a.exec();
}
