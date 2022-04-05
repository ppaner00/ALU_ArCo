#include "aluwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ALUWindow w;
    w.show();
    return a.exec();
}


/* Cosas por hacer:
 * IEEE suma sin signo
 * IEEE multiplicacion
 * IEEE division con signo
 *  Sin signo
 *
 * IEEE suma    Todos
 * Real a IEEE  Edu
 * IEEE a real  David
 * IEEE a hex   Pablo
*/
