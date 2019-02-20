#include "include/perlinwidget.h"
#include "ui_perlinwidget.h"

PerlinWidget::PerlinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PerlinWidget)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
}

PerlinWidget::~PerlinWidget()
{
    delete ui;
}

void PerlinWidget::on_confirm_BT_clicked()
{
    emit infoConfirm(ui->persistance_LCD->value(),ui->frequency_LCD->value(),ui->amplitude_LCD->value(),ui->octaves_LCD->value(),ui->randomseed_LCD->value());
}
