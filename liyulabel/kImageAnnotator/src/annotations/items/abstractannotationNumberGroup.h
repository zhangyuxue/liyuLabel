#ifndef AbstractAnnotationNumberGroup_H
#define AbstractAnnotationNumberGroup_H

#include "AbstractAnnotationItem.h"
#include "src/common/helper/MathHelper.h"

namespace kImageAnnotator {

class AbstractAnnotationNumberGroup : public AbstractAnnotationItem
{
public:
    AbstractAnnotationNumberGroup(const QPointF &startPosition, AnnotationProperties *properties);
    AbstractAnnotationNumberGroup(const AbstractAnnotationNumberGroup &other);
    ~AbstractAnnotationNumberGroup() override;
    QPolygonF polygon() const;
    void addPoint(const QPointF &position, bool modified);
    void setPosition(const QPointF &newPosition);
    void setPointAt(const QPointF &point, int index) override;
    QPointF pointAt(int index) const override;
    void scale(qreal sx, qreal sy) override;

    virtual int nearSharedPoints(QPointF point);
    virtual int pointIndex(QPointF &point);
    virtual QVector<QPointF> getPoints(int indexStart,int indexEnd);

    virtual void showAttachWidget(bool isShow);
    //virtual void attachWidget(TagChooseMainWdg* wdg);

protected:
    QPolygonF *mPolygon;
    int realptsNum=0;
};

} // namespace kImageAnnotator

#endif // AbstractAnnotationNumberGroupLINE_H
