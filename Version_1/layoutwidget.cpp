#include "layoutwidget.h"
#include "ui_layoutwidget.h"

LayoutWidget::LayoutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LayoutWidget)
{
    ui->setupUi(this);
}

LayoutWidget::~LayoutWidget()
{
    delete ui;
}
