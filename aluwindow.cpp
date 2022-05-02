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
    double sol = multiplicar();
    ui->SolReal->setText(QString::number(sol));
}


void ALUWindow::on_Dividir_clicked()
{
    double sol = dividir();
    ui->SolReal->setText(QString::number(sol));
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

void ALUWindow::on_info_clicked()
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


//REAL
void ALUWindow::on_NumeroReal_1_textChanged()
{
    //long realToIEEE754 = ui->NumeroReal_1->toPlainText().toLong();
    //double realToHex =realToIEEE754;

    realToIEEE754(); //Aqui hacemos la transformacion llamando a otro metodo

    // realToHex = realToHex * 3;

    ui->NumeroIEEE_1->setText(realToIEEE754());
    //ui->NumeroHex_1->setText(QString::number(realToHex));
}


void ALUWindow::on_NumeroReal_2_textChanged()
{
//    double realToIEEE = ui->NumeroReal_2->toPlainText().toDouble();
//    double realToHex =realToIEEE;

    realToIEEE754();         //Aqui hacemos la transformacion llamando a otro metodo
//    realToHex = realToHex * 3;

    ui->NumeroIEEE_2->setText(realToIEEE754());
//    ui->NumeroHex_2->setText(QString::number(realToHex));
}

//  ---------------------------
//          ALGORITMOS
//  ---------------------------

QString ALUWindow::realToIEEE754(){
    long num = ui->NumeroReal_1->toPlainText().toLong();
    int parteFracc = 23;
    int contador = 0;
    int expo = 127;

    QString signo("");
    QString mantisa("");
    QString numBinario("");
    QString auxExpo("");
    QString P_fraccionaria("");
    QString numIEEE754("");

    if(num < 0){
        signo = "1";
    }else{
        signo = "0";
    }

    //pasamos el numero a binario
    while(true){
        numBinario = num % 2 ? "1" + numBinario : "0" + numBinario;
        num /= 2;

        if(num == 0){
            break;
        }
    }


    //rellenamos con ceros hasta tener 24 bits
    for(int i = numBinario.size() - 1;  i < parteFracc; i++){
        numBinario = numBinario + "0";
        contador++;
    }


    //sacamos el exponente
    for(int j = numBinario.size() - (contador + 1); j > 0; j--){
        expo++;
    }


    //Convertimos el exponente en binario
    while(true){
        auxExpo = (expo % 2) ? "1" + auxExpo: "0" + auxExpo;
        expo /= 2;

        if(expo == 0){
            break;
        }
    }


    //sacamos la parte fraccionaria
    for(int k = 1; k < 24; k++){
        P_fraccionaria = P_fraccionaria + numBinario[k];

    }


//    ui->size->setText(QString::number(numBinario.size()));
//    ui->mantisa->setText(QString(numBinario));
//    ui->mantisaSize->setText(QString::number((numBinario.size())));
//    ui->exponente->setText(QString(auxExpo));
//    ui->parteFracc->setText((P_fraccionaria));
//    ui->signo->setText(signo);
    numIEEE754 = signo + auxExpo + P_fraccionaria;
//    ui->NumeroIEEE_1->setText(numIEEE754);
    return numIEEE754;
}
