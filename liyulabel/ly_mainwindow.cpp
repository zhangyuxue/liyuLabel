#include "ly_mainwindow.h"
#include "ui_ly_mainwindow.h"

ly_MainWindow::ly_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ly_MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("鲤鱼标注"));
    m_factory = new ly_Factory(ui->centralWidget);
    this->setCentralWidget(m_factory);

    connect(m_factory,&ly_Factory::facotryPic,this,&ly_MainWindow::facotryPic);

}

ly_MainWindow::~ly_MainWindow()
{
    delete ui;
}

void ly_MainWindow::facotryPic()
{
    m_picAn=new ly_PicAnnotation(this);
    this->setCentralWidget(m_picAn);
}
