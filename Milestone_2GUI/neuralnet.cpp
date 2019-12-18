#include "neuralnet.h"

NeuralNet::NeuralNet(vector< pair <int, double (*)(double, double)> > topology)
{
    /* Fills the 'net' vector with vectors<Neuron> to represent a neural network. */
    for(pair <int, double (*)(double, double)> i : topology){
        addLayer(i.first, i.second);
    }
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

double NeuralNet::randWeight()
{
// return rand()/double(RAND_MAX);}
}

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


