#include "aluwindow.h"
#include "ui_aluwindow.h"


ALUWindow::ALUWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ALUWindow)
{
    ui->setupUi(this);
}

ALUWindow::~ALUWindow()
{
    delete ui;
}


void ALUWindow::on_Sumar_clicked()
{
    double sol = sumar();
    ui->SolReal->setText(QString::number(sol));
}


void ALUWindow::on_Multiplicar_clicked()
{

}


void ALUWindow::on_Dividir_clicked()
{

}


double ALUWindow::sumar(){
    double sumando1, sumando2, sol;
    sumando1 = ui->NumeroReal_1->toPlainText().toDouble();
    sumando2 = ui->NumeroReal_2->toPlainText().toDouble();
    sol = sumando1 + sumando2;
    return sol;
}

double ALUWindow::multiplicar(){
    double sumando1, sumando2, sol;
    sumando1 = ui->NumeroReal_1->toPlainText().toDouble();
    sumando2 = ui->NumeroReal_2->toPlainText().toDouble();
    sol = sumando1 * sumando2;
    return sol;
}

double ALUWindow::dividir(){
    double sumando1, sumando2, sol;
    sumando1 = ui->NumeroReal_1->toPlainText().toDouble();
    sumando2 = ui->NumeroReal_2->toPlainText().toDouble();
    sol = sumando1 / sumando2;
    return sol;
}

void ALUWindow::on_pushButton_clicked()
{
    QMessageBox mensaje;
    QString texto;
    texto.append("Manejar el ALU: \n");
    texto.append("Rellena los cuadros de texto de los operandos de los que quieras calcular la solución. \n");
    texto.append("Pulsa el botón de la operación que quieras realizar. \n");
    texto.append("La solución aparecera en un texto en la parte inferior de la ventana.");
    mensaje.setText(texto);
    mensaje.exec();
}

//  ---------------------------
//  TRANSFORMACIONES DE NUMEROS
//  ---------------------------

//  INotifyPropertyChanged o RaisePropertyChanged

//Cuando introduzcas un numero en Real que se rellenen automaticamente los de IEE y Hex

//REAL
void ALUWindow::on_NumeroReal_1_textChanged()
{
    double realToIEEE = ui->NumeroReal_1->toPlainText().toDouble();
    double realToHex =realToIEEE;

    realToIEEE = realToIEEE * 2; //Aqui hacemos la transformacion llamando a otro metodo
    realToHex = realToHex * 3;

    ui->NumeroIEEE_1->setText(QString::number(realToIEEE));
    ui->NumeroHex_1->setText(QString::number(realToHex));
}


void ALUWindow::on_NumeroReal_2_textChanged()
{
    double realToIEEE = ui->NumeroReal_2->toPlainText().toDouble();
    double realToHex =realToIEEE;

    realToIEEE = realToIEEE * 2; //Aqui hacemos la transformacion llamando a otro metodo
    realToHex = realToHex * 3;

    ui->NumeroIEEE_2->setText(QString::number(realToIEEE));
    ui->NumeroHex_2->setText(QString::number(realToHex));
}




//IEEE
void ALUWindow::on_NumeroIEEE_1_textChanged()
{
//    double IEEEToReal = ui->NumeroIEEE_1->toPlainText().toDouble();
//    double IEEEToHex =IEEEToReal;

//    IEEEToReal = IEEEToReal * 2; //Aqui hacemos la transformacion llamando a otro metodo
//    IEEEToHex = IEEEToHex * 3;

//    ui->NumeroReal_1->setText(QString::number(IEEEToReal));
//    ui->NumeroHex_1->setText(QString::number(IEEEToHex));
}


void ALUWindow::on_NumeroIEEE_2_textChanged()
{

}


void ALUWindow::on_NumeroHex_1_textChanged()
{

}


void ALUWindow::on_NumeroHex_2_textChanged()
{

}


void ALUWindow::on_cerrar_clicked()
{
    this->close();
}

