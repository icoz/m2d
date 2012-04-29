#include "mapscene.h"

MapScene::MapScene(QString map_dir, QObject *parent)
    : QGraphicsScene (parent)
{
    this->m_map_dir = map_dir;
}

void MapScene::loadChunk(QString filename)
{

}
