#include "NumberGroupresizehandles.h"

namespace kImageAnnotator {

NumberGroupResizeHandles::NumberGroupResizeHandles(AbstractAnnotationNumberGroup *rectItem)
{
    mRolygonItem = rectItem;
    initHandles(mRolygonItem->polygon().size());
    initCursors();
    update();
}

void NumberGroupResizeHandles::update()
{
    auto polygon = mRolygonItem->polygon();
    //auto offset = mRolygonItem->properties()->Width();
    //auto outerLine = ShapeHelper::extendLine(line, offset);
    for (int i=0;i<polygon.size();i++) {
        QPointF pt = polygon.at(i);
        mHandles[i].moveCenter(pt);
        mHandles[i].setAnchor(pt);
    }
}

void NumberGroupResizeHandles::initCursors()
{
    mCursors.clear();
    auto polygon = mRolygonItem->polygon();
    for (int i=0;i<polygon.size();i++) {
        mCursors.append(CursorHelper::allResizeCursor());
    }
}

QRectF NumberGroupResizeHandles::getRect() const
{
    return mRolygonItem->rect();
}

int NumberGroupResizeHandles::getOffset() const
{
    return mRolygonItem->properties()->Width() / 2;
}

QRectF NumberGroupResizeHandles::getItemBoundingRect() const
{
    return mRolygonItem->rect().normalized();
}

} // namespace kImageAnnotator
