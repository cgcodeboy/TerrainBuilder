#ifndef CONSTRAINTWIDGET_H
#define CONSTRAINTWIDGET_H

#include <QWidget>

namespace Ui {
class ConstraintWidget;
}

class ConstraintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConstraintWidget(QWidget *parent = 0);
    ~ConstraintWidget();

private slots:
    void on_coeffcient_SL_valueChanged(int value);

    void on_confirm_BT_clicked();

signals:
    void infoConfirm(int);

private:
    Ui::ConstraintWidget *ui;
};

#endif // CONSTRAINTWIDGET_H
