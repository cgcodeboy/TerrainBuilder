#ifndef LAYOUTWIDGET_H
#define LAYOUTWIDGET_H

#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QBoxLayout>
#include <QMainWindow>

#include <include/shape.h>
#include <include/paintwidget.h>

namespace Ui {
class LayoutWidget;
}

class LayoutWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit LayoutWidget(QWidget *parent = 0);
    ~LayoutWidget();

signals:
    void changeCurrentShape(Shape::Code newShape);

private slots:
    void on_line_BT_clicked();

    void on_rec_BT_clicked();

    void on_generate_BT_clicked();

private:
    Ui::LayoutWidget *ui;
};

#endif // LAYOUTWIDGET_H
