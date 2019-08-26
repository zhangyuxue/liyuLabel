#ifndef POLYGONRESIZEHANDLES_H
#define POLYGONRESIZEHANDLES_H

#include "AbstractRectResizeHandles.h"
#include "src/annotations/items/abstractannotationpolygon.h"

namespace kImageAnnotator {

class PolygonResizeHandles : public AbstractRectResizeHandles
{
public:
    explicit PolygonResizeHandles(AbstractAnnotationPolygon *rectItem);
    ~PolygonResizeHandles() override = default;

    virtual void update() override;

protected:
    virtual void initCursors() override;
    QRectF getRect() const override;
    int getOffset() const override;
    QRectF getItemBoundingRect() const override;

private:
    AbstractAnnotationPolygon *mRolygonItem;
};

} // namespace kImageAnnotator
#endif // POLYGONRESIZEHANDLES_H
