#ifndef AnnotationNumberGroup_H
#define AnnotationNumberGroup_H

#include "abstractannotationNumberGroup.h"

namespace kImageAnnotator {

class AnnotationNumberGroup : public AbstractAnnotationNumberGroup
{
public:
    AnnotationNumberGroup(const QPointF &startPosition, AnnotationProperties *properties);
    AnnotationNumberGroup(const AnnotationNumberGroup &other);
    ~AnnotationNumberGroup() override = default;
    ToolTypes toolType() const override;

protected:
    void updateShape() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

}

#endif // AnnotationNumberGroupLINE_H
