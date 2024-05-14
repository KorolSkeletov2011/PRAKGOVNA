
#ifndef Treap_H
#define Treap_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <bits/stdc++.h>

using namespace std;

namespace Ui {
class Treap;
}

class Treap : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_pushButton_1488_clicked();

    void on_pushButton_1489_clicked();

    void on_pushButton_1450_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    struct node;
    node* root;
    int sz;

    bool find(int v, node* rt);

    node* merge(node* l, node* r);

    int siz(node* nd);

    pair<node*, node*> split(int x, node* rt);

    Ui::Treap *ui;
    QGraphicsScene *scene;

    vector <pair<int, QGraphicsEllipseItem*>> el;

public:
    explicit Treap(QWidget *parent = nullptr);

    void vertex(int x, int y, int r, QGraphicsScene *scene, QGraphicsEllipseItem *&vert);

    bool find(int v);

    void insert(int v);

    void erase(int v);

    void print(node* nd, int h, int& k, pair<int, int> pos);

    void dotext(node* nd, int h, int& k);

    int kf = 40;

    ~Treap();
};

#endif // Treap_H
