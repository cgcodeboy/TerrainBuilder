#include "include/perlingenerator.h"

int PerlinGenerator::counterNum = 0;

PerlinGenerator::PerlinGenerator():Generator(ITEM_TYPE::Perlin_Generator)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    _number = counterNum;
    setName("PerlinGenerator"+QString::number(_number));
    counterNum++;

    _perlin = new PerlinWidget;
    connect(_perlin,SIGNAL(infoConfirm(float,float,float,int,int)),this,SLOT(infoCome(float,float,float,int,int)));
}

QRectF PerlinGenerator::boundingRect() const
{
    return QRectF(0,0,100,200);
}

void PerlinGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        QImage image(":/image/resource/image/item/perlin.jpg");
        painter->drawImage(rec1,image);

        QRectF rec2(0,50,100,150);
        QBrush brush(QColor(30,40,50,50));
        painter->fillRect(rec2,brush);

        painter->setPen(Qt::green);
        painter->drawEllipse(2,68,5,5);

        painter->drawText(10,70,"hello");
    }
}

void PerlinGenerator::heightDataProcess()
{
    m_heightData.assign(255,255,1,1);
    for (int i = 0; i < 255; i++){
        for (int j = 0; j < 255; j++){
            m_heightData(i, j, 0, 0) = noise->getNoiseValue(i,j);
        }
    }
    m_heightData.save_bmp(("./tmp/image/"+getName()+".bmp").toStdString().c_str());
}

void PerlinGenerator::infoCome(float persistence, float frequency, float amplitude, int octaves, int randomseed)
{
    qDebug()<<persistence<<octaves;
    noise = new PerlinNoise();
    noise->setPersistence(persistence);
    noise->setOctaves(octaves);
    noise->setAmplitude(amplitude);
    noise->setFrequency(frequency);
    noise->setRandomSeed(randomseed);
    heightDataProcess();
}

void PerlinGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
    _perlin->show();
}

void PerlinGenerator::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void PerlinGenerator::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

