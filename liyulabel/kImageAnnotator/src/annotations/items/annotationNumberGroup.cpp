#include "AnnotationNumberGroup.h"
#include <QPainter>

namespace kImageAnnotator {

AnnotationNumberGroup::AnnotationNumberGroup(const QPointF &startPosition, AnnotationProperties *properties) : AbstractAnnotationNumberGroup(startPosition, properties)
{
}

AnnotationNumberGroup::AnnotationNumberGroup(const AnnotationNumberGroup &other) : AbstractAnnotationNumberGroup(other)
{

}

ToolTypes AnnotationNumberGroup::toolType() const
{
    return ToolTypes::NumberGroup;
}

void AnnotationNumberGroup::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    shiftPainterForAllOddShapeWidth(painter);

    painter->setRenderHint(QPainter::Antialiasing, true);
    if (hasBorder()) {
        painter->setPen(mPainterPen);
    } else {
        painter->setPen(Qt::NoPen);
    }

    //if (hasFill()) {
        painter->setBrush(mProperties->color());
    //}
    //painter->drawPath(*mShape);
    //painter->drawPolygon(*mPolygon);


        for (int i=0;i<mPolygon->size();i++) {
            QRect pointrect;
            pointrect.setRect(mPolygon->at(i).x()-3.0,mPolygon->at(i).y()-3.0,6,6);
            painter->drawEllipse(pointrect);
            //painter->drawText(pointrect, Qt::AlignCenter, QString::number(i));
            painter->drawText(pointrect.center().x(),pointrect.center().y()+15, QString::number(i));
        }

}

void AnnotationNumberGroup::updateShape()
{
    QPainterPath path;

    path.addPolygon(*mPolygon);



    setShape(path);
    update();
}

} // namespace kImageAnnotator
