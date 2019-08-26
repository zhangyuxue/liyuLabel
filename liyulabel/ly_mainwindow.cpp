#include "ly_mainwindow.h"
#include "ui_ly_mainwindow.h"

ly_MainWindow::ly_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ly_MainWindow)
{
    ui->setupUi(this);
}

ly_MainWindow::~ly_MainWindow()
{
    delete ui;
}
