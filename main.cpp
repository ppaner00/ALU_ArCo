#include "aluwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ALUWindow w;
    w.show();
    printf("hola mundo");
    return a.exec();
}
