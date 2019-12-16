#ifndef NEURALNET_H
#define NEURALNET_H
#include <neuron.h>
#include <ActivationFunctions.h>
#include <QtMath>

#include <QDirIterator>
#include <QtDebug>

class NeuralNet
{
public:
    /* Constructor 'NeuralNet' accepts a topology, which is a vector filled with <int, function> pairs, which is
     * where the function must take a vector<double> as input and also return a vector<double>.
     * Every pair represents a layer in the neural network, where the first part of the pair is the amount of neurons in
     * that layer and the second part is the activation function used by the neurons in that layer.
     * The first pair in the vector of pairs represents the input layer, the last pait represents the output layer and
     * every pair inbetween represents a hidden layer.
     */
    NeuralNet(vector< pair <int, double (*)(double, double)>> topology);

    /* Contains the structure of the neural net. Every element of the outer vector is represents a layer
     * and every element of the inner vector (vector of neurons) represents a neuron in the layer. */
    vector<vector<Neuron>> net;

    /* Amount of files to load in one batch. Used by the 'loadBatch' function. */
    int batchSize = 10;

    /* NOT IMPLEMENTED */
    vector<double> activateLayer(vector<Neuron>& layer);

    /* Generates random weights. */
    double randWeight();

    /* Loads training data into the 'trainingData' vector. */
    void loadBatch();

    /* Feeds the input layer of the neural net with first entry of 'training data'. */
    // ??? Maybe delete the entry as well, .clear() in loadBatach would not be needed ???
    void feedInput();

    //it takes a vector with target values ad changes the weights
    void backProp(const vector<double> &targetVals);

private:
    /* Adds a vector of neurons, representing a layer in a neural net, to the 'net' vector. Sets each neuron's
    activation function to 'func'. */
    void addLayer(int neurons, double (*func)(double, double));

    /* Contains current batch of training data. */
    QStringList trainingData;

    /* Directory iterator for iterating over training files. */
    QDirIterator* dirIterator = new QDirIterator("C:/Users/Filip/Desktop/dataset_half/nqgp", QDir::Files);

    //to calcutate the overall error
    double m_error;
    double m_recentAverageError;
    double m_recentAverageSmoothingFactor;



};

#endif // NEURALNET_H
