#include "main_window.hpp"
#include "sokoban_widget.hpp"
#include "board_editor.hpp"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , sokoban_widget_{nullptr}
{
    setGeometry(200, 200, 700, 700);

    sokoban_widget_ = new SokobanWidget {this};
    setCentralWidget(new QWidget);
    QGridLayout* layout = new QGridLayout;
    centralWidget()->setLayout(layout);
    layout->addWidget(sokoban_widget_, 0, 0, 1, 1);
    sokoban_widget_->setFocusPolicy(Qt::StrongFocus);
    connect(sokoban_widget_, &SokobanWidget::playerWin,
            this, &MainWindow::gameOver);

    close_act_ = new QAction {"&Quit", this};
    close_act_->setShortcut(QKeySequence::Close);
    connect(close_act_, &QAction::triggered, this, &MainWindow::close);
    open_editor_act_ = new QAction {"&Editor", this};
    connect(open_editor_act_, &QAction::triggered, this, &MainWindow::openEditor);
    load_level_act_ = new QAction {"&Load", this};
    load_level_act_->setShortcut(QKeySequence::Open);
    connect(load_level_act_, &QAction::triggered,
            sokoban_widget_, &SokobanWidget::loadBoard);
    main_menu_ = menuBar()->addMenu("&Main");
    main_menu_->addAction(load_level_act_);
    main_menu_->addAction(open_editor_act_);
    main_menu_->addSeparator();
    main_menu_->addAction(close_act_);
}

MainWindow::~MainWindow()
{}

void MainWindow::openEditor()
{
    BoardEditor* editor = new BoardEditor {this};
    editor->setWindowFlags(Qt::Window);
    editor->setWindowModality(Qt::ApplicationModal);
    editor->show();
}

void MainWindow::gameOver()
{
    QMessageBox::information(this, "Game over", "You win!");
}
