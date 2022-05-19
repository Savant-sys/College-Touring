/****************************************************************************
** Meta object code from reading C++ file 'allfromsaddleback.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CollegeTouring/allfromsaddleback.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'allfromsaddleback.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Allfromsaddleback_t {
    const uint offsetsAndSize[12];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Allfromsaddleback_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Allfromsaddleback_t qt_meta_stringdata_Allfromsaddleback = {
    {
QT_MOC_LITERAL(0, 17), // "Allfromsaddleback"
QT_MOC_LITERAL(18, 28), // "getEndCollegesFromSaddleback"
QT_MOC_LITERAL(47, 15), // "vector<QString>"
QT_MOC_LITERAL(63, 0), // ""
QT_MOC_LITERAL(64, 26), // "getDistancesFromSaddleback"
QT_MOC_LITERAL(91, 14) // "vector<double>"

    },
    "Allfromsaddleback\0getEndCollegesFromSaddleback\0"
    "vector<QString>\0\0getDistancesFromSaddleback\0"
    "vector<double>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Allfromsaddleback[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    3, 0x06,    0 /* Public */,
       4,    0,   27,    3, 0x06,    1 /* Public */,

 // signals: parameters
    0x80000000 | 2,
    0x80000000 | 5,

       0        // eod
};

void Allfromsaddleback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Allfromsaddleback *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { vector<QString> _r = _t->getEndCollegesFromSaddleback();
            if (_a[0]) *reinterpret_cast< vector<QString>*>(_a[0]) = std::move(_r); }  break;
        case 1: { vector<double> _r = _t->getDistancesFromSaddleback();
            if (_a[0]) *reinterpret_cast< vector<double>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = vector<QString> (Allfromsaddleback::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Allfromsaddleback::getEndCollegesFromSaddleback)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = vector<double> (Allfromsaddleback::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Allfromsaddleback::getDistancesFromSaddleback)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Allfromsaddleback::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Allfromsaddleback.offsetsAndSize,
    qt_meta_data_Allfromsaddleback,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Allfromsaddleback_t
, QtPrivate::TypeAndForceComplete<vector<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<double>, std::false_type>



>,
    nullptr
} };


const QMetaObject *Allfromsaddleback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Allfromsaddleback::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Allfromsaddleback.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Allfromsaddleback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
vector<QString> Allfromsaddleback::getEndCollegesFromSaddleback()
{
    vector<QString> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
vector<double> Allfromsaddleback::getDistancesFromSaddleback()
{
    vector<double> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
