#ifndef BLURWIDGET_H
#define BLURWIDGET_H

#include <QWidget>

namespace Ui {
class BlurWidget;
}

class BlurWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlurWidget(QWidget *parent = 0);
    ~BlurWidget();

signals:
    void infoConfirm(int type);

private slots:
    void on_confirm_BT_clicked();

private:
    Ui::BlurWidget *ui;
};

#endif // BLURWIDGET_H
