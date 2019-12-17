#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> plot ->addGraph();

}
void MainWindow ::makePlot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plot->xAxis->setRange(-1, 1);
    ui->plot->yAxis->setRange(0, 1);
    ui->plot->replot();


}
MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::on_spinBox_valueChanged(int arg1)
{

}*/



void MainWindow::on_pushButton_clicked()
{
    QString importFilePath = QFileDialog::getOpenFileName(this, tr("Open Text file"), "/home", tr("Text files (*.txt)"));
    // QMessageBox::information(this, "mytitle", importFilePath);
    QFile importFile(importFilePath);
}
