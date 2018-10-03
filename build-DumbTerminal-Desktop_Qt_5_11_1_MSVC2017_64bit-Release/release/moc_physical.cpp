/****************************************************************************
** Meta object code from reading C++ file 'physical.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../googleDrive/DBOX/BCIT/COMP_3980/Assignments/DumbTerminal/physical.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'physical.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Physical_t {
    QByteArrayData data[20];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Physical_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Physical_t qt_meta_stringdata_Physical = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Physical"
QT_MOC_LITERAL(1, 9, 20), // "initializeSerialPort"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "QSerialPort*"
QT_MOC_LITERAL(4, 44, 10), // "serialPort"
QT_MOC_LITERAL(5, 55, 22), // "deInitializeSerialPort"
QT_MOC_LITERAL(6, 78, 16), // "modifySerialPort"
QT_MOC_LITERAL(7, 95, 8), // "baudRate"
QT_MOC_LITERAL(8, 104, 8), // "dataBits"
QT_MOC_LITERAL(9, 113, 6), // "parity"
QT_MOC_LITERAL(10, 120, 8), // "stopBits"
QT_MOC_LITERAL(11, 129, 8), // "portName"
QT_MOC_LITERAL(12, 138, 24), // "modifySerialPortBaudRate"
QT_MOC_LITERAL(13, 163, 24), // "modifySerialPortDataBits"
QT_MOC_LITERAL(14, 188, 22), // "modifySerialPortParity"
QT_MOC_LITERAL(15, 211, 24), // "modifySerialPortStopBits"
QT_MOC_LITERAL(16, 236, 24), // "modifySerialPortPortName"
QT_MOC_LITERAL(17, 261, 18), // "readFromSerialPort"
QT_MOC_LITERAL(18, 280, 17), // "writeToSerialPort"
QT_MOC_LITERAL(19, 298, 4) // "data"

    },
    "Physical\0initializeSerialPort\0\0"
    "QSerialPort*\0serialPort\0deInitializeSerialPort\0"
    "modifySerialPort\0baudRate\0dataBits\0"
    "parity\0stopBits\0portName\0"
    "modifySerialPortBaudRate\0"
    "modifySerialPortDataBits\0"
    "modifySerialPortParity\0modifySerialPortStopBits\0"
    "modifySerialPortPortName\0readFromSerialPort\0"
    "writeToSerialPort\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Physical[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       5,    1,   67,    2, 0x0a /* Public */,
       6,    6,   70,    2, 0x0a /* Public */,
      12,    2,   83,    2, 0x0a /* Public */,
      13,    2,   88,    2, 0x0a /* Public */,
      14,    2,   93,    2, 0x0a /* Public */,
      15,    2,   98,    2, 0x0a /* Public */,
      16,    2,  103,    2, 0x0a /* Public */,
      17,    1,  108,    2, 0x0a /* Public */,
      18,    2,  111,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    7,    8,    9,   10,   11,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    7,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    8,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    9,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,   10,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,   11,    4,
    QMetaType::QByteArray, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3,   19,    4,

       0        // eod
};

void Physical::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Physical *_t = static_cast<Physical *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->initializeSerialPort((*reinterpret_cast< QSerialPort*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->deInitializeSerialPort((*reinterpret_cast< QSerialPort*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->modifySerialPort((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< QSerialPort*(*)>(_a[6]))); break;
        case 3: _t->modifySerialPortBaudRate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 4: _t->modifySerialPortDataBits((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 5: _t->modifySerialPortParity((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 6: _t->modifySerialPortStopBits((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 7: _t->modifySerialPortPortName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        case 8: { QByteArray _r = _t->readFromSerialPort((*reinterpret_cast< QSerialPort*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->writeToSerialPort((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< QSerialPort*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSerialPort* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Physical::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Physical.data,
      qt_meta_data_Physical,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Physical::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Physical::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Physical.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Physical::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
