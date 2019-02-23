#include "include/layoutwidget.h"
#include "ui_layoutwidget.h"

LayoutWidget::LayoutWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LayoutWidget)
{
    ui->setupUi(this);

//    QToolBar *bar = addToolBar("Tools");
//    QActionGroup *group = new QActionGroup(bar);

//    QAction *drawLineAction = new QAction("Line", bar);
//    drawLineAction->setIcon(QIcon(":/line.png"));
//    drawLineAction->setToolTip(tr("Draw a line."));
//    drawLineAction->setCheckable(true);
//    drawLineAction->setChecked(true);
//    group->addAction(drawLineAction);
//    bar->addAction(drawLineAction);

//    QAction *drawRectAction = new QAction("Rectangle", bar);
//    drawRectAction->setIcon(QIcon(":/rect.png"));
//    drawRectAction->setToolTip(tr("Draw a rectangle."));
//    drawRectAction->setCheckable(true);
//    group->addAction(drawRectAction);
//    bar->addAction(drawRectAction);

//    PaintWidget *paintWidget = new PaintWidget(this);
//    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
//    layout->addWidget(paintWidget);
//    this->setLayout(layout);

//    connect(drawLineAction, SIGNAL(triggered()),
//            this, SLOT(drawLineActionTriggered()));
//    connect(drawRectAction, SIGNAL(triggered()),
//            this, SLOT(drawRectActionTriggered()));
    connect(this, SIGNAL(changeCurrentShape(Shape::Code)),
            ui->paint_Widget, SLOT(setCurrentShape(Shape::Code)));
}

LayoutWidget::~LayoutWidget()
{
    delete ui;
}

void LayoutWidget::on_line_BT_clicked()
{
    emit changeCurrentShape(Shape::Line);
}

void LayoutWidget::on_rec_BT_clicked()
{
    emit changeCurrentShape(Shape::Rect);
}

void LayoutWidget::on_generate_BT_clicked()
{
    ui->paint_Widget->saveBMP();
}
