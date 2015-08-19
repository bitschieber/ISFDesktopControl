/****************************************************************************
** Meta object code from reading C++ file 'brainboardcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../brainboardcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brainboardcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BrainBoardController_t {
    QByteArrayData data[7];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrainBoardController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrainBoardController_t qt_meta_stringdata_BrainBoardController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "BrainBoardController"
QT_MOC_LITERAL(1, 21, 12), // "dataReceived"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "dataHostReceived"
QT_MOC_LITERAL(4, 52, 22), // "BrainBoardDataReceived"
QT_MOC_LITERAL(5, 75, 4), // "data"
QT_MOC_LITERAL(6, 80, 26) // "BrainBoardDataReceivedHost"

    },
    "BrainBoardController\0dataReceived\0\0"
    "dataHostReceived\0BrainBoardDataReceived\0"
    "data\0BrainBoardDataReceivedHost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrainBoardController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   36,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QByteArray,    5,

       0        // eod
};

void BrainBoardController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BrainBoardController *_t = static_cast<BrainBoardController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataReceived(); break;
        case 1: _t->dataHostReceived(); break;
        case 2: _t->BrainBoardDataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->BrainBoardDataReceivedHost((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BrainBoardController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BrainBoardController::dataReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (BrainBoardController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BrainBoardController::dataHostReceived)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject BrainBoardController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BrainBoardController.data,
      qt_meta_data_BrainBoardController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BrainBoardController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrainBoardController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BrainBoardController.stringdata0))
        return static_cast<void*>(const_cast< BrainBoardController*>(this));
    return QObject::qt_metacast(_clname);
}

int BrainBoardController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void BrainBoardController::dataReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void BrainBoardController::dataHostReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
