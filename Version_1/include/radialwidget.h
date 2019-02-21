#ifndef RADIALWIDGET_H
#define RADIALWIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class RadialWidget;
}

class RadialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RadialWidget(QWidget *parent = 0);
    ~RadialWidget();

signals:
    void infoConfirm(int,int);

private slots:
    void on_confirm_BT_clicked();

private:
    Ui::RadialWidget *ui;
};

#endif // RADIALWIDGET_H
