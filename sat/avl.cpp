#include "avl.h"
#include "ui_avl.h"
#include "QGraphicsEllipseItem"
#include "QGraphicsScene"
#include <iostream>
#include <cmath>
#include "mainwindow.h"


AVL::AVL(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AVL)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

AVL::~AVL()
{
    delete ui;
}


void AVL::vertex(int x, int y, int r, QGraphicsScene *scene, QGraphicsEllipseItem *&vert) {
    QBrush br(Qt::red);
    QPen whitePen(Qt::red);
    whitePen.setWidth(3);
    vert = scene->addEllipse(x, y, r, r, whitePen);
    vert->setFlag(QGraphicsItem::ItemIsSelectable);
}



void AVL::on_pushButton_clicked()
{
    QGraphicsEllipseItem* vert;
    vertex(50, 50, 50, scene, vert);

    el.push_back(vert);
}


void AVL::on_pushButton_2_clicked()
{
    for (auto& e : el) {
        if (e->isSelected()) scene->removeItem(e);
    }
}

void AVL::on_pushButton_3_clicked()
{
    ui->graphicsView->scale(1.05, 1.05);
}


void AVL::on_pushButton_5_clicked()
{
    ui->graphicsView->scale(0.95, 0.95);
}

void AVL::on_pushButton_4_clicked()
{
    hide();
    auto my = new MainWindow;
    my->show();
}
