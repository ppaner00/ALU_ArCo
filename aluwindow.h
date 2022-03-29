#ifndef ALUWINDOW_H
#define ALUWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ALUWindow; }
QT_END_NAMESPACE

class ALUWindow : public QMainWindow
{
    Q_OBJECT

public:
    ALUWindow(QWidget *parent = nullptr);
    ~ALUWindow();

private:
    Ui::ALUWindow *ui;
};
#endif // ALUWINDOW_H
