#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>

class MapScene : public QGraphicsScene
{
public:
    MapScene(QString map_dir, QObject *parent = 0);
//    void loadMap();
    void saveMap();
protected:
    void loadChunk(QString filename);
    void saveChunk(QString filename);
};

#endif // MAPSCENE_H
