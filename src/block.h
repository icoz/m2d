#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include "block_types.h"

class Block : public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Block(BlockType bt,QObject *parent = 0);

signals:

public slots:

};

#endif // BLOCK_H
