#include "ly_factory.h"
#include "ui_ly_factory.h"

ly_Factory::ly_Factory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ly_Factory)
{
    ui->setupUi(this);
}

ly_Factory::~ly_Factory()
{
    delete ui;
}

void ly_Factory::on_pushButton_pic_clicked()
{
    emit facotryPic();
}
