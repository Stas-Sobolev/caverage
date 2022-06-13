#include "myscene.h"
#include <QDebug>

mySceneView::mySceneView(QGraphicsScene* scene):captured_rect(nullptr)
{
    setScene(scene);

    parent_of_rectangles=std::make_shared<QGraphicsRectItem>();

    parent_of_rectangles->setPos(scene->width()/2,scene->height()-scene->height()/4);
    parent_of_rectangles->setRect(0,0,100,100);
    parent_of_rectangles->setBrush(Qt::green);
    scene->addItem(parent_of_rectangles.get());

}

mySceneView::~mySceneView()
{

}

const std::vector<std::shared_ptr<QGraphicsRectItem> > &mySceneView::get_rectangles() const
{
    return rectangles;
}

void mySceneView::add_rectangle(const std::shared_ptr<QGraphicsRectItem>& rect)
{
    rectangles.push_back(rect);
}

void mySceneView::mousePressEvent(QMouseEvent *event)
{
    if(event->x()>=parent_of_rectangles->x() && event->x()<=parent_of_rectangles->x()+parent_of_rectangles->rect().width()
            && event->y()>=parent_of_rectangles->y() && event->y()<=parent_of_rectangles->y()+parent_of_rectangles->rect().height())
    {
        rectangles.push_back(std::make_shared<QGraphicsRectItem>(parent_of_rectangles->pos().x(),parent_of_rectangles->pos().y()
                                                                 ,parent_of_rectangles->rect().width(),parent_of_rectangles->rect().height()));
        //rectangles.back()->setBrush(Qt::red);
        /*rectangles.back()->setPos(200,200);
        rectangles.back()->setRect(0,0,200,200);*/
        scene()->addItem(rectangles.back().get());

        captured_rect=rectangles.back();
        scene()->update();
        update();
    }
}

void mySceneView::mouseMoveEvent(QMouseEvent *event)
{

}
