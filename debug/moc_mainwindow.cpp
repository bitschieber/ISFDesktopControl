/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[483];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 42), // "on_pushButtonSimulationStepFo..."
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 41), // "on_pushButtonSimulationConnec..."
QT_MOC_LITERAL(4, 97, 22), // "SimulationDataReceived"
QT_MOC_LITERAL(5, 120, 4), // "data"
QT_MOC_LITERAL(6, 125, 23), // "SimulationImageReceived"
QT_MOC_LITERAL(7, 149, 3), // "img"
QT_MOC_LITERAL(8, 153, 22), // "BrainBoardDataReceived"
QT_MOC_LITERAL(9, 176, 23), // "halDataToBrainBoardHost"
QT_MOC_LITERAL(10, 200, 11), // "halDebugLog"
QT_MOC_LITERAL(11, 212, 3), // "str"
QT_MOC_LITERAL(12, 216, 41), // "on_pushButtonBrainBoardConnec..."
QT_MOC_LITERAL(13, 258, 26), // "TimerWaitForISFRunFinished"
QT_MOC_LITERAL(14, 285, 35), // "on_pushButtonSimulationPlay_c..."
QT_MOC_LITERAL(15, 321, 20), // "on_cbRCOnOff_clicked"
QT_MOC_LITERAL(16, 342, 7), // "checked"
QT_MOC_LITERAL(17, 350, 25), // "on_cbUserButton01_clicked"
QT_MOC_LITERAL(18, 376, 25), // "on_cbUserButton02_clicked"
QT_MOC_LITERAL(19, 402, 22), // "simulationStateMachine"
QT_MOC_LITERAL(20, 425, 17), // "SIMULATION_SIGNAL"
QT_MOC_LITERAL(21, 443, 6), // "signal"
QT_MOC_LITERAL(22, 450, 26), // "on_sliderADC1_valueChanged"
QT_MOC_LITERAL(23, 477, 5) // "value"

    },
    "MainWindow\0on_pushButtonSimulationStepForward_clicked\0"
    "\0on_pushButtonSimulationConnection_clicked\0"
    "SimulationDataReceived\0data\0"
    "SimulationImageReceived\0img\0"
    "BrainBoardDataReceived\0halDataToBrainBoardHost\0"
    "halDebugLog\0str\0"
    "on_pushButtonBrainBoardConnection_clicked\0"
    "TimerWaitForISFRunFinished\0"
    "on_pushButtonSimulationPlay_clicked\0"
    "on_cbRCOnOff_clicked\0checked\0"
    "on_cbUserButton01_clicked\0"
    "on_cbUserButton02_clicked\0"
    "simulationStateMachine\0SIMULATION_SIGNAL\0"
    "signal\0on_sliderADC1_valueChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    1,   98,    2, 0x08 /* Private */,
      10,    1,  101,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,
      19,    1,  116,    2, 0x08 /* Private */,
      22,    1,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QImage,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonSimulationStepForward_clicked(); break;
        case 1: _t->on_pushButtonSimulationConnection_clicked(); break;
        case 2: _t->SimulationDataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->SimulationImageReceived((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->BrainBoardDataReceived(); break;
        case 5: _t->halDataToBrainBoardHost((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->halDebugLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonBrainBoardConnection_clicked(); break;
        case 8: _t->TimerWaitForISFRunFinished(); break;
        case 9: _t->on_pushButtonSimulationPlay_clicked(); break;
        case 10: _t->on_cbRCOnOff_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_cbUserButton01_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_cbUserButton02_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->simulationStateMachine((*reinterpret_cast< SIMULATION_SIGNAL(*)>(_a[1]))); break;
        case 14: _t->on_sliderADC1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
