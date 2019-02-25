#include "include/textureoutput.h"

TextureOutput::TextureOutput():Output(ITEM_TYPE::Texture_Output)
{
    focused = false;
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsFocusable,true);
}

QRectF TextureOutput::boundingRect() const
{
    return QRectF(0,0,150,70);
}

void TextureOutput::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ItemDrawMaster *drawMaster = new ItemDrawMaster(getType(),painter,focused);
    drawMaster->draw();
}

void TextureOutput::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

}

void TextureOutput::focusInEvent(QFocusEvent *event)
{

}

void TextureOutput::focusOutEvent(QFocusEvent *event)
{

}

