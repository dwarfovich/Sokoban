#ifndef BOARDEDITOR_HPP
#define BOARDEDITOR_HPP

#include <QWidget>
#include <QScopedPointer>

QT_BEGIN_NAMESPACE
class QHBoxLayout;
class QVBoxLayout;
class QButtonGroup;
class QPixmap;
QT_END_NAMESPACE

class SokobanWidget;

class BoardEditor : public QWidget
{
    Q_OBJECT

public:
    explicit BoardEditor (QWidget* parent = 0);

public slots:
    void createNewLevel ();
    void setTile (const QPoint& location);

private: // methods
    void addTileButton (const QString& name);
    QIcon createIcon (int tile);

private: // data
    SokobanWidget* sokoban_widget_;
    QButtonGroup* tile_buttons_;
    QScopedPointer<QPixmap> sprites_;
    QScopedPointer<QPixmap> player_sprite_;
    QHBoxLayout* main_layout_;
    QVBoxLayout* buttons_layout_;
    int buttons_number_;
};

#endif // BOARDEDITOR_HPP
