/****************************************************************************
** Meta object code from reading C++ file 'board.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/board.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'board.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Board_t {
    QByteArrayData data[8];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Board_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Board_t qt_meta_stringdata_Board = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Board"
QT_MOC_LITERAL(1, 6, 11), // "playerMoved"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "location"
QT_MOC_LITERAL(4, 28, 12), // "tilesChanged"
QT_MOC_LITERAL(5, 41, 4), // "Tile"
QT_MOC_LITERAL(6, 46, 4), // "tile"
QT_MOC_LITERAL(7, 51, 16) // "allBoxesArranged"

    },
    "Board\0playerMoved\0\0location\0tilesChanged\0"
    "Tile\0tile\0allBoxesArranged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Board[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    2,   32,    2, 0x06 /* Public */,
       7,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 5,    3,    6,
    QMetaType::Void,

       0        // eod
};

void Board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Board *_t = static_cast<Board *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playerMoved((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->tilesChanged((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< Tile(*)>(_a[2]))); break;
        case 2: _t->allBoxesArranged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Board::*_t)(const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::playerMoved)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Board::*_t)(const QPoint & , Tile );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::tilesChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Board::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Board::allBoxesArranged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Board::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Board.data,
      qt_meta_data_Board,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Board::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Board.stringdata0))
        return static_cast<void*>(const_cast< Board*>(this));
    return QObject::qt_metacast(_clname);
}

int Board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Board::playerMoved(const QPoint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Board::tilesChanged(const QPoint & _t1, Tile _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Board::allBoxesArranged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
