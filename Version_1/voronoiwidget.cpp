#include "voronoiwidget.h"
#include "ui_voronoiwidget.h"

VoronoiWidget::VoronoiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VoronoiWidget)
{
    ui->setupUi(this);
}

VoronoiWidget::~VoronoiWidget()
{
    delete ui;
}
