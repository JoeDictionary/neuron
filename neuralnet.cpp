#include "neuralnet.h"
#include <ctime>
#include <cstdlib>

NeuralNet::NeuralNet(vector< pair <int, double (*)(double, double)> > netTopology)
{
    /* Fills the 'net' vector with vectors<Neuron> to represent a neural network. */
    for(pair <int, double (*)(double, double)> i : netTopology){
        addLayer(i.first, i.second);  //first is list of values of layer i and second is activation function for layer i
    }
    topology = netTopology;
}

void NeuralNet::addLayer(int neuronAmt, double (*func)(double, double))
{
    vector<Neuron> layer;
    for (int i = 0; i < neuronAmt; i++){
        Neuron p(func);
        layer.push_back(p);
    }
    net.push_back(layer);
}

vector<double> NeuralNet::activateLayer(vector<Neuron>& layer)
{
    /*
    vector<double> (*aFunc)(vector<double>) = layer[0].activationFunction;
    vector<double> rawLayer;
    vector<double> activatedLayer;

    // Fill 'rawLayer' with not activated values from the 'layer' neurons.
    for (Neuron i : layer){
        rawLayer.push_back(i.containedValue);
    }

    activatedLayer = aFunc(rawLayer);

    for (int i = 0; i < activatedLayer.size(); i++) {
        (layer[i]).containedValue = activatedLayer[i];
    }
    */
}

/* Calculates a weight for a neuron for the weights initialization */
double NeuralNet::randWeight(double prevLayerAmt)
{
    double randNum = ((double)rand() / ((double)RAND_MAX));
    return (randNum * sqrt(2./prevLayerAmt));
}

/* Initializes the weights in the neural network (from every neuron to every neuron in the next layer) */
void NeuralNet::initRandomWeights(vector<double> &weights)
{
    srand(time(0));
    for (int i = 0; i < net.size() - 1; i++){  // i is a layer; last layer does not have weights to another layer
        for (int j = 0; j < net[i].size(); j++){  // j is a neuron in layer i
            for (int k; k < net[i+1].size(); k++){  // k is a neuron in the layer i+1
                //weights[j to k] = randWeight(double(net[i].size())); // net[i].size() as the amount of neurons of previous layer
            //! War mir nicht sicher wie ich die weights hier speichere; jedenfalls soll der weight von neuron j zu neuron k gespeichert werden
            }
        }
    }
}

/* Loads batch into training data */
void NeuralNet::loadBatch()
{
    // Clears 'trainingData' list from already used data.
    trainingData.clear();

    for(int i=0;i < batchSize; i++){
        QFile file(dirIterator->next());
        qDebug() << dirIterator->fileName();
        file.open(QIODevice::ReadOnly);
        trainingData.append(file.readAll());
    }
    qDebug() << "(loadBatch) Next Batch Loaded!";
}

void NeuralNet::feedInput()
{
    QList<int> processedData;

    // Splits first entry in string in 'trainingData' into strings of single digits, converts these to integers and appends them to 'processed' data.
    for(QString i : trainingData[0].split(QRegExp("\\s+"), QString::SkipEmptyParts)) {
        processedData.append(i.toInt());
    }

    // Sets every neuron's 'currentVal' in the input layer to the corresponding datapoint in 'processedData'.
    for(int i = 0; net[0].size(); i++) {
        net[0][i].currentVal = processedData[i];
    }
}

/* Returns the 2 values of the output layer neurons as a pair */
pair<double, double> NeuralNet::readOutput()
{
    int netSize = net.size();
    return pair<double, double> (net[netSize - 1][0].currentVal, net[netSize - 1][1].currentVal);
}





