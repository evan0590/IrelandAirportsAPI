/****************************************************************************
** Meta object code from reading C++ file 'arrivalscontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../arrivalscontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arrivalscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArrivalsController_t {
    QByteArrayData data[12];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArrivalsController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArrivalsController_t qt_meta_stringdata_ArrivalsController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ArrivalsController"
QT_MOC_LITERAL(1, 19, 5), // "index"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "iata"
QT_MOC_LITERAL(4, 31, 10), // "flightIata"
QT_MOC_LITERAL(5, 42, 4), // "date"
QT_MOC_LITERAL(6, 47, 10), // "flightDate"
QT_MOC_LITERAL(7, 58, 7), // "airport"
QT_MOC_LITERAL(8, 66, 11), // "airportIata"
QT_MOC_LITERAL(9, 78, 7), // "airline"
QT_MOC_LITERAL(10, 86, 11), // "airlineName"
QT_MOC_LITERAL(11, 98, 11) // "airportdate"

    },
    "ArrivalsController\0index\0\0iata\0"
    "flightIata\0date\0flightDate\0airport\0"
    "airportIata\0airline\0airlineName\0"
    "airportdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArrivalsController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,
       9,    1,   54,    2, 0x0a /* Public */,
      11,    2,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    6,

       0        // eod
};

void ArrivalsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArrivalsController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->index(); break;
        case 1: _t->iata((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->date((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->airport((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->airline((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->airportdate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ArrivalsController::staticMetaObject = { {
    QMetaObject::SuperData::link<ApplicationController::staticMetaObject>(),
    qt_meta_stringdata_ArrivalsController.data,
    qt_meta_data_ArrivalsController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArrivalsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArrivalsController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArrivalsController.stringdata0))
        return static_cast<void*>(this);
    return ApplicationController::qt_metacast(_clname);
}

int ArrivalsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApplicationController::qt_metacall(_c, _id, _a);
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
