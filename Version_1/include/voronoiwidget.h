#ifndef VORONOIWIDGET_H
#define VORONOIWIDGET_H

#include <QWidget>

namespace Ui {
class VoronoiWidget;
}

class VoronoiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VoronoiWidget(QWidget *parent = 0);
    ~VoronoiWidget();

signals:
    void infoConfirm(int);

private slots:
    void on_confirm_BT_clicked();

private:
    Ui::VoronoiWidget *ui;
};

#endif // VORONOIWIDGET_H
