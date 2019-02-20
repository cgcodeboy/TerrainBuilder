#include "include/constantwidget.h"
#include "ui_constantwidget.h"

ConstantWidget::ConstantWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConstantWidget)
{
    ui->setupUi(this);
}

ConstantWidget::~ConstantWidget()
{
    delete ui;
}

void ConstantWidget::on_confirm_BT_clicked()
{
    emit(infoConfirm(ui->value_LCD->value()));
}
