#ifndef ABSTRACTANNOTATIONPOLYGON_H
#define ABSTRACTANNOTATIONPOLYGON_H

#include "AbstractAnnotationItem.h"
#include "src/common/helper/MathHelper.h"

namespace kImageAnnotator {

class AbstractAnnotationPolygon : public AbstractAnnotationItem
{
public:
    AbstractAnnotationPolygon(const QPointF &startPosition, AnnotationProperties *properties);
    AbstractAnnotationPolygon(const AbstractAnnotationPolygon &other);
    ~AbstractAnnotationPolygon() override;
    QPolygonF polygon() const;
    void addPoint(const QPointF &position, bool modified);
    void setPosition(const QPointF &newPosition);
    void setPointAt(const QPointF &point, int index) override;
    QPointF pointAt(int index) const override;
    void scale(qreal sx, qreal sy) override;

    virtual int nearSharedPoints(QPointF point);
    virtual int pointIndex(QPointF &point);
    virtual QVector<QPointF> getPoints(int indexStart,int indexEnd);

protected:
    QPolygonF *mPolygon;
    int realptsNum=0;
};

} // namespace kImageAnnotator

#endif // ABSTRACTANNOTATIONPOLYGONLINE_H
