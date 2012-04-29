#include "chunk.h"
#include <QFile>
#include <QDataStream>
#include <QtGui>

Chunk::Chunk(QString file, QPoint pos, QGraphicsItem *parent)
    :QGraphicsItemGroup(parent)
{
    this->m_file = file;
    m_x = pos.x();
    m_y = pos.y();
    loadMap();
}

Chunk::~Chunk()
{
    saveMap();
}

Block *Chunk::blockAtRelPos(QPoint p)
{
//    Block *b = blocks.value(p);
    if ((this->scene())){
        Block *b = dynamic_cast<Block*> ((this->scene())->itemAt(mapToScene(p)));
        if (b){
            return b;
        }
    }else{
        Block *b;
        foreach (b, blocks){
            if (b->pos() == p)
                return b;
        }
    }
    return NULL;
}

Block *Chunk::blockAtAbsPos(QPointF p)
{
    QGraphicsItem *gi = (this->scene())->itemAt(p);
    Block *b = dynamic_cast<Block*> (gi);
    if (b){
        return b;
    }
    return NULL;
}

void Chunk::loadMap()
{
    QFile fin(m_file);
    blocks.clear();
    if (!fin.exists()){
        generateMap();
        return;
    }
    if (fin.open(QIODevice::ReadOnly)){
        QDataStream in(&fin);
        in >> m_x >> m_y;   // load Chunk position
        qint32 count,block_type,x,y;
        in >> count;        // load Chunk blocks count
        Block *b;
        for (qint32 i=0; i < count; i++){
            in >> block_type >> x >> y;
            b = new Block(BlockType(block_type),QPointF(x, y));
            this->addToGroup(b);
//            blocks.insert(QPoint(x,y),b);
            blocks.append(b);
        }
        fin.close();
        this->setPos(m_x,m_y);
    }
}

void Chunk::saveMap()
{
    QFile fout(m_file);
    if (fout.open(QIODevice::WriteOnly)){
        QDataStream out(&fout);
        out << m_x << m_y << blocks.size();
        Block *b;
        foreach (b, blocks){
            out << qint32(b->m_block_type); // save BlockType
            out << qint32(b->x());
            out << qint32(b->y());
        }
        fout.close();
    }
}

void Chunk::generateMap()
{
    qint32 count = qrand() % (64*64);
    Block *b;
    QPoint p;
    for (qint32 i = 0; i < count; i++){
        do { p = QPoint(qrand()%64 * 16, qrand()%64 * 16);}
        while (blockAtRelPos(p)) ;//check block at P
        b = new Block(BlockType(qrand()%(qint32(LastBlock)-1)),p);
//        blocks.insert(p,b);
        blocks.append(b);
        this->addToGroup(b);
    }
}
