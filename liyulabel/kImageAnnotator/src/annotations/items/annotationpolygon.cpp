#include "annotationpolygon.h"
#include <QPainter>

namespace kImageAnnotator {

AnnotationPolygon::AnnotationPolygon(const QPointF &startPosition, AnnotationProperties *properties) : AbstractAnnotationPolygon(startPosition, properties)
{
}

AnnotationPolygon::AnnotationPolygon(const AnnotationPolygon &other) : AbstractAnnotationPolygon(other)
{

}

ToolTypes AnnotationPolygon::toolType() const
{
    return ToolTypes::Polygon;
}

void AnnotationPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    shiftPainterForAllOddShapeWidth(painter);

    painter->setRenderHint(QPainter::Antialiasing, true);
    if (hasBorder()) {
        painter->setPen(mPainterPen);
    } else {
        painter->setPen(Qt::NoPen);
    }

    if (hasFill()) {
        painter->setBrush(mProperties->color());
    }
    //painter->drawPath(*mShape);
    painter->drawPolygon(*mPolygon);

    if(isshared)
    {
        for (int i=0;i<mPolygon->size();i++) {
            painter->drawEllipse(mPolygon->at(i),5,5);
        }

    }

}

void AnnotationPolygon::updateShape()
{
    QPainterPath path;

    if(mPolygon->size()==2)
    {
        path = QPainterPath(mPolygon->first());
        path.lineTo(mPolygon->last());
    }
    else
    {
        path.addPolygon(*mPolygon);
    }


    setShape(path);
}

} // namespace kImageAnnotator
