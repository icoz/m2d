#include "mapscene.h"

MapScene::MapScene(QString map_dir, QObject *parent)
    : QGraphicsScene (parent)
{
    this->m_map_dir = map_dir;
}

void MapScene::setPlayerPos(QPointF pos)
{
    cur_pos = pos;

}

void MapScene::loadChunk(QString filename)
{

}

QPoint MapScene::posToChunkCoords(QPointF pos)
{
    QPoint p;
    p.setX(qint32(pos.x()) % (CHUNK_SIZE*TEXTURE_SIZE));
    p.setY(qint32(pos.y()) % (CHUNK_SIZE*TEXTURE_SIZE));
    return p;
}

//void MapScene::keyPressEvent(QKeyEvent *keyEvent)
//{
//    switch (keyEvent->key()){
//    case Qt::Key_up:
//        //move player up
//        break;
//    }
//}
