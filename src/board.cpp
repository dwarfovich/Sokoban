#include "board.hpp"
#include <QDataStream>
#include <QRect>
#include <iostream>

QDataStream& operator<< (QDataStream& stream, const Tile& tile)
{
    stream << int(tile);
    return stream;
}

QDataStream& operator>> (QDataStream& stream, Tile& tile)
{
    int c;
    stream >> c;
    tile = Tile(c);
    return stream;
}

QDataStream& operator<< (QDataStream& stream, const Board& board)
{
    stream << board.boxes_;
    stream << board.arranged_boxes_;
    stream << board.targets_;
    stream << board.field_.size();
    for (const auto& v : board.field_)
        stream << v;
    stream << board.player_location_;
    return stream;
}

QDataStream& operator>> (QDataStream& stream, Board& board)
{
    stream >> board.boxes_;
    stream >> board.arranged_boxes_;
    stream >> board.targets_;
    int size;
    stream >> size;
    board.field_.resize(size);
    for (auto& v : board.field_)
        stream >> v;
    stream >> board.player_location_;
    return stream;
}

Board::Board(QObject* parent)
    : QObject{parent}
    , field_{}
    , boxes_{0}
    , arranged_boxes_{0}
    , targets_{0}
    , player_location_{0, 0}
{}

Board::~Board()
{}

bool Board::movePlayer(Direction direction)
{
    auto next_location = adjacentLocation(player_location_, direction);
    if (next_location.x() == -1)
        return false;

    if (isFreeTile(next_location)) {
        player_location_ = next_location;
        emit playerMoved(player_location_);
        return true;
    }

    if (isTileWithBox(next_location))
        if (pushBlock(next_location, direction)) {
            player_location_ = next_location;
            emit playerMoved(player_location_);
            return true;
        }

    return false;
}

bool Board::pushBlock(const QPoint& location, Direction direction)
{
    auto adjacent_location = adjacentLocation(location, direction);
    if (!isTileWithBox(location) || !isFreeTile(adjacent_location))
        return false;
    setBox(location, false);
    setBox(adjacent_location, true);
    emit tilesChanged(location, tile(location));
    emit tilesChanged(adjacent_location, tile(adjacent_location));
    if (arranged_boxes_ == targets_) {
        emit allBoxesArranged();
    }
    return true;
}

void Board::setTile(const QPoint& location, Tile tile)
{
    if (isProperLocation(location)) {
        field_[location.y()][location.x()] = tile;
        emit tilesChanged(location, tile);
    }
}

void Board::setBox(const QPoint& location, bool box)
{
    Tile& tile = field_[location.y()][location.x()];
    if (box) {
        if (tile == Tile::Empty) {
            tile = Tile::Box;
            ++boxes_;
        }
        else if (tile == Tile::Target) {
            tile = Tile::ArrangedBox;
            ++arranged_boxes_;

        }
    } else {
        if (tile == Tile::Box) {
            tile = Tile::Empty;
            --boxes_;
        }
        else if (tile == Tile::ArrangedBox) {
            tile = Tile::Target;
            --arranged_boxes_;
        }
    }
}

void Board::initializeEmptyField(int width, int height)
{
    field_.resize(height);
    for (auto& row : field_) {
        row.resize(width);
        row.fill(Tile::Empty);
    }
}

bool Board::isProperLocation(const QPoint& location) const
{
    return (location.x() >= 0 && location.x() < width()
            && location.y() >= 0 && location.y() < height());
}

bool Board::isFreeTile(const QPoint& location) const
{
    return (tile(location) == Tile::Empty || tile(location) == Tile::Target);
}

bool Board::isTileWithBox(const QPoint& location) const
{
    return (tile(location) == Tile::Box || tile(location) == Tile::ArrangedBox);
}

QPoint Board::adjacentLocation(const QPoint& location, Direction direction) const
{
    if (!isProperLocation(location))
        return {-1, -1};
    if (direction == Direction::Left && location.x() > 0)
        return {location.x() - 1, location.y()};
    else if (direction == Direction::Up && location.y() > 0)
        return {location.x(), location.y() - 1};
    else if (direction == Direction::Right && location.x() + 1 < width())
        return {location.x() + 1, location.y()};
    else if (direction == Direction::Down && location.y() + 1 < height())
        return {location.x(), location.y() + 1};
    else
        return {-1, -1};
}

Tile Board::tile (const QPoint& location) const
{
    if (isProperLocation(location))
        return field_[location.y()][location.x()];
    else
        return Tile::Error;
}

void Board::countBoxes ()
{
    boxes_ = 0;
    arranged_boxes_ = 0;
    for (int i = 0; i < height(); ++i)
        for (int j = 0; j < width(); ++j)
            if (field_[i][j] == Tile::Box)
                ++boxes_;
            else if (field_[i][j] == Tile::ArrangedBox)
                ++arranged_boxes_;
            else if (field_[i][j] == Tile::Target)
                ++targets_;
}

int Board::width () const
{
    return (height() > 0 ? field_[0].size() : 0);
}

int Board::height() const
{
    return field_.size();
}

const TileMatrix& Board::field() const
{
    return field_;
}

int Board::boxes() const
{
    return boxes_;
}

int Board::arrangedBoxes() const
{
    return arranged_boxes_;
}

const QPoint& Board::playerLocation() const
{
    return player_location_;
}

bool Board::setPlayerLocation(const QPoint& player_location)
{
    if (!isProperLocation(player_location) || !isFreeTile(player_location))
        return false;
    player_location_ = player_location;
    emit playerMoved(player_location_);
    return true;
}
