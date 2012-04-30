#ifndef CHUNKMAP_H
#define CHUNKMAP_H

#include <QPoint>
#include "chunk.h"

class ChunkMap
{
public:
    ChunkMap();
    QList<QPoint> keys() const {return points;}
    QList<Chunk*> values() const {return chunks;}
    Chunk* take(QPoint p) {
        Chunk* c = value(p);
        remove(p);
        return c;
    }
    void insert(QPoint p, Chunk* c){
        points.append(p);
        chunks.append(c);
    }
    void remove(QPoint p){
        int idx = points.indexOf(p);
        points.removeAt(idx);
        chunks.removeAt(idx);
    }
    Chunk* value(QPoint p){
        return chunks.at(points.indexOf(p));
    }
    bool contains(QPoint p){
        return points.contains(p);
    }
protected:
    QList<QPoint> points;
    QList<Chunk*> chunks;
};

#endif // CHUNKMAP_H
