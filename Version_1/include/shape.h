#ifndef SHAPE
#define SHAPE

#include <QtGui>

class Shape
{
public:

    enum Code {
        Line,
        Rect
    };

    Shape(){}

    void setStart(QPoint s)
    {
        start = s;
    }

    void setEnd(QPoint e)
    {
        end = e;
    }

    QPoint startPoint()
    {
        return start;
    }

    QPoint endPoint()
    {
        return end;
    }

    void virtual paint(QPainter & painter) = 0;

protected:
    QPoint start;
    QPoint end;
};

class Line : public Shape
{
public:
    Line(){}

    void virtual paint(QPainter &painter){
        painter.drawLine(start, end);
    }
};

class Rect : public Shape
{
public:
    Rect(){}

    void virtual paint(QPainter &painter){
        painter.drawRect(start.x(), start.y(),
                         end.x() - start.x(), end.y() - start.y());
    }
};

#endif // SHAPE

