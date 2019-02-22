#include "include\voronoigenerator.h"

VoronoiGenerator::VoronoiGenerator():Generator(ITEM_TYPE::Voronoi_Generator)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    _voronoi = new VoronoiWidget;
    connect(_voronoi,SIGNAL(infoConfirm(int)),this,SLOT(infoCome(int)));
}

QRectF VoronoiGenerator::boundingRect() const
{
    return QRectF(0,0,100,200);
}

void VoronoiGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        QImage image(":/image/resource/image/item/voronoi.jpg");
        painter->drawImage(rec1,image);

        QRectF rec2(0,50,100,150);
        QBrush brush(QColor(30,40,50,50));
        painter->fillRect(rec2,brush);

        painter->setPen(Qt::green);
        painter->drawEllipse(2,68,5,5);

        painter->drawText(10,70,"hello");
    }
}

void VoronoiGenerator::heightDataProcess()
{
    //create points
    std::vector<QPoint> points;
    srand(time(NULL));
    int w = 255 - 20, h = 255 - 20;
    for (int i = 0; i < _number; i++)
    {
        QPoint point;
        point.setX(rand()%w+10);
        point.setY(rand()%w+10);
        points.push_back(point);
    }

    m_heightData.assign(255,255,1,1);
    int d;
    h = w = 255;
    for (int hh = 0; hh < h; hh++) {
        for (int ww = 0; ww < w; ww++) {
            int ind = -1, dist = INT_MAX;
            for (int it = 0; it < points.size(); it++) {
                QPoint p = points[it];
                d = sqrt((p.x()-hh)*(p.x()-hh)+(p.y()-ww)*(p.y()-ww));
                if (d < dist) {
                    dist = d;
                    ind = it;
                }
            }

            if (ind > -1){
                int value = 0 + dist * log(_number);
                if(value  < 255)
                    m_heightData(hh, ww, 0, 0) = 255 - value;
                else
                    m_heightData(hh, ww, 0, 0) = 0;
            }
        }
    }
    m_heightData.save_bmp(("./tmp/image/"+getName()+".bmp").toStdString().c_str());
}

void VoronoiGenerator::infoCome(int number)
{
    _number = number;
    heightDataProcess();
}

void VoronoiGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    _voronoi->show();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void VoronoiGenerator::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void VoronoiGenerator::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

