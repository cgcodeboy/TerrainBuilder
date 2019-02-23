#ifndef GRADIENTWIDGET_H
#define GRADIENTWIDGET_H

#include <QWidget>

namespace Ui {
class GradientWidget;
}

class GradientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GradientWidget(QWidget *parent = 0);
    ~GradientWidget();

signals:
    void infoConfirm(int,int);

private slots:
    void on_confirm_BT_clicked();

private:
    Ui::GradientWidget *ui;
};

#endif // GRADIENTWIDGET_H
