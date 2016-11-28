#include "tile_item.hpp"
#include <QPainter>

QScopedPointer<QPixmap> TileItem::tile_sprites_{nullptr};

TileItem::TileItem()
{
    static Initializer initializer;
    setZValue(1);
//    setAcceptHoverEvents(true);
    this->setFlag(ItemIsFocusable,true);
}

QRectF TileItem::boundingRect() const
{
    return {0., 0., size(), size()};
}

void TileItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->drawPixmap(boundingRect(),
                        *tile_sprites_,
                        {sprite_offset_ * size(), 0., size(), size()});
}

void TileItem::setTileLocation(const QPoint& location)
{
    tile_location_ = location;
}

void TileItem::setTile(Tile tile)
{
    tile_ = tile;
    sprite_offset_ = int(tile_) + 1; // First Tile has value -1, so adding 1
    update();
}

qreal TileItem::size()
{
    return tile_sprites_->height();
}

const QPoint& TileItem::tileLocation () const
{
    return tile_location_;
}

TileItem::Initializer::Initializer()
{
    tile_sprites_.reset(new QPixmap {":/resources/tiles.png"});
}
