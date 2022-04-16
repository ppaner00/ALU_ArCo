#ifndef ALUWINDOW_H
#define ALUWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <stdio.h>
#include <unistd.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ALUWindow; }
QT_END_NAMESPACE

class ALUWindow : public QMainWindow
{
    Q_OBJECT

public:
    ALUWindow(QWidget *parent = nullptr);
    ~ALUWindow();

    union Code{
        struct{
            unsigned int partFrac = 23;
            unsigned int exp = 8;
            unsigned int sign = 1;
        }bitfield;

        float num;
        unsigned int numAux;
    };

    double sumar();
    double multiplicar();
    double dividir();
    QString realToIEEE754();

private slots:
    void on_Sumar_clicked();

    void on_Multiplicar_clicked();

    void on_Dividir_clicked();

    void on_NumeroReal_1_textChanged();

    void on_NumeroReal_2_textChanged();

    void on_info_clicked();

private:
    Ui::ALUWindow *ui;
};
#endif // ALUWINDOW_H
