#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>
#include <QGraphicsSceneMouseEvent>

namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = 0);
    ~TestForm();

private:
    Ui::TestForm *ui;
    bool focused;

protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif // TESTFORM_H
