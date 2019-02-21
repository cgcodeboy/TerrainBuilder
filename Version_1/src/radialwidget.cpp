#include "include/radialwidget.h"
#include "ui_radialwidget.h"

RadialWidget::RadialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RadialWidget)
{
    ui->setupUi(this);
}

RadialWidget::~RadialWidget()
{
    delete ui;
}

void RadialWidget::on_confirm_BT_clicked()
{
    emit infoConfirm(ui->radius_LCD->value(),ui->type_CB->currentIndex());
}
