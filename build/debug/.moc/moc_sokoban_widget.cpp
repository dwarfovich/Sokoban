/****************************************************************************
** Meta object code from reading C++ file 'sokoban_widget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/sokoban_widget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sokoban_widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SokobanWidget_t {
    QByteArrayData data[15];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SokobanWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SokobanWidget_t qt_meta_stringdata_SokobanWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SokobanWidget"
QT_MOC_LITERAL(1, 14, 11), // "tileClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "location"
QT_MOC_LITERAL(4, 36, 9), // "playerWin"
QT_MOC_LITERAL(5, 46, 9), // "loadBoard"
QT_MOC_LITERAL(6, 56, 9), // "saveBoard"
QT_MOC_LITERAL(7, 66, 10), // "updateTile"
QT_MOC_LITERAL(8, 77, 4), // "Tile"
QT_MOC_LITERAL(9, 82, 4), // "tile"
QT_MOC_LITERAL(10, 87, 20), // "updatePlayerLocation"
QT_MOC_LITERAL(11, 108, 9), // "drawBoard"
QT_MOC_LITERAL(12, 118, 10), // "movePlayer"
QT_MOC_LITERAL(13, 129, 9), // "Direction"
QT_MOC_LITERAL(14, 139, 9) // "direction"

    },
    "SokobanWidget\0tileClicked\0\0location\0"
    "playerWin\0loadBoard\0saveBoard\0updateTile\0"
    "Tile\0tile\0updatePlayerLocation\0drawBoard\0"
    "movePlayer\0Direction\0direction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SokobanWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    2,   60,    2, 0x0a /* Public */,
      10,    1,   65,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 8,    3,    9,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void SokobanWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SokobanWidget *_t = static_cast<SokobanWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tileClicked((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->playerWin(); break;
        case 2: _t->loadBoard(); break;
        case 3: _t->saveBoard(); break;
        case 4: _t->updateTile((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< Tile(*)>(_a[2]))); break;
        case 5: _t->updatePlayerLocation((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->drawBoard(); break;
        case 7: _t->movePlayer((*reinterpret_cast< Direction(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SokobanWidget::*_t)(const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SokobanWidget::tileClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SokobanWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SokobanWidget::playerWin)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SokobanWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SokobanWidget.data,
      qt_meta_data_SokobanWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SokobanWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SokobanWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SokobanWidget.stringdata0))
        return static_cast<void*>(const_cast< SokobanWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SokobanWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SokobanWidget::tileClicked(const QPoint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SokobanWidget::playerWin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
