#include "mainwindow.h"
#include <neuralnet.h>
#include <ActivationFunctions.h>
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();    

    // Example Neural-Net Topology
    vector<pair <int, double (*)(double, double)>> topology = {
    pair <int, double (*)(double, double)> (224000, afunc::lRelu),
    pair <int, double (*)(double, double)> (5, afunc::lRelu),
    pair <int, double (*)(double, double)> (3, afunc::lRelu),
    pair <int, double (*)(double, double)> (2, afunc::lRelu)};

    NeuralNet myNet(topology);
    myNet.setQgpDir("C:/Users/Filip/Desktop/dataset_half/qgp");

    myNet.loadBatch(true);
    myNet.feedInput();

    return a.exec();
}
