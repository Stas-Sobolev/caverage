#include "myscene.h"
#include <QDebug>

mySceneView::mySceneView(QGraphicsScene* scene):captured_rect(nullptr)
{
    setScene(scene);

    parent_of_rectangles=std::make_shared<Rectangle>(true);

    parent_of_rectangles->set_parent(this);
    parent_of_rectangles->setPos(scene->width()/2,scene->height()-scene->height()/4);
    parent_of_rectangles->setRect(0,0,100,50);
    //parent_of_rectangles->setBrush(Qt::green);
    scene->addItem(parent_of_rectangles.get());


}

mySceneView::~mySceneView()
{

}

const std::vector<std::shared_ptr<Rectangle> > &mySceneView::get_rectangles() const
{
    return rectangles;
}

void mySceneView::add_rectangle()
{
    rectangles.push_back(std::make_shared<Rectangle>());
    rectangles.back()->setBrush(Qt::green);
    rectangles.back()->set_parent(this);
    rectangles.back()->setPos(parent_of_rectangles->pos().x(),parent_of_rectangles->pos().y());
    rectangles.back()->setRect(0,0,parent_of_rectangles->rect().width(),parent_of_rectangles->rect().height());
    scene()->addItem(rectangles.back().get());

}

Rectangle *mySceneView::get_parent_of_rectangle() const
{
    return parent_of_rectangles.get();
}

/*void mySceneView::mousePressEvent(QMouseEvent *event)
{
    if(event->x()>=parent_of_rectangles->x() && event->x()<=parent_of_rectangles->x()+parent_of_rectangles->rect().width()
            && event->y()>=parent_of_rectangles->y() && event->y()<=parent_of_rectangles->y()+parent_of_rectangles->rect().height())
    {
        rectangles.push_back(std::make_shared<QGraphicsRectItem>(parent_of_rectangles->pos().x(),parent_of_rectangles->pos().y()
                                                                 ,parent_of_rectangles->rect().width(),parent_of_rectangles->rect().height()));

        captured_rect=rectangles.back();
        scene()->update();
        update();
    }
    else
}

void mySceneView::mouseMoveEvent(QMouseEvent *event)
{

}*/
