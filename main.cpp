#include <QCoreApplication>
#include <vector>
#include <math.h>
#include <iostream>
#include <neuron.h>
#include <neuralnet.h>
#include <ActivationFunctions.h>
using namespace std;

int printConfirm(int num){
    return num - 4;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Test Vector
    vector<double> inputVec = {-1, 0, 5, 10};

    // Vector of pairs for initializing a 'NeuralNet' object.
    vector< pair <int, double (*)(double)>> topologyVec = {
            pair<int, double (*)(double)> (10, afunc::lRelu),
            pair<int, double (*)(double)> (5, afunc::lRelu),
            pair<int, double (*)(double)> (5, afunc::lRelu),
            pair<int, double (*)(double)> (2, afunc::softmax)
};

    // Initialization of a 'NeuralNet' using previously defined 'topologyVec'.
    NeuralNet myNet(topologyVec);
    // Sizecheck to see if the net was created with the right amount of layers.
    cout << myNet.net.size() << endl;

    /*
    vector<vector<double> (*)(vector<double>)> funcVec;
    funcVec.push_back(afunc::lRelu);
    cout << "lRelu: " << (funcVec[0])(inputVec)[0] << endl;
    */

    return a.exec();
}
