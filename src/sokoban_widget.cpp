#include "sokoban_widget.hpp"
#include "tile_item.hpp"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QPointF>

#include <QDebug>
#define DEB qDebug()

SokobanWidget::SokobanWidget(QWidget* parent)
    : QWidget{parent}
    , view_{new QGraphicsView}
    , scene_{new QGraphicsScene}
    , board_{nullptr}
    , player_sprite_{nullptr}
{
    view_->setScene(scene_);
    QMatrix matrix;
        matrix.scale(0.5, 0.5);
    view_->setMatrix(matrix);
//    view_->setDragMode(QGraphicsView::ScrollHandDrag);
    setLayout(new QHBoxLayout);
    layout()->addWidget(view_);
    if (!player_sprite_)
        player_sprite_ = new QGraphicsPixmapItem {QString{":/resources/player.png"}};
    player_sprite_->setZValue(2);
    scene_->addItem(player_sprite_);
}

void SokobanWidget::drawBoard()
{
    scene_->clear();
    int height = board_->height();
    int width = board_->width();
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j) {
            auto tile = board_->tile({j, i});
            TileItem* item = new TileItem ();
            item->setTile(tile);
            item->setPos(j * TileItem::size(), i * TileItem::size());
            item->setTileLocation({j, i});
            scene_->addItem(item);
        }
    player_sprite_ = new QGraphicsPixmapItem {QString{":/resources/player.png"}};
    player_sprite_->setZValue(2);
    scene_->addItem(player_sprite_);
    updatePlayerLocation(board_->playerLocation());
    scene_->setSceneRect(QRectF());
}

void SokobanWidget::loadTestBoard ()
{
    QString filename = "/home/boo/level.sl";
    if (filename.isEmpty())
        return;
    else {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        QDataStream stream (&file);
        stream.setVersion(QDataStream::Qt_DefaultCompiledVersion);
        Board* board = new Board;
        stream >> *board;
        setBoard(board);
        drawBoard();
    }
}

void SokobanWidget::movePlayer(Direction direction)
{
    board_->movePlayer(direction);
}

void SokobanWidget::mousePressEvent(QMouseEvent* event)
{
    auto item = qgraphicsitem_cast<TileItem*> (scene_->focusItem());
    if (item)
        emit tileClicked(item->tileLocation());
    QWidget::mousePressEvent(event);
}

void SokobanWidget::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_Left  : board_->movePlayer(Direction::Left);  break;
    case Qt::Key_Up    : board_->movePlayer(Direction::Up);    break;
    case Qt::Key_Right : board_->movePlayer(Direction::Right); break;
    case Qt::Key_Down  : board_->movePlayer(Direction::Down);  break;
    default: break;
    }
    QWidget::keyPressEvent(event);
}

Board* SokobanWidget::board()
{
    return board_;
}

void SokobanWidget::setBoard(Board* board)
{
    delete board_;
    board_ = board;
    board_->setParent(this);
//    drawBoard();
    connect(board_, &Board::playerMoved,
            this, &SokobanWidget::updatePlayerLocation);
    connect(board_, &Board::tilesChanged,
            this, &SokobanWidget::updateTile);
    connect(board_, &Board::allBoxesArranged,
            this, &SokobanWidget::playerWin);
}

void SokobanWidget::createBoard(int width, int height)
{
    if (board_ == nullptr)
        setBoard(new Board);
    board_->initializeEmptyField(width, height);
    drawBoard();
}

void SokobanWidget::loadBoard()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Load level",
                                                    "/home/boo/level.sl",
                                                    "Level (*.sl)");
    if (filename.isEmpty())
        return;
    else {
        QFile file {filename};
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, "Unable to open file",
                                     file.errorString());
            return;
        }
        QDataStream stream {&file};
        stream.setVersion(QDataStream::Qt_DefaultCompiledVersion);
        if (board_ == nullptr) {
            Board* board = new Board;
            setBoard(board);
        }
        stream >> *board_;
        drawBoard();
    }
}

void SokobanWidget::saveBoard()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    "Save level",
                                                    "/home/boo/level.sl",
                                                    "Level (*.sl)");
    if (filename.isEmpty())
        return;
    else {
        QFile file {filename};
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, "Unable to open file",
                                     file.errorString());
            return;
        }
        board_->countBoxes();
        QDataStream stream {&file};
        stream.setVersion(QDataStream::Qt_DefaultCompiledVersion);
        stream << *board_;
    }
}

void SokobanWidget::updateTile(const QPoint& location, Tile tile)
{
    auto item = scene_->itemAt(location * TileItem::size(), QTransform{});
    auto tile_item = qgraphicsitem_cast<TileItem*> (item);
    if (tile_item != 0) {
        tile_item->setTile(tile);
        tile_item->update();
    }
}

void SokobanWidget::updatePlayerLocation(const QPoint& location)
{
    player_sprite_->setPos(location * TileItem::size());
    view_->centerOn(player_sprite_);
}
