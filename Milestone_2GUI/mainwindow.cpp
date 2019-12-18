#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("FC NN without hidden layer");
    ui->comboBox->addItem("FC NN with 1 hidden layer");
    ui->comboBox->addItem("FC NN with 2 hidden layer");
    ui->comboBox->addItem("FC NN with 3 hidden layer");

    ui->comboBox_2->addItem("Training/test");
    ui->comboBox_2->addItem("Loss Rate");






    ui-> plot ->addGraph();

}
void MainWindow ::makePlot()
{
    // generate some data:
    QVector<double> x(10), y(10); // initialize with entries 0..100
    for (int i=0; i<10; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = pow(i,2); // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plot->xAxis->setRange(-10, 10);
    ui->plot->yAxis->setRange(-10, 10);
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





void MainWindow::on_pushButton_2_clicked()
{
    makePlot();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
     ui->plot->xAxis->setLabel(arg1);
     ui->plot->replot();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->plot->yAxis->setLabel(arg1);
    ui->plot->replot();
}
