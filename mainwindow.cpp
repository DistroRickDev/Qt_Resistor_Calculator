#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Resistor Calculator"); //set the window title
    this->setFixedHeight(400); //has not a resible height
    this->setFixedWidth(400); //has not a resible width

    fillComboBox();

    setFinalResult();

    connect(ui->Calc_Button, &QPushButton::clicked,this, &MainWindow::on_Calc_Button_clicked);
};
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillComboBox()
{
    for(int i =0; i<10; i++)
    {
        ui->FirstRing->addItem(res_color[i]);
        ui->SecondRing->addItem(res_color[i]);
        ui->ThirdRing->addItem(res_color[i]);
    }
    for(int i =0; i<10; i++)
    {
        ui->FirstRing->setItemData(i, colors[i], Qt::BackgroundRole);
        ui->SecondRing->setItemData(i, colors[i], Qt::BackgroundRole);
        ui->ThirdRing->setItemData(i, colors[i], Qt::BackgroundRole);
    }
    ui->FirstRing->setItemData(0, colors[9], Qt::TextColorRole);
    ui->SecondRing->setItemData(0, colors[9], Qt::TextColorRole);
    ui->ThirdRing->setItemData(0, colors[9], Qt::TextColorRole);

    ui->FirstRing->setCurrentIndex(0);
    ui->SecondRing->setCurrentIndex(0);
    ui->ThirdRing->setCurrentIndex(0);


    for(int i =0; i<8; i++)
    {
        ui->Tolerance->addItem(QString::number(tolerance[i]));
    }
}

void MainWindow::setFinalResult()
{
    ResistorCalc resis_calc;
    QString final = resis_calc.calculateFinal((int)ui->FirstRing->currentIndex(), (int)ui->SecondRing->currentIndex(), (int)ui->ThirdRing->currentIndex(), tolerance[ui->Tolerance->currentIndex()]);
    qDebug() << final ;
    ui->Result_Label->setText(final);
}

void MainWindow::on_Calc_Button_clicked()
{
   // qDebug() << "Signal Triggered\n";
   setFinalResult();
}

