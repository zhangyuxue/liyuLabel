#ifndef LY_PICANNOTATION_H
#define LY_PICANNOTATION_H

#include <QWidget>
#include "Config.h"
#include "AnnotationArea.h"
#include "ly_graphicview.h"
using namespace kImageAnnotator;

namespace Ui {
class ly_PicAnnotation;
}

class ly_PicAnnotation : public QWidget
{
    Q_OBJECT

public:
    explicit ly_PicAnnotation(QWidget *parent = 0);
    ~ly_PicAnnotation();

public slots:
    void on_pushButton_pen_clicked();
    void on_pushButton_line_clicked();
    void on_pushButton_rect_clicked();
    void on_pushButton_number_clicked();
private:
    void uncheckedTools();
protected:
    Config* mConfig = nullptr ;
    AnnotationArea* mAnnotationArea = nullptr;
    ly_GraphicView* mView = nullptr;
private:
    Ui::ly_PicAnnotation *ui;
};

#endif // LY_PICANNOTATION_H
