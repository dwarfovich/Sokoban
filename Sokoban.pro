#-------------------------------------------------
#
# Project created by QtCreator 2016-11-26T17:53:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sokoban
TEMPLATE = app

INCLUDEPATH += src

release: DESTDIR = build/release
debug:   DESTDIR = build/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

SOURCES +=\
    src/board.cpp \
    src/board_editor.cpp \
    src/main.cpp \
    src/main_window.cpp \
    src/new_level_dialog.cpp \
    src/sokoban_widget.cpp \
    src/tile_item.cpp

HEADERS  += \
    src/board.hpp \
    src/board_editor.hpp \
    src/direction_enum.hpp \
    src/main_window.hpp \
    src/new_level_dialog.hpp \
    src/sokoban_widget.hpp \
    src/tile_enum.hpp \
    src/tile_item.hpp

RESOURCES += \
    tiles.qrc

DISTFILES +=
