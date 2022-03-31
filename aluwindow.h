#ifndef ALUWINDOW_H
#define ALUWINDOW_H

#include <QMainWindow>
#include "QMessageBox"

QT_BEGIN_NAMESPACE
namespace Ui { class ALUWindow; }
QT_END_NAMESPACE

class ALUWindow : public QMainWindow
{
    Q_OBJECT

public:
    ALUWindow(QWidget *parent = nullptr);
    ~ALUWindow();

    double sumar();
    double multiplicar();
    double dividir();

private slots:
    void on_Sumar_clicked();

    void on_Multiplicar_clicked();

    void on_Dividir_clicked();

    void on_pushButton_clicked();

    void on_NumeroReal_1_textChanged();

    void on_NumeroReal_2_textChanged();

    void on_NumeroIEEE_1_textChanged();

    void on_NumeroIEEE_2_textChanged();

    void on_NumeroHex_1_textChanged();

    void on_NumeroHex_2_textChanged();

    void on_info_clicked();

private:
    Ui::ALUWindow *ui;
};
#endif // ALUWINDOW_H
