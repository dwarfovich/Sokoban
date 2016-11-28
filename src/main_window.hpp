#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

class SokobanWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();

public slots:
    void openEditor ();

private slots:
    void gameOver ();

private:
    SokobanWidget* sokoban_widget_;
    QMenu* main_menu_;
    QAction* close_act_;
    QAction* open_editor_act_;
    QAction* load_level_act_;
};

#endif // MAIN_WINDOW_HPP
