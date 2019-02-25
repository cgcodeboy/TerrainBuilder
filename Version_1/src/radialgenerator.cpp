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
    return QRectF(0,0,150,70);
}

void RadialGenerator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
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
    _radial->show();
    QGraphicsItem::mouseDoubleClickEvent(event);
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

