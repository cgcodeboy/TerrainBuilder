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
    connect(_perlin,SIGNAL(infoConfirm(float,float,int,int)),this,SLOT(infoCome(float,float,int,int)));
}

QRectF PerlinGenerator::boundingRect() const
{
    return QRectF(0,0,150,70);
}

void PerlinGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void PerlinGenerator::heightDataProcess()
{
    m_heightData.assign(255,255,1,1);
    for (int i = 0; i < 255; i++){
        for (int j = 0; j < 255; j++){
            m_heightData(i, j, 0, 0) = noise->getNoiseValue(static_cast<float>(i)/255,static_cast<float>(j)/255)*255;
        }
    }
    m_heightData.save_bmp(("./tmp/image/"+getName()+".bmp").toStdString().c_str());
}

void PerlinGenerator::infoCome(float frequency, float amplitude, int octaves, int randomseed)
{
    noise = new Perlin();
    noise->setOctaves(octaves);
    noise->setAmplitude(amplitude);
    noise->setFrequency(frequency);
    noise->setRandomSeed(randomseed);
    heightDataProcess();
}

void PerlinGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    _perlin->show();
    QGraphicsItem::mouseDoubleClickEvent(event);    
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

