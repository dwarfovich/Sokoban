#include "board_editor.hpp"
#include "board.hpp"
#include "sokoban_widget.hpp"
#include "new_level_dialog.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QMouseEvent>
#include <QMessageBox>

BoardEditor::BoardEditor (QWidget* parent)
    : QWidget{parent}
    , sokoban_widget_{new SokobanWidget}
    , tile_buttons_{new QButtonGroup {this}}
    , sprites_{new QPixmap {":/resources/tiles.png"}}
    , player_sprite_{new QPixmap {":/resources/player.png"}}
    , main_layout_ {new QHBoxLayout}
    , buttons_layout_ {new QVBoxLayout}
    , buttons_number_{0}
{
    if (parent == 0)
        setAttribute(Qt::WA_DeleteOnClose, true);
    setGeometry(300, 300, 1000, 500);
    setLayout(main_layout_);
    main_layout_->addWidget(sokoban_widget_);

    connect(sokoban_widget_, &SokobanWidget::tileClicked,
            this, &BoardEditor::setTile);
    // Buttons
    main_layout_->addLayout(buttons_layout_);
    addTileButton("Background");
    addTileButton("Empty");
    addTileButton("Target");
    addTileButton("Wall");
    addTileButton("Box");
    addTileButton("ArrangedBox");
    addTileButton("Player");

    QPushButton* new_button = new QPushButton {"New"};
    buttons_layout_->addWidget(new_button);
    connect(new_button, &QPushButton::clicked,
            this, &BoardEditor::createNewLevel);
    QPushButton* load_button = new QPushButton {"Load"};
    buttons_layout_->addWidget(load_button);
    connect(load_button, &QPushButton::clicked,
            sokoban_widget_, &SokobanWidget::loadBoard);
    QPushButton* save_button = new QPushButton {"Save"};
    buttons_layout_->addWidget(save_button);
    connect(save_button, &QPushButton::clicked,
            sokoban_widget_, &SokobanWidget::saveBoard);
    buttons_layout_->addStretch(1);
}

void BoardEditor::createNewLevel()
{
    NewLevelDialog* dlg = new NewLevelDialog {this};
    if (dlg->exec()) {
        sokoban_widget_->createBoard(dlg->fieldWidth(),  dlg->fieldHeight());
    }
}

void BoardEditor::setTile (const QPoint& location)
{
    int checked_id = tile_buttons_->checkedId();
    if (checked_id < 6) {
        Tile selected_tile = Tile(tile_buttons_->checkedId());
        sokoban_widget_->board()->setTile(location, selected_tile);
    } else
        sokoban_widget_->board()->setPlayerLocation(location);
}

void BoardEditor::addTileButton(const QString& name)
{
    QPushButton* button = new QPushButton {};
    button->setCheckable(true);
    buttons_layout_->addWidget(button, buttons_number_);
    button->setFixedSize(64, 64);
    button->setIconSize({40, 40});
    button->setToolTip(name);
    button->setIcon(createIcon(buttons_number_));

    tile_buttons_->addButton(button, buttons_number_++);
}

QIcon BoardEditor::createIcon(int tile)
{
    if (tile >= 0 && tile < 6) {
        qreal size = sprites_->height();
        QPixmap sprite = sprites_->copy((tile + 1) * size, 0, size, size);
        return QIcon {sprite};
    } else if (tile == 6)
        return QIcon {player_sprite_->copy()};
    else
        return QIcon {};
}
