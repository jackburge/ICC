#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serialPorts.h"
#include "variables.h"
#include "mythread.h"
#include <QTimer>
#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void tick();

private:
    Ui::MainWindow *ui;
    SerialPorts *serialPorts;
    QTimer *timer;
};

#endif // MAINWINDOW_H
