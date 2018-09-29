#ifndef PERLINWIDGET_H
#define PERLINWIDGET_H

#include <QWidget>

namespace Ui {
class PerlinWidget;
}

class PerlinWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PerlinWidget(QWidget *parent = 0);
    ~PerlinWidget();

private:
    Ui::PerlinWidget *ui;
};

#endif // PERLINWIDGET_H
