#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>

namespace Ui {
class AddWidget;
}

class AddWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddWidget(QWidget *parent = 0);
    ~AddWidget();

private:
    Ui::AddWidget *ui;

signals:
    void infoConfirm(int);
private slots:
    void on_confirm_BT_clicked();
};

#endif // ADDWIDGET_H
