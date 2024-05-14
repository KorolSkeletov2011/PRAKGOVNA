
#ifndef AVL_H
#define AVL_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <bits/stdc++.h>

using namespace std;

namespace Ui {
class AVL;
}

class AVL : public QMainWindow
{
    Q_OBJECT

public:
    explicit AVL(QWidget *parent = nullptr);

    void vertex(int x, int y, int r, QGraphicsScene *scene, QGraphicsEllipseItem *&vert);

    ~AVL();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AVL *ui;
    QGraphicsScene *scene;

    vector <QGraphicsEllipseItem*> el;
};

#endif // AVL_H
