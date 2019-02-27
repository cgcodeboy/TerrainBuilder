#ifndef SUBTRACTWIDGET_H
#define SUBTRACTWIDGET_H

#include <QWidget>

namespace Ui {
class SubtractWidget;
}

class SubtractWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SubtractWidget(QWidget *parent = 0);
    ~SubtractWidget();

private slots:
    void on_confirm_BT_clicked();

signals:
    void infoConfirm(int);

private:
    Ui::SubtractWidget *ui;
};

#endif // SUBTRACTWIDGET_H
