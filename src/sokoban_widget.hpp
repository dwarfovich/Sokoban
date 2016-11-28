#ifndef SOKOBANWIDGET_HPP
#define SOKOBANWIDGET_HPP

#include "direction_enum.hpp"
#include "board.hpp"
#include <QWidget>
#include <QScopedPointer>

QT_BEGIN_NAMESPACE
class QGraphicsView;
class QGraphicsScene;
class QGraphicsPixmapItem;
QT_END_NAMESPACE

class SokobanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SokobanWidget (QWidget *parent = 0);

    Board* board ();
    void setBoard (Board* board);
    void createBoard (int width, int height);

    void loadTestBoard ();

public slots:
    void loadBoard ();
    void saveBoard ();

    void updateTile (const QPoint& location, Tile tile);
    void updatePlayerLocation (const QPoint& location);
    void drawBoard ();
    void movePlayer (Direction direction);

signals:
    void tileClicked (const QPoint& location);
    void playerWin ();

protected:
    void mousePressEvent (QMouseEvent* event);
    void keyPressEvent (QKeyEvent* event);

private:
    QGraphicsView* view_;
    QGraphicsScene* scene_;
    Board* board_;
    QGraphicsPixmapItem* player_sprite_;
};

#endif // SOKOBANWIDGET_HPP
