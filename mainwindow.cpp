#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    variables = new Variables();
    serialPorts = new SerialPorts();
    timer = new QTimer(this);
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete variables;
    delete serialPorts;
    delete timer;
}

void MainWindow::tick()
{

}
