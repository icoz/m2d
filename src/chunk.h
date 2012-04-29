#ifndef CHUNK_H
#define CHUNK_H

#include <QGraphicsItemGroup>
#include "block.h"

class Chunk : public QGraphicsItemGroup
{
public:
    explicit Chunk(QString file, QPoint pos = QPoint(0,0), QGraphicsItem *parent = 0);
    ~Chunk();
    Block* blockAtRelPos(QPoint);
    Block* blockAtAbsPos(QPointF);
signals:
    
public slots:
protected:
    QList<Block*> blocks;
    QString m_file;
    qint32 m_x;
    qint32 m_y;

    void loadMap();
    void saveMap();
    void generateMap();
};

#endif // CHUNK_H
