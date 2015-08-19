/****************************************************************************
** Meta object code from reading C++ file 'isfcarhalx86.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hal/isfcarhalx86.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'isfcarhalx86.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ISFCarHALx86_t {
    QByteArrayData data[6];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ISFCarHALx86_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ISFCarHALx86_t qt_meta_stringdata_ISFCarHALx86 = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ISFCarHALx86"
QT_MOC_LITERAL(1, 13, 19), // "sigDataToBrainBoard"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "data"
QT_MOC_LITERAL(4, 39, 11), // "sigDebugLog"
QT_MOC_LITERAL(5, 51, 3) // "str"

    },
    "ISFCarHALx86\0sigDataToBrainBoard\0\0"
    "data\0sigDebugLog\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ISFCarHALx86[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void ISFCarHALx86::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ISFCarHALx86 *_t = static_cast<ISFCarHALx86 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDataToBrainBoard((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sigDebugLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ISFCarHALx86::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ISFCarHALx86::sigDataToBrainBoard)) {
                *result = 0;
            }
        }
        {
            typedef void (ISFCarHALx86::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ISFCarHALx86::sigDebugLog)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ISFCarHALx86::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ISFCarHALx86.data,
      qt_meta_data_ISFCarHALx86,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ISFCarHALx86::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ISFCarHALx86::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ISFCarHALx86.stringdata0))
        return static_cast<void*>(const_cast< ISFCarHALx86*>(this));
    if (!strcmp(_clname, "I_ISFCarHAL"))
        return static_cast< I_ISFCarHAL*>(const_cast< ISFCarHALx86*>(this));
    return QObject::qt_metacast(_clname);
}

int ISFCarHALx86::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ISFCarHALx86::sigDataToBrainBoard(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ISFCarHALx86::sigDebugLog(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
