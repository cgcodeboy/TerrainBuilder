#include "include\radialgenerator.h"

RadialGenerator::RadialGenerator():Generator(ITEM_TYPE::Radial_Generator)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);

    _radial = new RadialWidget;
    connect(_radial,SIGNAL(infoConfirm(int,int)),this,SLOT(infoCome(int,int)));
}

QRectF RadialGenerator::boundingRect() const
{
    return QRectF(0,0,100,200);
}

void RadialGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        QImage image(":/image/resource/image/item/radial.jpg");
        painter->drawImage(rec1,image);

        QRectF rec2(0,50,100,150);
        QBrush brush(QColor(30,40,50,50));
        painter->fillRect(rec2,brush);

        painter->setPen(Qt::green);
        painter->drawEllipse(2,68,5,5);

        painter->drawText(10,70,"hello");
    }
}

void RadialGenerator::heightDataProcess()
{
    //type equals 0, use gaussian function.
    if(_type == 0){
        //sigmal is the 4 quarter of radius
        float **GKernel = new float*[255];
        float sigma = _radius/4;
        float r, s = 2.0 * sigma * sigma;

        // sum is for normalization
        float sum = 0.0;

        int temp = 255/2;

        //dynamically generate the 2d array
        for (int x = 0; x <= 255; x++)
            GKernel[x] = new float[255];

        //generate the origin data
        for (int x = -127; x <= 127; x++) {
            for (int y = -127; y <= 127; y++) {
                r = sqrt(x * x + y * y);
                GKernel[x + 127][y + 127] = (exp(-(r * r) / s)) / (M_PI * s);
                sum += GKernel[x + 127][y + 127];
            }
        }

        float max = 0;
        // normalising the Kernel
        for (int i = 0; i <= 255; ++i)
            for (int j = 0; j <= 255; ++j){
                GKernel[i][j] /= sum;
                if(GKernel[i][j]>max)
                    max = GKernel[i][j];
            }

        //normal to (0 to 1)
        for (int i = 0; i <= 255; ++i)
            for (int j = 0; j <= 255; ++j){
                GKernel[i][j] /= max;
            }

        //generate the bitmap
        m_heightData.assign(255,255,1,1);
        for (int i = 0; i < 255; i++)
            for (int j = 0; j < 255; j++)
                m_heightData(i, j, 0, 0) = GKernel[i][j]*255;
        m_heightData.save_bmp(("./tmp/image/"+getName()+".bmp").toStdString().c_str());
    }else if(_type == 1){

    }else{

    }
}


void RadialGenerator::infoCome(int radius, int radial_type)
{
    qDebug()<<radius<<radial_type;
    _radius = radius;
    _type = radial_type;
    heightDataProcess();
}

void RadialGenerator::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
    _radial->show();
}

void RadialGenerator::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void RadialGenerator::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

