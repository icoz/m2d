#include "block.h"

Block::Block(BlockType bt, QObject *parent) :
    QGraphicsItem(parent)
{
    switch (bt){
    case Dirt:
        this->setPixmap(":/block/dirt.png");
        break;
    case Stone:
        this->setPixmap(":/block/stone.png");
        break;
    case Gold:
        this->setPixmap(":/block/gold.png");
        break;
    default:
        this->setPixmap(":/block/unknown.png");
        break;
    }
}
