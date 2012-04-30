#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include <QtGui>
#include <QtCore>
#include "chunk.h"
#include "chunkmap.h"

class MapScene : public QGraphicsScene
{
public:
    MapScene(QString map_dir, QObject *parent = 0);
    void setPlayerPos(QPointF pos);
//    void loadMap();
//    void saveMap();
protected:
    void loadChunk(QPoint p);
    void unloadChunk(QPoint p);

    //virtual void keyPressEvent ( QKeyEvent * keyEvent );

private:
    QString m_map_dir;
    ChunkMap chunks;
    //Chunk* chunks[3][3];

    QPointF cur_pos;
    QPoint centralChunk;

    QPoint posToChunkCoords(QPointF pos);
    int chunkPointToInt(QPoint p);
};

#endif // MAPSCENE_H
