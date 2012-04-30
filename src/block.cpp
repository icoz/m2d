#include "block.h"

Block::Block(BlockType bt, QPointF pos, QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    this->setPos(pos);
    m_block_type = bt;
    switch (bt){
    case Dirt:
        this->setPixmap(QPixmap(":/block/dirt.png"));
        break;
    case Gobble:
        this->setPixmap(QPixmap(":/block/gobble.png"));
        break;
    case Stone:
        this->setPixmap(QPixmap(":/block/stone.png"));
        break;
    case Gold:
        this->setPixmap(QPixmap(":/block/gold.png"));
        break;
    case Iron:
        this->setPixmap(QPixmap(":/block/iron.png"));
        break;
    default:
        this->setPixmap(QPixmap(":/block/unknown.png"));
        break;
    }
}
