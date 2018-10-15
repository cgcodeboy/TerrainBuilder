#include "include/mainview.h"

MainView::MainView(QWidget *parent):QGraphicsView(parent)
{
    cur_type = Arrow;

    connectState = false;

    scene = new QGraphicsScene(this);

    itembuilder = new ItemFactory;

    scene->setBackgroundBrush(QBrush(QColor(100,100,100)));

    scene->setSceneRect(0,0,2000,2000);

    this->setScene(scene);
}

QGraphicsScene *MainView::getScene() const
{
    return scene;
}

void MainView::setCur_type(const ITEM_TYPE value)
{
    cur_type = value;
    if(cur_type == ITEM_TYPE::Connect){
        startItem = nullptr;
        endItem = nullptr;
    }
}

/*brief: So many bugs!!! wait to correct the logic!
 *       When click a item, if it's connect status, we should connect two item together.
 */
void MainView::mousePressEvent(QMouseEvent *event)
{
    //如果是右键点击，说明放弃当前
    if(event->button() == Qt::RightButton){
        foreach (QGraphicsItem* item, scene->items(Qt::AscendingOrder)) {
            item->setFlag(QGraphicsItem::ItemIsMovable,true);
        }
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        setCur_type(ITEM_TYPE::Arrow);
        return;
    }
    if(cur_type == ITEM_TYPE::Connect){
        if(!startItem){
            QPoint point = event->pos();
//            qDebug()<<"start"<<point.x()<<point.y();
            //wait to correct!!
            startItem = dynamic_cast<Item*>(scene->itemAt(QPoint(point.x(),point.y()),QTransform()));
            QGraphicsView::mousePressEvent(event);
            return;
        }
//        qDebug()<<"hello";
        if(!endItem){
            QPoint point = event->pos();
//            qDebug()<<"end"<<point.x()<<point.y();
            //wait to correct!!
            endItem = dynamic_cast<Item*>(scene->itemAt(QPoint(point.x(),point.y()),QTransform()));
            if(endItem){
                if(startItem!=endItem){
                    //                    if(startItem->pos().x()<endItem->pos().x()){
                    //                        if(startItem->pos().y()<endItem->pos().y()){

                    //                        }
                    //                    }
                    QPoint startPoint(startItem->pos().x()+50,startItem->pos().y()+25);
                    QPoint endPoint(endItem->pos().x()+50,endItem->pos().y()+25);
//                    QPoint midPoint;
//                    if(abs(startPoint.x() - endPoint.x())>abs(startPoint.y() - endPoint.y())){
//                        midPoint.setX(endPoint.x());
//                        midPoint.setY(startPoint.y());
//                    }else{
//                        midPoint.setX(startPoint.x());
//                        midPoint.setY(endPoint.y());
//                    }
                    QPoint controlPoint_1,controlPoint_2;
                    controlPoint_1.setX((startPoint.x()+endPoint.x())/2);
                    controlPoint_2.setX((startPoint.x()+endPoint.x())/2);
                    controlPoint_1.setY(startPoint.y());
                    controlPoint_2.setY(endPoint.y());
//                    if(startPoint.x()<endPoint.x()){

//                    }
//                    else{
//                        controlPoint_1.setY(endPoint.y());
//                        controlPoint_2.setY(startPoint.y());
//                    }
                    BezierLine *line = new BezierLine(startPoint,endPoint,controlPoint_1,controlPoint_2);
                    scene->addItem(line);
                    startItem = nullptr;
                    endItem = nullptr;
                }
                else{
                    endItem = nullptr;
                }
            }
            QGraphicsView::mousePressEvent(event);
            return;
        }
    }

    QPoint point = event->pos();
    switch (cur_type) {
    case ITEM_TYPE::Constant_Generator:{
//        qDebug()<<point.x()<<point.y();
        addItem(ITEM_TYPE::Constant_Generator,point.x(), point.y());
        break;
    }
    case ITEM_TYPE::Gradient_Generator:{
        addItem(ITEM_TYPE::Gradient_Generator,point.x(),point.y());
        break;
    }
    case ITEM_TYPE::Perlin_Generator:{
        addItem(ITEM_TYPE::Perlin_Generator,point.x(),point.y());
        break;
    }
    case ITEM_TYPE::Layout_Generator:{
        addItem(ITEM_TYPE::Layout_Generator,point.x(),point.y());
        break;
    }
    case ITEM_TYPE::Radial_Generator:{
        addItem(ITEM_TYPE::Radial_Generator,point.x(),point.y());
        break;
    }
    case ITEM_TYPE::Voronoi_Generator:{
        addItem(ITEM_TYPE::Voronoi_Generator,point.x(),point.y());
        break;
    }
    default:
        QGraphicsView::mousePressEvent(event);
        break;
    }
}

void MainView::initBluePrint()
{
//    for(int j = 0;j<4;j++)
//    {
//        addItem(ITEM_TYPE::Constant_Generator,0,j*60);
//    }
//    for(int j = 0;j<4;j++)
//    {
//        addItem(ITEM_TYPE::Perlin_Generator,80,j*60);
//    }
//    for(int j = 0;j<4;j++)
//    {
//        addItem(ITEM_TYPE::Layout_Generator,160,j*60);
//    }
//    for(int j = 0;j<4;j++)
//    {
//        addItem(ITEM_TYPE::Gradient_Generator,240,j*60);
//    }
}

void MainView::addItem(ITEM_TYPE type,int x,int y)
{
    Item *item = itembuilder->buildItem(type,x,y);
    scene->addItem(item);
}

