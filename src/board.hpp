#ifndef BOARD_HPP
#define BOARD_HPP

#include "tile_enum.hpp"
#include "direction_enum.hpp"
#include <QObject>
#include <QVector>
#include <QPoint>

using TileVector = QVector<Tile>;
using TileMatrix = QVector<TileVector>;

class Board : public QObject
{
    Q_OBJECT

public:
    explicit Board (QObject* parent = 0);
    ~Board ();
    friend QDataStream& operator<< (QDataStream& stream, const Board& board);
    friend QDataStream& operator>> (QDataStream& stream, Board& board);

    const TileMatrix& field () const;
    void initializeEmptyField (int width, int height);
    int width () const;
    int height () const;

    int boxes() const;
    int arrangedBoxes() const;

    bool isProperLocation (const QPoint& location) const;
    QPoint adjacentLocation (const QPoint& location, Direction direction) const;
    bool movePlayer (Direction direction);
    bool setPlayerLocation (const QPoint& player_location);
    const QPoint& playerLocation () const;

    void setTile (const QPoint& location, Tile tile);
    Tile tile (const QPoint& location) const;
    void countBoxes ();

signals:
    void playerMoved (const QPoint& location);
    void tilesChanged (const QPoint& location, Tile tile);
    void allBoxesArranged ();

private: // methods
    bool pushBlock (const QPoint& location, Direction direction);
    void setBox (const QPoint& location, bool box);
    bool isFreeTile (const QPoint& location) const;
    bool isTileWithBox (const QPoint& location) const;

private: // data
    TileMatrix field_;
    int boxes_;
    int arranged_boxes_;
    int targets_;
    QPoint player_location_;
};

#endif // BOARD_HPP
