#include "include/addwidget.h"
#include "ui_addwidget.h"

AddWidget::AddWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddWidget)
{
    ui->setupUi(this);
}

AddWidget::~AddWidget()
{
    delete ui;
}

void AddWidget::on_confirm_BT_clicked()
{
    emit infoConfirm(ui->addValue_LCD->value());
}
