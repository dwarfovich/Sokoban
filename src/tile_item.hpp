#ifndef TILEITEM_HPP
#define TILEITEM_HPP

#include <QGraphicsItem>
#include <QScopedPointer>
#include "board.hpp"

class TileItem : public QGraphicsItem
{
public:
    TileItem ();

    QRectF boundingRect () const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setTileLocation (const QPoint& location);
    const QPoint& tileLocation() const;
    void setTile (Tile tile);
    static qreal size ();

private:
    struct Initializer { Initializer(); };
    static QScopedPointer<QPixmap> tile_sprites_;
    QPoint tile_location_;
    int sprite_offset_;
    Tile tile_;
};

#endif // TILEITEM_HPP
