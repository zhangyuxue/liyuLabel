#include "polygonresizehandles.h"

namespace kImageAnnotator {

PolygonResizeHandles::PolygonResizeHandles(AbstractAnnotationPolygon *rectItem)
{
    mRolygonItem = rectItem;
    initHandles(mRolygonItem->polygon().size());
    initCursors();
    update();
}

void PolygonResizeHandles::update()
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

void PolygonResizeHandles::initCursors()
{
    mCursors.clear();
    auto polygon = mRolygonItem->polygon();
    for (int i=0;i<polygon.size();i++) {
        mCursors.append(CursorHelper::allResizeCursor());
    }
}

QRectF PolygonResizeHandles::getRect() const
{
    return mRolygonItem->rect();
}

int PolygonResizeHandles::getOffset() const
{
    return mRolygonItem->properties()->Width() / 2;
}

QRectF PolygonResizeHandles::getItemBoundingRect() const
{
    return mRolygonItem->rect().normalized();
}

} // namespace kImageAnnotator
