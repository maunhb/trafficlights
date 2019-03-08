#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QObject>
#include <QMainWindow>
#include "worlditerator.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void renderPixmap();

private:
    Ui::MainWindow *ui;
    World* mainWorld;
    WorldPainter* worldPainter;
    WorldIterator* worldIterator;
    QPixmap* drawSurfacePixmap;
    QPainter* drawSurfacePainter;
    map* worldMap;
    void initRenderSurface();
    void resizeEvent(QResizeEvent* event);

private slots:
    void on_startButton_clicked();
//    void on_restartButton_clicked();
};

#endif // MAINWINDOW_H
