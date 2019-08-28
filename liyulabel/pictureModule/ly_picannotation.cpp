#include "ly_picannotation.h"
#include "ui_ly_picannotation.h"

ly_PicAnnotation::ly_PicAnnotation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ly_PicAnnotation)
{
    ui->setupUi(this);

    mConfig = new Config;
    mAnnotationArea = new AnnotationArea(mConfig);
    ui->verticalLayout_main->addWidget(mView = new ly_GraphicView(mAnnotationArea));

    mAnnotationArea->loadImage(QPixmap(":/resouce/picnull.png"));
}

ly_PicAnnotation::~ly_PicAnnotation()
{
    delete ui;
}

void ly_PicAnnotation::on_pushButton_pen_clicked()
{
    uncheckedTools();
    ui->pushButton_pen->setChecked(true);
    mConfig->setSelectedTool(ToolTypes::Pen);
}

void ly_PicAnnotation::on_pushButton_line_clicked()
{
    uncheckedTools();
    ui->pushButton_line->setChecked(true);
    mConfig->setSelectedTool(ToolTypes::Line);
}

void ly_PicAnnotation::on_pushButton_rect_clicked()
{
    uncheckedTools();
    ui->pushButton_rect->setChecked(true);
    mConfig->setSelectedTool(ToolTypes::Rect);
    mConfig->setToolFillType(FillTypes::BorderAndNoFill,ToolTypes::Rect);
}

void ly_PicAnnotation::on_pushButton_number_clicked()
{
    uncheckedTools();
    ui->pushButton_number->setChecked(true);
    mConfig->setSelectedTool(ToolTypes::Number);
}


void ly_PicAnnotation::uncheckedTools()
{
    ui->pushButton_line->setChecked(false);
    ui->pushButton_rect->setChecked(false);
    ui->pushButton_number->setChecked(false);
    ui->pushButton_pen->setChecked(false);
}
