#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avl.h"
#include "ui_avl.h"
#include "ui_treap.h"
#include "treap.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto my = new AVL;
    my->show();
    hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    auto my = new Treap;
    my->show();
    hide();
}

