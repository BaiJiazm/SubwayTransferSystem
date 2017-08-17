/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SubwayTransferSystem/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[380];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_toolEnlarge_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 23), // "on_toolShrink_triggered"
QT_MOC_LITERAL(4, 61, 25), // "on_actionAddAll_triggered"
QT_MOC_LITERAL(5, 87, 26), // "on_actionAddLine_triggered"
QT_MOC_LITERAL(6, 114, 29), // "on_actionAddStation_triggered"
QT_MOC_LITERAL(7, 144, 29), // "on_actionAddConnect_triggered"
QT_MOC_LITERAL(8, 174, 28), // "on_actionAddByText_triggered"
QT_MOC_LITERAL(9, 203, 23), // "tabWidgetCurrentChanged"
QT_MOC_LITERAL(10, 227, 5), // "index"
QT_MOC_LITERAL(11, 233, 7), // "addLine"
QT_MOC_LITERAL(12, 241, 10), // "addStation"
QT_MOC_LITERAL(13, 252, 13), // "addConnection"
QT_MOC_LITERAL(14, 266, 9), // "addByText"
QT_MOC_LITERAL(15, 276, 22), // "updateTranserQueryInfo"
QT_MOC_LITERAL(16, 299, 24), // "transferStartLineChanged"
QT_MOC_LITERAL(17, 324, 8), // "lineName"
QT_MOC_LITERAL(18, 333, 22), // "transferDstLineChanged"
QT_MOC_LITERAL(19, 356, 9), // "lineNames"
QT_MOC_LITERAL(20, 366, 13) // "transferQuery"

    },
    "MainWindow\0on_toolEnlarge_triggered\0"
    "\0on_toolShrink_triggered\0"
    "on_actionAddAll_triggered\0"
    "on_actionAddLine_triggered\0"
    "on_actionAddStation_triggered\0"
    "on_actionAddConnect_triggered\0"
    "on_actionAddByText_triggered\0"
    "tabWidgetCurrentChanged\0index\0addLine\0"
    "addStation\0addConnection\0addByText\0"
    "updateTranserQueryInfo\0transferStartLineChanged\0"
    "lineName\0transferDstLineChanged\0"
    "lineNames\0transferQuery"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    1,  101,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    1,  109,    2, 0x08 /* Private */,
      18,    1,  112,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toolEnlarge_triggered(); break;
        case 1: _t->on_toolShrink_triggered(); break;
        case 2: _t->on_actionAddAll_triggered(); break;
        case 3: _t->on_actionAddLine_triggered(); break;
        case 4: _t->on_actionAddStation_triggered(); break;
        case 5: _t->on_actionAddConnect_triggered(); break;
        case 6: _t->on_actionAddByText_triggered(); break;
        case 7: _t->tabWidgetCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->addLine(); break;
        case 9: _t->addStation(); break;
        case 10: _t->addConnection(); break;
        case 11: _t->addByText(); break;
        case 12: _t->updateTranserQueryInfo(); break;
        case 13: _t->transferStartLineChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->transferDstLineChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->transferQuery(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
