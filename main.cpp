#include <QCoreApplication>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class Neuron
{
public:
    Neuron(vector<double> (*func)()){
        activationFunction = func;
    }

    double &weightRef(int index){
        return weights[index];
    }

    vector<double> &weightsRef(){
        return weights;
    }

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

    vector<double> softmaxDeriv(vector<double> z){
        vector<double> outputVec;
        vector<double> softmaxVec = softmax(z);
        for (double i : softmaxVec){
            outputVec.push_back(i * (1 - i));
        }
        return outputVec;
    }

private:
    /* Vector of weights on connections to the next layer, also means the amount of neurons in the next
     * layer if in a connected neural network. The first weight corresponds to the first neuron of the next layer
     * and so forth.
     */
    vector<double> weights;
    /* Pointer to the activation function set by the constructor.*/
    vector<double> (*activationFunction)();

};

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
