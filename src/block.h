#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>
#include "block_types.h"

class Block : public QGraphicsPixmapItem
{
public:
    explicit Block(BlockType bt,QPointF pos = QPointF(0,0), QGraphicsItem *parent = 0);
};

#endif // BLOCK_H
