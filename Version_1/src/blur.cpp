#include "include/blur.h"

void DFT(int dir,double *real,double *imag){
    int i,k;
    double arg,cosarg,sinarg;
    double *_real = new double[256],*_imag = new double[256];
    for(int i = 0; i < 256;i++){
        _real[i] = 0;
        _imag[i] = 0;
        arg = - dir * 2 * M_PI * static_cast<double>(i) / 256;
        for(int j = 0; j < 256 ;j++){
            cosarg = cos(j * arg);
            sinarg = sin(j * arg);
            _real[i] += (real[j] * cosarg - imag[j] * sinarg);
            _imag[i] += (real[j] * sinarg + imag[j] * cosarg);
        }
    }

    if(dir == 1){
        for (i = 0; i < 256; i++) {
            real[i] = _real[i] / static_cast<double>(256);
            imag[i] = _imag[i] / static_cast<double>(256);
        }
    }else{
        for (i = 0; i < 256; i++) {
            real[i] = _real[i];
            imag[i] = _imag[i];
        }
    }

    delete []_real;
    delete []_imag;
}


Blur::Blur():Filter(ITEM_TYPE::Blur_Filter)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF Blur::boundingRect() const
{
    return QRectF(0,0,150,70);
}

void Blur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void Blur::processHeightData()
{
    CImg<unsigned char> outputHeightData;

    switch (_type) {
    case 0:{
        //mean filter
        for(int i = 0;i<255;i++){
            for(int j = 0;j<255;j++){
                if(i==0||i==255||j==0||j==255){
                    outputHeightData(i,j,0,0) = m_heightData(i,j,0,0);
                }else{
                    outputHeightData(i,j,0,0) = (m_heightData(i-1,j-1,0,0)+m_heightData(i,j-1,0,0)+m_heightData(i+1,j-1,0,0)\
                                                 +m_heightData(i-1,j,0,0)+m_heightData(i,j,0,0)+m_heightData(i+1,j,0,0)\
                                                 +m_heightData(i-1,j+1,0,0)+m_heightData(i,j+1,0,0)+m_heightData(i+1,j+1,0,0))/9;
                }
            }
        }
        break;
    }
    case 1:{
        //medium filter
        for(int i = 0;i<255;i++){
            for(int j = 0;j<255;j++){
                if(i==0||i==255||j==0||j==255){
                    outputHeightData(i,j,0,0) = m_heightData(i,j,0,0);
                }else{
                    std::vector<int> curVec;
                    for(int m = -1;m<2;m++){
                        for(int n = -1;n<2;n++){
                            curVec.push_back(m_heightData(i+m,j+n,0,0));
                        }
                    }
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8 - i; j++){
                            if (curVec[i] > curVec[i+1]){
                                int temp = curVec[j];
                                curVec[j] = curVec[j + 1];
                                curVec[j + 1] = temp;
                            }
                        }
                    }
                    outputHeightData(i,j,0,0) = curVec[4];
                }
            }
        }
    }
    case 2:{
        // 2 : Gaussian
        double **gaus=new double *[3];
        for(int i = 0;i < 3;i++)
        {
            gaus[i] = new double[3];  //动态生成矩阵
        }
        const double PI=4.0 * atan(1.0); //圆周率π赋值
        int center = 1,sigma = 1;
        double sum=0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0;j<3;j++)
            {
                gaus[i][j]=(1/(2 * PI * sigma * sigma)) * exp(-((i-center)*(i-center)+(j-center)*(j-center))/(2*sigma*sigma));
                sum += gaus[i][j];
            }
        }
        for(int i= 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                gaus[i][j] /= sum;
            }
        }
        for(int i = 0;i < 255; i++){
            for(int j = 0; j < 255; j++){
                if(i==0||i==255||j==0||j==255){
                    outputHeightData(i,j,0,0) = m_heightData(i,j,0,0);
                }else{
                    outputHeightData(i,j,0,0) = m_heightData(i-1,j-1,0,0)*gaus[0][0]+m_heightData(i,j-1,0,0)*gaus[0][1]+m_heightData(i+1,j-1,0,0)*gaus[0][2]\
                            +m_heightData(i-1,j,0,0)*gaus[1][0]+m_heightData(i,j,0,0)*gaus[1][1]+m_heightData(i+1,j,0,0)*gaus[1][2]\
                            +m_heightData(i-1,j+1,0,0)*gaus[2][0]+m_heightData(i,j+1,0,0)*gaus[2][1]+m_heightData(i+1,j+1,0,0)*gaus[2][2];
                }
            }
        }
        break;
    }
    case 3:{
        // 3 : Butterworth
        //transform the image to complex
        Complex **complexImag = new Complex*[256];
        for (int i = 0; i < 256; i++) //making 3-dimensional table to store DFT values
        {
            complexImag[i] = new Complex[256];
        }

        for (int i=0; i<256; i++){
            for (int j=0; j<256; j++){
                Complex data(m_heightData(i,j,0,0), 0);
                complexImag[i][j] = data;
            }
        }

        //Discrete Fourier Transform
        // rows
        int dir = 1;
        double *real = new double[256], *imag = new double[256];
        for (int j=0;j<256;j++) {
            for (int i = 0; i < 256; i++) {
                real[i] = complexImag[i][j].real;
                imag[i] = complexImag[i][j].imag;
            }
            DFT(dir,real,imag);
            for (int i = 0; i < 256; i++) {
                complexImag[i][j].real = real[i];
                complexImag[i][j].imag = imag[i];
            }
        }

        // columns
        for (int i=0;i<256;i++) {
            for (int j=0;j<256;j++) {
                real[j] = complexImag[i][j].real;
                imag[j] = complexImag[i][j].imag;
            }
            DFT(dir,real,imag);
            for (int j=0;j<256;j++) {
                complexImag[i][j].real = real[j];
                complexImag[i][j].imag = imag[j];
            }
        }

        //compute the filter
        double **distData = new double*[256],**filterData = new double*[256];
        for (int i = 0; i < 256; i++)
        {
            distData[i] = new double[256];
            filterData[i] = new double[256];
        }
        for (int i=0;i<256;i++) {
            for (int j=0;j<256;j++) {
                distData[i][j] = sqrt((i-128)*(i-128)+(j-128)*(j-128));
            }
        }
        for (int i=0;i<256;i++) {
            for (int j=0;j<256;j++) {
                filterData[i][j] = 1/(1 + (sqrt(2.0) - 1)*pow((distData[i][j]/30),2));
                complexImag[i][j].real *= filterData[i][j];
                complexImag[i][j].imag *= filterData[i][j];
            }
        }

        //Inverse Discrete Fourier Transform
        dir = -1;
        //rows
        for (int j=0;j<256;j++) {
            for (int i = 0; i < 256; i++) {
                real[i] = complexImag[i][j].real;
                imag[i] = complexImag[i][j].imag;
            }
            DFT(dir,real,imag);
            for (int i = 0; i < 256; i++) {
                complexImag[i][j].real = real[i];
                complexImag[i][j].imag = imag[i];
            }
        }
        //columns
        for (int i=0;i<256;i++) {
            for (int j=0;j<256;j++) {
                real[j] = complexImag[i][j].real;
                imag[j] = complexImag[i][j].imag;
            }
            DFT(dir,real,imag);
            for (int j=0;j<256;j++) {
                complexImag[i][j].real = real[j];
                complexImag[i][j].imag = imag[j];
            }
        }
        //generate the latest image
        CImg<unsigned char> outData(256,256,1,1);
        for (int i=0;i<256;i++) {
            for (int j=0;j<256;j++) {
                outData(i,j,0,0) = sqrt(complexImag[i][j].real * complexImag[i][j].real \
                                         + complexImag[i][j].imag * complexImag[i][j].imag);
            }
        }
        break;
    }
    default:
        break;
    }
}

void Blur::infoCome(int type)
{
    _type = type;
    processHeightData();
}

void Blur::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void Blur::focusInEvent(QFocusEvent *event)
{
    focused = true;
    update();
    QGraphicsItem::focusInEvent(event);
}

void Blur::focusOutEvent(QFocusEvent *event)
{
    focused = false;
    update();
    QGraphicsItem::focusOutEvent(event);
}

