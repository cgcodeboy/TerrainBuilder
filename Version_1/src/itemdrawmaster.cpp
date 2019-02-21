#include "include/itemdrawmaster.h"

ItemDrawMaster::ItemDrawMaster(ITEM_TYPE type, QPainter *painter, bool focused)
{
    _painter = painter;
    _type = type;
    _focused = focused;
}

void ItemDrawMaster::draw()
{
    QDomDocument doc("mydocument");
    QFile file(":/xml/resource/xml/item.xml");
    if (!file.open(QIODevice::ReadOnly)){
        qDebug()<<"file error";
        return;
    }
    if (!doc.setContent(&file)) {
        qDebug()<<"doc error";
        file.close();
        return;
    }
    file.close();

    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement();
        if(!e.isNull()) {
            QDomNode node = e.firstChild();
            if(!node.isNull()){
                if(node.toElement().text()== getElemTypeName(_type)){
                    QDomNode input = node.nextSibling();
                    QDomNodeList inputList = input.childNodes();
                    QDomNode output = input.nextSibling();
                    QDomNodeList outputList = output.childNodes();
                    if(_focused){
                        _painter->setPen(Qt::green);
                        QRectF rec(0,0,150,50+(inputList.size()>outputList.size()?inputList.size():outputList.size())*20);
                        _painter->drawRect(rec);
                        QBrush brush(QColor(255,0,0,100));
                        _painter->fillRect(rec,brush);
                        return;
                    }

                    QRectF rec_1(0,0,150,50);
                    QImage image(":/image/resource/image/item/perlin.jpg");
                    _painter->drawImage(rec_1,image);
                    QRectF rec;
                    if(inputList.size()>=outputList.size()){
                        rec.setRect(0,50,150,20*inputList.size());

                    }
                    else{
                        rec.setRect(0,50,150,20*outputList.size());
                    }
                    QBrush brush(QColor(30,40,50,50));
                    _painter->fillRect(rec,brush);

                    for(int i = 0;i<inputList.size();i++){
                        QDomNode inputAttri = inputList.at(i);
                        if(!inputAttri.isNull()){
                            QDomNode nameNode = inputAttri.firstChild();
                            QDomNode typeNode = nameNode.nextSibling();
                            if(typeNode.toElement().text() == "Integer"){
                                _painter->setPen(Qt::green);
                                _painter->drawEllipse(5,60+i*20,5,5);
                                _painter->drawText(15,60+i*20,nameNode.toElement().text());
                            }
                        }
                    }

                    for(int i = 0;i<outputList.size();i++){
                        QDomNode outputAttri = outputList.at(i);
                        if(!outputAttri.isNull()){
                            QDomNode nameNode = outputAttri.firstChild();
                            QDomNode typeNode = nameNode.nextSibling();
                            if(typeNode.toElement().text() == "Integer"){
                                QPen pen;
                                pen.setColor(Qt::green);
                                pen.setWidth(1);
                                _painter->setPen(pen);
                                _painter->drawEllipse(140,60+i*20,5,5);
                                _painter->drawText(80,60+i*20,nameNode.toElement().text());
                            }
                        }
                    }
                }
            }
        }
        n = n.nextSibling();
    }
}

