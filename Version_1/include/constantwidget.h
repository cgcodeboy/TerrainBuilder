#ifndef CONSTANTWIDGET_H
#define CONSTANTWIDGET_H

#include <QWidget>

namespace Ui {
class ConstantWidget;
}

class ConstantWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConstantWidget(QWidget *parent = 0);
    ~ConstantWidget();

private slots:
    void on_confirm_BT_clicked();

signals:
    void infoConfirm(int);

private:
    Ui::ConstantWidget *ui;
};

#endif // CONSTANTWIDGET_H
