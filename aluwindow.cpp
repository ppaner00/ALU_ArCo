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

