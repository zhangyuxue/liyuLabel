#ifndef LY_GRAPHICVIEW_H
#define LY_GRAPHICVIEW_H

#include <QGraphicsView>

class ly_GraphicView:public QGraphicsView
{
public:
    ly_GraphicView(QGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
};

#endif // LY_GRAPHICVIEW_H
