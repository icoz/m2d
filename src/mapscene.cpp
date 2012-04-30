#include "mapscene.h"

MapScene::MapScene(QString map_dir, QObject *parent)
    : QGraphicsScene (parent)
{
    this->m_map_dir = map_dir;
    centralChunk = QPoint(0,0);
    for (int i=-1; i <= 1; i++)
        for (int j =-1; j <= -1; j++){
            loadChunk(QPoint(i,j));
        }
}

void MapScene::setPlayerPos(QPointF pos)
{
    cur_pos = pos;
    //check if player is in central chunk
    QPoint playerChunk = posToChunkCoords(pos);
    if (playerChunk != centralChunk){
        //if not, then load next chunks
        //... and unload unused chunks
        QPoint ch, del;
        foreach (ch, chunks.keys()){
            del = playerChunk - ch;
            if ((abs(del.x()) > 1) || (abs(del.y()) > 1))
                unloadChunk(del);
        }
        for (int i=-1; i <= 1; i++)
            for (int j =-1; j <= -1; j++){
                loadChunk(playerChunk+QPoint(i,j));
            }
        centralChunk = playerChunk;
    }
}

void MapScene::loadChunk(QPoint p)
{
    // if already loaded return
    if (chunks.contains(p)) return;
    //gen chunk name
    QString ch_name = m_map_dir+QString("ch_%1_%2.chunk").arg(p.x()).arg(p.y());
    //load chunk
    Chunk *c = new Chunk(ch_name,p);
    //save it in map and add it to scene
    chunks.insert(p,c);
    this->addItem(c);
}

void MapScene::unloadChunk(QPoint p)
{
    // if already unloaded return
    if (!chunks.contains(p)) return;
    Chunk* c = chunks.take(p);
    removeItem(c);
    delete c;
}

QPoint MapScene::posToChunkCoords(QPointF abs_pos)
{
    QPoint p;
    p.setX(qint32(abs_pos.x()) % (CHUNK_SIZE*TEXTURE_SIZE));
    p.setY(qint32(abs_pos.y()) % (CHUNK_SIZE*TEXTURE_SIZE));
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
