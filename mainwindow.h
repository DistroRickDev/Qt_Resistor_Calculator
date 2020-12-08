#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "resistorcalc.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString res_color[10] = {"Preto(0)", "Castanho(1)", "Vermelho(2)", "Laranja(3)", "Amarelo(4)", "Verde(5)", "Azul(6)", "Violeta(7)", "Cinza(8)", "Branco(9)"};
    float tolerance[8] = {0.05, 0.1, 0.25, 0.5, 1, 2, 5, 10};
    QColor colors[10] = {QColor(Qt::black), QColor(92,64,51), QColor(Qt::red), QColor(255,153,0), QColor(Qt::yellow), QColor(Qt::green), QColor(Qt::blue), QColor(53,28,117), QColor(Qt::gray), QColor(Qt::white)};

    void fillComboBox();
    void setFinalResult();

private slots:
    void on_Calc_Button_clicked();
};
#endif // MAINWINDOW_H
