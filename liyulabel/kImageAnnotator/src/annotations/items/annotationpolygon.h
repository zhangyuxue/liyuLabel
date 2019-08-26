#ifndef ANNOTATIONPOLYGON_H
#define ANNOTATIONPOLYGON_H

#include "abstractannotationpolygon.h"

namespace kImageAnnotator {

class AnnotationPolygon : public AbstractAnnotationPolygon
{
public:
    AnnotationPolygon(const QPointF &startPosition, AnnotationProperties *properties);
    AnnotationPolygon(const AnnotationPolygon &other);
    ~AnnotationPolygon() override = default;
    ToolTypes toolType() const override;

protected:
    void updateShape() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

}

#endif // ANNOTATIONPOLYGONLINE_H
