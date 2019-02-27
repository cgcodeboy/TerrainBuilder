#include "include/subtractwidget.h"
#include "ui_subtractwidget.h"

SubtractWidget::SubtractWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubtractWidget)
{
    ui->setupUi(this);
}

SubtractWidget::~SubtractWidget()
{
    delete ui;
}

void SubtractWidget::on_confirm_BT_clicked()
{
    emit infoConfirm(ui->subtractValue_LCD->value());
}
