#include "include/voronoiwidget.h"
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

void VoronoiWidget::on_confirm_BT_clicked()
{
    emit infoConfirm(ui->number_LCD->value());
}

