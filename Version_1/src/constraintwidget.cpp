#include "include/constraintwidget.h"
#include "ui_constraintwidget.h"

ConstraintWidget::ConstraintWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConstraintWidget)
{
    ui->setupUi(this);
}

ConstraintWidget::~ConstraintWidget()
{
    delete ui;
}

void ConstraintWidget::on_coeffcient_SL_valueChanged(int value)
{
    ui->coeffcient_LCD->display(static_cast<double>(value)/100);
}

void ConstraintWidget::on_confirm_BT_clicked()
{
    emit infoConfirm(ui->coeffcient_LCD->value());
}
