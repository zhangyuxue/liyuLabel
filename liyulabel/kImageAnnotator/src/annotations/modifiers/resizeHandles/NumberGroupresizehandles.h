#ifndef NumberGroupResizeHandles_H
#define NumberGroupResizeHandles_H

#include "AbstractRectResizeHandles.h"
#include "src/annotations/items/abstractannotationNumberGroup.h"

namespace kImageAnnotator {

class NumberGroupResizeHandles : public AbstractRectResizeHandles
{
public:
    explicit NumberGroupResizeHandles(AbstractAnnotationNumberGroup *rectItem);
    ~NumberGroupResizeHandles() override = default;

    virtual void update() override;

protected:
    virtual void initCursors() override;
    QRectF getRect() const override;
    int getOffset() const override;
    QRectF getItemBoundingRect() const override;

private:
    AbstractAnnotationNumberGroup *mRolygonItem;
};

} // namespace kImageAnnotator
#endif // NumberGroupResizeHandles_H
