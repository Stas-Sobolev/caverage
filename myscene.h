#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<memory>
#include<vector>
#include <QMouseEvent>
#include"rectangle.h"

class mySceneView : public QGraphicsView
{
public:
    mySceneView(QGraphicsScene* scene);
    ~mySceneView();

    const std::vector<std::shared_ptr<Rectangle>>& get_rectangles() const;
    void add_rectangle();

    Rectangle* get_parent_of_rectangle()const;
    //void mousePressEvent(QMouseEvent *event) override;
    //void mouseMoveEvent(QMouseEvent *event) override;

private:
    std::vector<std::shared_ptr<Rectangle>> rectangles;
    std::shared_ptr<Rectangle> parent_of_rectangles;
    std::shared_ptr<Rectangle> captured_rect;
};

#endif // MYSCENE_H
