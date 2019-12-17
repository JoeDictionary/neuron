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
/*    vector< pair <int, double (*)(double)> > topologyVec = {
            pair<int, double (*)(double)>(10, afunc::lRelu),
            pair<int, double (*)(double)>(5, afunc::lRelu),
            pair<int, double (*)(double)>(5, afunc::lRelu),
            pair<int, double (*)(double)>(10, afunc::lRelu),
};*/

    vector< pair <int, double (*)(double)> > topologyVec = {
            pair<int, double (*)(double)>(10, afunc::lRelu),
            pair<int, double (*)(double)>(2, afunc::lRelu),
};

    // Initialization of a 'NeuralNet' using previously defined 'topologyVec'.
    NeuralNet myNet(topologyVec);
    // Sizecheck to see if the net was created with the right amount of layers.
    //cout << myNet.net.size() << endl;

    vector<double> input;
    input.push_back(1.0);
    input.push_back(2.0);
    input.push_back(3.0);
    input.push_back(4.0);
    input.push_back(5.0);
    input.push_back(6.0);
    input.push_back(7.0);
    input.push_back(8);
    input.push_back(9.0);
    input.push_back(10.0);

    myNet.setupNeuralNetwork();

    myNet.print();

    myNet.getOutputFromInput(input);

    myNet.print();

    vector<double> targetOutput;
    targetOutput.push_back(1);
    targetOutput.push_back(0);

    myNet.backPropagate(targetOutput, 1);

    myNet.print();

    for(int i=0; i<100; i++){
    myNet.getOutputFromInput(input);
    myNet.backPropagate(targetOutput, 1);

    myNet.getOutputFromInput(input);
    myNet.backPropagate(targetOutput, 1);

    myNet.getOutputFromInput(input);
    myNet.backPropagate(targetOutput, 1);
}

    myNet.getOutputFromInput(input);

    myNet.print();

    /*
    vector<vector<double> (*)(vector<double>)> funcVec;
    funcVec.push_back(afunc::lRelu);
    cout << "lRelu: " << (funcVec[0])(inputVec)[0] << endl;
    */

    return a.exec();
}
