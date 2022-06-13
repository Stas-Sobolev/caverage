#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    my_scene=std::make_unique<mySceneView>(new QGraphicsScene(0,0,600,600));

    this->setCentralWidget(my_scene.get());
}

MainWindow::~MainWindow()
{

}

