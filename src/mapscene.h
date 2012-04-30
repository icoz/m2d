#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include <QtGui>
#include "chunk.h"

class MapScene : public QGraphicsScene
{
public:
    MapScene(QString map_dir, QObject *parent = 0);
    void setPlayerPos(QPointF pos);
//    void loadMap();
//    void saveMap();
protected:
    void loadChunk(QString filename);
    void saveChunk(QString filename);

    //virtual void keyPressEvent ( QKeyEvent * keyEvent );

private:
    QString m_map_dir;
    //QMap<QPoint, Chunk*> chunks;
    Chunk* chunks[3][3];
    QPointF cur_pos;

    QPoint posToChunkCoords(QPointF pos);
};

#endif // MAPSCENE_H
