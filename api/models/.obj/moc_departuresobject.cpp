/****************************************************************************
** Meta object code from reading C++ file 'departuresobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sqlobjects/departuresobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'departuresobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeparturesObject_t {
    QByteArrayData data[9];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeparturesObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeparturesObject_t qt_meta_stringdata_DeparturesObject = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DeparturesObject"
QT_MOC_LITERAL(1, 17, 7), // "airport"
QT_MOC_LITERAL(2, 25, 12), // "airport_iata"
QT_MOC_LITERAL(3, 38, 12), // "airline_name"
QT_MOC_LITERAL(4, 51, 11), // "flight_iata"
QT_MOC_LITERAL(5, 63, 11), // "flight_date"
QT_MOC_LITERAL(6, 75, 19), // "departure_scheduled"
QT_MOC_LITERAL(7, 95, 15), // "arrival_airport"
QT_MOC_LITERAL(8, 111, 17) // "arrival_scheduled"

    },
    "DeparturesObject\0airport\0airport_iata\0"
    "airline_name\0flight_iata\0flight_date\0"
    "departure_scheduled\0arrival_airport\0"
    "arrival_scheduled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeparturesObject[] = {

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

void DeparturesObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DeparturesObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getairport(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getairport_iata(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getairline_name(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getflight_iata(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getflight_date(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getdeparture_scheduled(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getarrival_airport(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->getarrival_scheduled(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DeparturesObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setairport(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setairport_iata(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setairline_name(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setflight_iata(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setflight_date(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setdeparture_scheduled(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setarrival_airport(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setarrival_scheduled(*reinterpret_cast< QString*>(_v)); break;
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

QT_INIT_METAOBJECT const QMetaObject DeparturesObject::staticMetaObject = { {
    QMetaObject::SuperData::link<TSqlObject::staticMetaObject>(),
    qt_meta_stringdata_DeparturesObject.data,
    qt_meta_data_DeparturesObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeparturesObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeparturesObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeparturesObject.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(this);
    return TSqlObject::qt_metacast(_clname);
}

int DeparturesObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
