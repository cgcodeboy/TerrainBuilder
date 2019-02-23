#include "include/gradientgenerator.h"

GradientGenerator::GradientGenerator():Generator(ITEM_TYPE::Gradient_Generator)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    _gradient = new GradientWidget;
    connect(_gradient,SIGNAL(infoConfirm(int,int)),this,SLOT(infoCome(int,int)));
}

QRectF GradientGenerator::boundingRect() const
{
    return QRectF(0,0,100,200);
}

void GradientGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(focused){
        painter->setPen(Qt::green);
        painter->drawRect(0,0,100,200);
        QBrush brush(QColor(255,0,0,100));
        painter->fillRect(QRect(0,0,100,200),brush);
    }
    else
    {
        QRectF rec1(0,0,100,50);
        QImage image(":/image/resource/image/item/gradient.jpg");
        painter->drawImage(rec1,image);

        QRectF rec2(0,50,100,150);
        QBrush brush(QColor(30,40,50,50));
        painter->fillRect(rec2,brush);

        painter->setPen(Qt::green);
        painter->drawEllipse(2,68,5,5);

        painter->drawText(10,70,"hello");
    }
}

void GradientGenerator::heightDataProcess()
{
    float radio = static_cast<float>(255)/_width;
    m_heightData.assign(255,255,1,1);
    for (int i = 127; i >=0; i--){
        for (int j = 0; j < 255; j++){
            int value = 127 - radio*(127-i);
            if(value >=0 )
                m_heightData(i, j, 0, 0) = value;
            else
                m_heightData(i, j, 0, 0) = 0;
        }
    }
    for (int i = 128; i <255; i++){
        for (int j = 0; j < 255; j++){
            int value = 128 + radio*(i - 128);
            if(value <= 255 )
                m_heightData(i, j, 0, 0) = value;
            else
                m_heightData(i, j, 0, 0) = 255;
        }
    }

    m_heightData = m_heightData.rotate(_direction,1,1);
    m_heightData.save_bmp(("./tmp/image/"+getName()+".bmp").toStdString().c_str());
}

void GradientGenerator::infoCome(int direction, int width)
{
    _direction = direction;
    _width = width;
    heightDataProcess();
}

void GradientGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    _gradient->show();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void GradientGenerator::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void GradientGenerator::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

