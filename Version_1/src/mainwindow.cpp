#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainView->initBluePrint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_select_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,true);
    }
    QApplication::restoreOverrideCursor();
    setCursor(Qt::ArrowCursor);
    ui->mainView->setCur_type(ITEM_TYPE::Arrow);
}

void MainWindow::on_connect_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    QApplication::restoreOverrideCursor();
    setCursor(Qt::CrossCursor);
    ui->mainView->setCur_type(ITEM_TYPE::Connect);
}

void MainWindow::on_type1_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    QString cursor_path(":/icon/resource/image/mounBT_1.ico");
    QApplication::restoreOverrideCursor();
    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Constant_Generator);
}

void MainWindow::on_tpye2_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    QString cursor_path(":/icon/resource/image/mounBT_2.ico");
    QApplication::restoreOverrideCursor();
    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Layout_Generator);
}

void MainWindow::on_type3_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    QString cursor_path(":/icon/resource/image/mounBT_3.ico");
    QApplication::restoreOverrideCursor();
    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Perlin_Generator);
}

void MainWindow::on_type4_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    QString cursor_path(":/icon/resource/image/mounBT_4.ico");
    QApplication::restoreOverrideCursor();
    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Gradient_Generator);
}
