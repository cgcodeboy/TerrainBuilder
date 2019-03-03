#include "include/blurwidget.h"
#include "ui_blurwidget.h"

BlurWidget::BlurWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlurWidget)
{
    ui->setupUi(this);
}

BlurWidget::~BlurWidget()
{
    delete ui;
}

void BlurWidget::on_confirm_BT_clicked()
{
    //index
    // 0 : mean
    // 1 : medium
    // 2 : Gaussian
    // 3 : Butterworth
    emit infoConfirm(ui->smoothing_CB->currentIndex());
}
