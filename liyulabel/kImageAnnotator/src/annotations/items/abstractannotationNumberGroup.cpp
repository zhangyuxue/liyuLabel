#include "AbstractAnnotationNumberGroup.h"
#include <QDebug>

namespace kImageAnnotator {

AbstractAnnotationNumberGroup::AbstractAnnotationNumberGroup(const QPointF &startPosition, AnnotationProperties *properties) : AbstractAnnotationItem(properties)
{
    mPolygon = new QPolygonF();
    //mPolygon->append(startPosition);
    realptsNum=mPolygon->size();
}

AbstractAnnotationNumberGroup::AbstractAnnotationNumberGroup(const AbstractAnnotationNumberGroup &other) : AbstractAnnotationItem(other)
{
    mPolygon = new QPolygonF(*other.mPolygon);
    realptsNum=mPolygon->size();
}

AbstractAnnotationNumberGroup::~AbstractAnnotationNumberGroup()
{
    delete mPolygon;
}

int AbstractAnnotationNumberGroup::nearSharedPoints(QPointF point)
{
    for (int i=0;i<mPolygon->size();i++) {
        QLineF line;
        line.setP1(point);
        line.setP2(mPolygon->at(i));
        if(line.length() <=5)
            return i;
    }
    return -1;
}

int AbstractAnnotationNumberGroup::pointIndex(QPointF &point)
{
    for (int i=0;i<mPolygon->size();i++) {
        if(mPolygon->at(i) == point)
            return i;
    }
    return -1;
}

QVector<QPointF> AbstractAnnotationNumberGroup::getPoints(int indexStart,int indexEnd)
{
    QVector<QPointF> points;
    for (int i=indexStart;i<indexEnd;i++) {
        qDebug()<<"Get points:"<<i<<"--------------"<<mPolygon->at(i);
       points.append(mPolygon->at(i));
    }
    return points;
}

QPolygonF AbstractAnnotationNumberGroup::polygon() const
{
    return *mPolygon;
}

void AbstractAnnotationNumberGroup::addPoint(const QPointF &position, bool modified)
{
    prepareGeometryChange();

    mPolygon->append(position);
    realptsNum++;
    updateShape();
}

void AbstractAnnotationNumberGroup::setPosition(const QPointF &newPosition)
{
    prepareGeometryChange();
    mPolygon->translate(newPosition - position());
    updateShape();
}

void AbstractAnnotationNumberGroup::setPointAt(const QPointF &point, int index)
{
    prepareGeometryChange();

    if (index >= 0) {
        mPolygon->replace(index,point);
    }
    else
    {

    }
    updateShape();
}

QPointF AbstractAnnotationNumberGroup::pointAt(int index) const
{
    if (index >= 0) {
        return mPolygon->at(index);
    }
    return QPointF(0,0);
}

void AbstractAnnotationNumberGroup::scale(qreal sx, qreal sy)
{
    prepareGeometryChange();
    QTransform transform;
    transform.scale(sx, sy);
    auto scaledPolygonLine = transform.map(*mPolygon);
    mPolygon->clear();
    delete mPolygon;
    mPolygon = new QPolygonF(scaledPolygonLine);
    updateShape();
}

void AbstractAnnotationNumberGroup::showAttachWidget(bool isShow)
{
//    if(isShow)
//    {
//        mAttachWidget->show();
//    }
//    else {
//        mAttachWidget->hide();
//    }
}

//void AbstractAnnotationNumberGroup::attachWidget(TagChooseMainWdg* wdg)
//{
//    mAttachWidget = wdg;
//}

}
