#include "blurwidget.h"
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
