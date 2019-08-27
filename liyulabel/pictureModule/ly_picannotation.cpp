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
}

ly_PicAnnotation::~ly_PicAnnotation()
{
    delete ui;
}
