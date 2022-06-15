#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QWidget>
#include <QPoint>
#include <memory>


class mySceneView;

class Rectangle:public QGraphicsRectItem
{
public:
    Rectangle(double x, double y, double w, double h,bool stat, mySceneView* parent);
    Rectangle(bool stat=false,mySceneView* parent=nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;



    void set_captured(bool cap);
    bool is_captured() const;

    void set_parent(mySceneView* par);
    //const QPoint& get_coordinate_capt_rect()const;
private:
    bool captured;
    std::shared_ptr<mySceneView> parent;
    bool stationary;
};

#endif // RECTANGLE_H
