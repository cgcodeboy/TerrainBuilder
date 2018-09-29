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
