#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainView->initBluePrint();

    QDir dir;
    if (!dir.exists("./tmp/image/"))
    {
        dir.mkpath("./tmp/image/");
    }
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
//    QApplication::restoreOverrideCursor();
//    setCursor(Qt::ArrowCursor);
//    ui->mainView->setCur_type(ITEM_TYPE::Arrow);
}

void MainWindow::on_connect_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QApplication::restoreOverrideCursor();
//    setCursor(Qt::CrossCursor);
//    ui->mainView->setCur_type(ITEM_TYPE::Connect);
}

void MainWindow::on_constant_Gen_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QString cursor_path(":/icon/resource/icon/constant.jpg");
//    QApplication::restoreOverrideCursor();
//    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Constant_Generator);
}

void MainWindow::on_layout_Gen_BT_clicked()
{
//    qDebug()<<"click la la";
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QString cursor_path(":/icon/resource/icon/layout.jpg");
//    QApplication::restoreOverrideCursor();
//    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Layout_Generator);
}

void MainWindow::on_perlin_Gen_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QString cursor_path(":/icon/resource/icon/perlin.jpg");
//    QApplication::restoreOverrideCursor();
//    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Perlin_Generator);
}

void MainWindow::on_gradient_Gen_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QString cursor_path(":/icon/resource/icon/gradient.jpg");
//    QApplication::restoreOverrideCursor();
//    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Gradient_Generator);
}

void MainWindow::on_radial_Gen_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QString cursor_path(":/icon/resource/icon/radial.jpg");
//    QApplication::restoreOverrideCursor();
//    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Radial_Generator);
}

void MainWindow::on_voronoi_Gen_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QString cursor_path(":/icon/resource/icon/voronoi.jpg");
//    QApplication::restoreOverrideCursor();
//    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Voronoi_Generator);
}

void MainWindow::on_simple_Con_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
//    QString cursor_path(":/icon/resource/icon/simple.jpg");
//    QApplication::restoreOverrideCursor();
//    setCursor(QCursor(QPixmap(cursor_path)));
    ui->mainView->setCur_type(ITEM_TYPE::Simple_Combiner);
}

void MainWindow::on_constraint_Con_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Constraint_Combiner);
}

void MainWindow::on_blur_Filter_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Blur_Filter);
}

void MainWindow::on_clamp_Filter_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Clamp_Filter);
}

void MainWindow::on_noise_Filter_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Noise_Filter);
}

void MainWindow::on_terrace_Filter_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Terrace_Filter);
}

void MainWindow::on_add_Math_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Add_Math);
}

void MainWindow::on_subtract_Math_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Subtract_Math);
}

void MainWindow::on_multiply_Math_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Multiply_Math);
}

void MainWindow::on_divide_Math_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Divide_Math);
}

void MainWindow::on_invert_Math_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Invert_Math);
}


void MainWindow::on_sqrt_Math_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Sqrt_Math);
}

void MainWindow::on_water_Nat_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::WaterErosion_Nature);
}

void MainWindow::on_thermal_Nat_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::ThermalErosion_Nature);
}

void MainWindow::on_height_Out_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Height_Output);
}

void MainWindow::on_texture_Out_BT_clicked()
{
    QGraphicsScene *scene = ui->mainView->getScene();
    foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    ui->mainView->setCur_type(ITEM_TYPE::Texture_Output);
}
