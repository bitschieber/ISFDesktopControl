/****************************************************************************
** Meta object code from reading C++ file 'simulationconnectioncontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../simulationconnectioncontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulationconnectioncontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SimulationConnectionController_t {
    QByteArrayData data[7];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimulationConnectionController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimulationConnectionController_t qt_meta_stringdata_SimulationConnectionController = {
    {
QT_MOC_LITERAL(0, 0, 30), // "SimulationConnectionController"
QT_MOC_LITERAL(1, 31, 13), // "imageReceived"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 3), // "img"
QT_MOC_LITERAL(4, 50, 12), // "dataReceived"
QT_MOC_LITERAL(5, 63, 4), // "data"
QT_MOC_LITERAL(6, 68, 22) // "SimulationDataReceived"

    },
    "SimulationConnectionController\0"
    "imageReceived\0\0img\0dataReceived\0data\0"
    "SimulationDataReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimulationConnectionController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    5,

       0        // eod
};

void SimulationConnectionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimulationConnectionController *_t = static_cast<SimulationConnectionController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageReceived((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->dataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->SimulationDataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SimulationConnectionController::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SimulationConnectionController::imageReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (SimulationConnectionController::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SimulationConnectionController::dataReceived)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SimulationConnectionController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SimulationConnectionController.data,
      qt_meta_data_SimulationConnectionController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SimulationConnectionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulationConnectionController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SimulationConnectionController.stringdata0))
        return static_cast<void*>(const_cast< SimulationConnectionController*>(this));
    return QObject::qt_metacast(_clname);
}

int SimulationConnectionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SimulationConnectionController::imageReceived(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimulationConnectionController::dataReceived(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
