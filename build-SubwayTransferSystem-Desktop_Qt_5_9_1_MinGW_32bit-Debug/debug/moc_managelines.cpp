/****************************************************************************
** Meta object code from reading C++ file 'managelines.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SubwayTransferSystem/managelines.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managelines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageLines_t {
    QByteArrayData data[11];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManageLines_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManageLines_t qt_meta_stringdata_ManageLines = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ManageLines"
QT_MOC_LITERAL(1, 12, 31), // "on_lineEditLineName_textChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 4), // "arg1"
QT_MOC_LITERAL(4, 50, 32), // "on_pushButtonChooseColor_clicked"
QT_MOC_LITERAL(5, 83, 34), // "on_lineEditStationName_textCh..."
QT_MOC_LITERAL(6, 118, 37), // "on_doubleSpinBoxLatitude_valu..."
QT_MOC_LITERAL(7, 156, 38), // "on_doubleSpinBoxLongitude_val..."
QT_MOC_LITERAL(8, 195, 25), // "on_listWidget_itemClicked"
QT_MOC_LITERAL(9, 221, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 238, 4) // "item"

    },
    "ManageLines\0on_lineEditLineName_textChanged\0"
    "\0arg1\0on_pushButtonChooseColor_clicked\0"
    "on_lineEditStationName_textChanged\0"
    "on_doubleSpinBoxLatitude_valueChanged\0"
    "on_doubleSpinBoxLongitude_valueChanged\0"
    "on_listWidget_itemClicked\0QListWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageLines[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       6,    1,   51,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void ManageLines::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManageLines *_t = static_cast<ManageLines *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_lineEditLineName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonChooseColor_clicked(); break;
        case 2: _t->on_lineEditStationName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_doubleSpinBoxLatitude_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_doubleSpinBoxLongitude_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ManageLines::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManageLines.data,
      qt_meta_data_ManageLines,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ManageLines::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageLines::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageLines.stringdata0))
        return static_cast<void*>(const_cast< ManageLines*>(this));
    return QDialog::qt_metacast(_clname);
}

int ManageLines::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
