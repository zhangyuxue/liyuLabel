#include "abstractannotationpolygon.h"
#include <QDebug>

namespace kImageAnnotator {

AbstractAnnotationPolygon::AbstractAnnotationPolygon(const QPointF &startPosition, AnnotationProperties *properties) : AbstractAnnotationItem(properties)
{
    mPolygon = new QPolygonF();
    mPolygon->append(startPosition);
    mPolygon->append(startPosition);
    realptsNum=mPolygon->size();
}

AbstractAnnotationPolygon::AbstractAnnotationPolygon(const AbstractAnnotationPolygon &other) : AbstractAnnotationItem(other)
{
    mPolygon = new QPolygonF(*other.mPolygon);
    realptsNum=mPolygon->size();
}

AbstractAnnotationPolygon::~AbstractAnnotationPolygon()
{
    delete mPolygon;
}

int AbstractAnnotationPolygon::nearSharedPoints(QPointF point)
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

int AbstractAnnotationPolygon::pointIndex(QPointF &point)
{
    for (int i=0;i<mPolygon->size();i++) {
        if(mPolygon->at(i) == point)
            return i;
    }
    return -1;
}

QVector<QPointF> AbstractAnnotationPolygon::getPoints(int indexStart,int indexEnd)
{
    QVector<QPointF> points;
    for (int i=indexStart;i<indexEnd;i++) {
        qDebug()<<"Get points:"<<i<<"--------------"<<mPolygon->at(i);
       points.append(mPolygon->at(i));
    }
    return points;
}

QPolygonF AbstractAnnotationPolygon::polygon() const
{
    return *mPolygon;
}

void AbstractAnnotationPolygon::addPoint(const QPointF &position, bool modified)
{
    prepareGeometryChange();
    if(mPolygon->size() > realptsNum)
        mPolygon->removeLast();
    mPolygon->append(position);
    realptsNum++;
    updateShape();
}

void AbstractAnnotationPolygon::setPosition(const QPointF &newPosition)
{
    prepareGeometryChange();
    mPolygon->translate(newPosition - position());
    updateShape();
}

void AbstractAnnotationPolygon::setPointAt(const QPointF &point, int index)
{
    prepareGeometryChange();

    if (index >= 0) {
        mPolygon->replace(index,point);
    }
    else
    {
        if(mPolygon->size() == 2)
        {
            mPolygon->replace(1,point);
        }
        else
        {
            if(mPolygon->size() == realptsNum)
            {
                mPolygon->append(point);
            }
            else {
                mPolygon->replace(mPolygon->size()-1,point);
            }
        }
    }
    updateShape();
}

QPointF AbstractAnnotationPolygon::pointAt(int index) const
{
    if (index >= 0) {
        return mPolygon->at(index);
    }
    return QPointF(0,0);
}

void AbstractAnnotationPolygon::scale(qreal sx, qreal sy)
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

}
