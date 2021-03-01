/****************************************************************************
** Meta object code from reading C++ file 'arrivalsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sqlobjects/arrivalsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arrivalsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArrivalsObject_t {
    QByteArrayData data[9];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArrivalsObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArrivalsObject_t qt_meta_stringdata_ArrivalsObject = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ArrivalsObject"
QT_MOC_LITERAL(1, 15, 7), // "airport"
QT_MOC_LITERAL(2, 23, 12), // "airport_iata"
QT_MOC_LITERAL(3, 36, 12), // "airline_name"
QT_MOC_LITERAL(4, 49, 11), // "flight_iata"
QT_MOC_LITERAL(5, 61, 11), // "flight_date"
QT_MOC_LITERAL(6, 73, 17), // "arrival_scheduled"
QT_MOC_LITERAL(7, 91, 17), // "departure_airport"
QT_MOC_LITERAL(8, 109, 19) // "departure_scheduled"

    },
    "ArrivalsObject\0airport\0airport_iata\0"
    "airline_name\0flight_iata\0flight_date\0"
    "arrival_scheduled\0departure_airport\0"
    "departure_scheduled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArrivalsObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       8,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::QString, 0x00095003,
       8, QMetaType::QString, 0x00095003,

       0        // eod
};

void ArrivalsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ArrivalsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getairport(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getairport_iata(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getairline_name(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getflight_iata(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getflight_date(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getarrival_scheduled(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getdeparture_airport(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->getdeparture_scheduled(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ArrivalsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setairport(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setairport_iata(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setairline_name(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setflight_iata(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setflight_date(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setarrival_scheduled(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setdeparture_airport(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setdeparture_scheduled(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ArrivalsObject::staticMetaObject = { {
    QMetaObject::SuperData::link<TSqlObject::staticMetaObject>(),
    qt_meta_stringdata_ArrivalsObject.data,
    qt_meta_data_ArrivalsObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArrivalsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArrivalsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArrivalsObject.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(this);
    return TSqlObject::qt_metacast(_clname);
}

int ArrivalsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
