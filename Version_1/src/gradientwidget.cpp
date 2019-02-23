#include "include/gradientwidget.h"
#include "ui_gradientwidget.h"

GradientWidget::GradientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradientWidget)
{
    ui->setupUi(this);
}

GradientWidget::~GradientWidget()
{
    delete ui;
}

void GradientWidget::on_confirm_BT_clicked()
{
    emit infoConfirm(ui->direction_LCD->value(),ui->width_LCD->value());
}
