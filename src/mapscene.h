#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include <QtGui>
#include "chunk.h"

class MapScene : public QGraphicsScene
{
public:
    MapScene(QString map_dir, QObject *parent = 0);
//    void loadMap();
//    void saveMap();
protected:
    void loadChunk(QString filename);
    void saveChunk(QString filename);
private:
    QString m_map_dir;
    QMap<QPoint, Chunk*> chunks;
};

#endif // MAPSCENE_H
