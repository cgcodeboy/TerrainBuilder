#include "gradientwidget.h"
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
