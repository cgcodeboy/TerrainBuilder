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

private:
    Ui::VoronoiWidget *ui;
};

#endif // VORONOIWIDGET_H
