#include "treap.h"
#include "ui_treap.h"
#include "QGraphicsEllipseItem"
#include "QGraphicsScene"
#include <mainwindow.h>
#include <iostream>
#include <cmath>
#include "bits/stdc++.h"

struct Treap::Treap::node{
    Treap::node *l, *r;
    int val, pr;
    int sz;

    node(int val0 = 0) {
        val = val0;
        pr = rand();
        sz = 1;
        l = r = nullptr;
    }
};

Treap::Treap(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Treap)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

Treap::~Treap()
{
    delete ui;
}

void Treap::vertex(int x, int y, int r, QGraphicsScene *scene, QGraphicsEllipseItem *&vert) {
    QBrush br(Qt::black);
    QPen whitePen(Qt::black);
    whitePen.setWidth(3);
    vert = scene->addEllipse(x, y, r, r, whitePen, br);
    vert->setFlag(QGraphicsItem::ItemIsSelectable);
}

void Treap::print(Treap::node* rt, int h, int& k, pair<int, int> pos) {
    if (rt == nullptr) return;

    print(rt->l, h + 1, k, {3 * kf / 2 * (k + siz(rt->l) + 1) + kf / 2, 5 * kf / 2 * h + kf / 2});
    ++k;

    if (pos != make_pair(-INT_MIN, -INT_MIN)) {
        QBrush br(Qt::black);
        QPen whitePen(Qt::black);

        scene->addLine(3 * kf / 2 * k + kf / 2, 5 * kf / 2 * h + kf / 2, pos.first, pos.second);
    }

    QGraphicsEllipseItem* vert;
    vertex(3 * kf / 2 * k, 5 * kf / 2 * h, kf, scene, vert);

    el.push_back({rt->val, vert});

    print(rt->r, h + 1, k, {3 * kf / 2 * k + kf / 2, 5 * kf / 2 * h + kf / 2});
}

void Treap::dotext(node* rt, int h, int &k) {
    if (rt == nullptr) return;

    dotext(rt->l, h + 1, k);
    ++k;

    int kol = to_string(rt->val).size();
    auto text = new QGraphicsTextItem(QString::number(rt->val) + "\n" + QString::number(rt->pr));
    text->setScale(max(1 - 0.05 * kol, 0.5 / (40.0 / kf)));
    text->scale();
    text->setDefaultTextColor(Qt::red);
    text->setPos(3 * kf / 2 * k, 5 * kf / 2 * h + kf / 3);
    scene->addItem(text);

    dotext(rt->r, h + 1, k);
}

bool Treap::find(int v, Treap::node* rt) {
    if (rt == nullptr) return false;
    if (rt->val == v) return true;
    if (v < rt->val) return find(v, rt->l);
    return find(v, rt->r);
}

bool Treap::find(int v) {
    return find(v, root);
}

int Treap::siz(node* nd) {
    if (nd == nullptr) return 0;
    return nd->sz;
}

Treap::node* Treap::merge(Treap::node *l, Treap::node *r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;
    if (l->pr > r->pr) {
        l->r = merge(l->r, r);
        l->sz = siz(l->l) + siz(l->r) + 1;
        return l;
    }
    r->l = merge(l, r->l);
    r->sz = siz(r->l) + siz(r->r) + 1;
    return r;
}

pair<Treap::node*, Treap::node*> Treap::split(int x, Treap::node* rt) {
    if (rt == nullptr) return {nullptr, nullptr};
    if (rt->val <= x) {
        auto p = split(x, rt->r);
        rt->r = p.first;
        rt->sz = siz(rt->l) + siz(rt->r) + 1;
        return {rt, p.second};
    }
    auto p = split(x, rt->l);
    rt->l = p.second;
    rt->sz = siz(rt->l) + siz(rt->r) + 1;
    return {p.first, rt};
}

void Treap::insert(int v) {
    if (find(v)) return;
    ++sz;
    auto* nw = new node(v);
    auto p = split(v, root);
    root = merge(merge(p.first, nw), p.second);
}

void Treap::erase(int v) {
    if (!find(v)) return;
    --sz;
    auto p = split(v, root);
    root = merge(split(v - 1, p.first).first, p.second);
}

void Treap::on_pushButton_1488_clicked()
{
    long long k = rand();
    insert(k);
    int cnt = 0;
    for (auto& [v, e] : el) {
        scene->removeItem(e);
    }
    scene->clear();
    el.clear();
    kf = max(15, 40 - sz / 2);
    print(root, 0, cnt, {-INT_MIN, -INT_MIN});
    cnt = 0;
    dotext(root, 0, cnt);
}


void Treap::on_pushButton_1489_clicked()
{
    for (int i = 0; i < (int)el.size(); ++i) {
        if (el[i].second->isSelected()) {
            erase(el[i].first);
            scene->removeItem(el[i].second);
        }
    }
    int cnt = 0;
    for (auto& [v, e] : el) {
        scene->removeItem(e);
    }
    scene->clear();
    el.clear();
    kf = max(15, 40 - sz / 2);
    print(root, 0, cnt, {-INT_MIN, -INT_MIN});
    cnt = 0;
    dotext(root, 0, cnt);
}

void Treap::on_pushButton_1450_clicked()
{
    hide();
    auto my = new MainWindow;
    my->show();
}


void Treap::on_pushButton_clicked()
{
    ui->graphicsView->scale(1.05, 1.05);
}


void Treap::on_pushButton_2_clicked()
{
    ui->graphicsView->scale(0.95, 0.95);
}

