#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<memory>
#include<vector>
#include <QMouseEvent>


class mySceneView : public QGraphicsView
{
public:
    mySceneView(QGraphicsScene* scene);
    ~mySceneView();

    const std::vector<std::shared_ptr<QGraphicsRectItem>>& get_rectangles() const;
    void add_rectangle(const std::shared_ptr<QGraphicsRectItem>& rect);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    std::vector<std::shared_ptr<QGraphicsRectItem>> rectangles;
    std::shared_ptr<QGraphicsRectItem> parent_of_rectangles;
    std::shared_ptr<QGraphicsRectItem> captured_rect;
};

#endif // MYSCENE_H
