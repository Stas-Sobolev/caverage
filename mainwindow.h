#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"myscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MainWindow(const MainWindow&)=delete;
    MainWindow& operator= (const MainWindow&) =delete;
private:
    std::shared_ptr<mySceneView> my_scene;
};
#endif // MAINWINDOW_H
