#include "rectangle.h"
#include <QPointF>
#include "myscene.h"
#include <QDebug>
Rectangle::Rectangle(double x, double y, double w, double h,bool stat, mySceneView* _parent):QGraphicsRectItem(x,y,w,h)
{
   parent.reset(_parent);
   stationary=stat;
}

Rectangle::Rectangle(bool stat,mySceneView* parent):Rectangle(0,0,0,0,stat,parent){}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(stationary)
        parent->add_rectangle();
    //поворот прямоугольника(пока на 90 градусов)
    else if(event->button()==Qt::RightButton)
    {
        //this->setRect(0,0,rect().height(),rect().width());
        setTransformOriginPoint(0,0);
        setRotation(this->rotation()+90);

    }

}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!stationary)
    {
        QPointF delta = event->scenePos()-event->lastScenePos();
        moveBy(delta.x(),delta.y());
    }

}

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    set_captured(false);
}

void Rectangle::set_captured(bool cap)
{
    captured=cap;
}

bool Rectangle::is_captured() const
{
    return captured;
}

void Rectangle::set_parent(mySceneView* par)
{
    parent.reset(par);
}


