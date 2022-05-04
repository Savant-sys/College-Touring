/****************************************************************************
** Meta object code from reading C++ file 'adminwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CollegeTouring/adminwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminWindow_t {
    const uint offsetsAndSize[30];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AdminWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AdminWindow_t qt_meta_stringdata_AdminWindow = {
    {
QT_MOC_LITERAL(0, 11), // "AdminWindow"
QT_MOC_LITERAL(12, 8), // "showMain"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 10), // "updateMain"
QT_MOC_LITERAL(33, 14), // "vector<Campus>"
QT_MOC_LITERAL(48, 8), // "campuses"
QT_MOC_LITERAL(57, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(81, 26), // "on_CollegeList_itemClicked"
QT_MOC_LITERAL(108, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(125, 4), // "item"
QT_MOC_LITERAL(130, 14), // "on_Add_clicked"
QT_MOC_LITERAL(145, 17), // "on_Remove_clicked"
QT_MOC_LITERAL(163, 17), // "on_Change_clicked"
QT_MOC_LITERAL(181, 24), // "on_PriceList_itemClicked"
QT_MOC_LITERAL(206, 27) // "on_SouvenirList_itemClicked"

    },
    "AdminWindow\0showMain\0\0updateMain\0"
    "vector<Campus>\0campuses\0on_pushButton_4_clicked\0"
    "on_CollegeList_itemClicked\0QListWidgetItem*\0"
    "item\0on_Add_clicked\0on_Remove_clicked\0"
    "on_Change_clicked\0on_PriceList_itemClicked\0"
    "on_SouvenirList_itemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    1,   69,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   72,    2, 0x08,    4 /* Private */,
       7,    1,   73,    2, 0x08,    5 /* Private */,
      10,    0,   76,    2, 0x08,    7 /* Private */,
      11,    0,   77,    2, 0x08,    8 /* Private */,
      12,    0,   78,    2, 0x08,    9 /* Private */,
      13,    1,   79,    2, 0x08,   10 /* Private */,
      14,    1,   82,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void AdminWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showMain(); break;
        case 1: _t->updateMain((*reinterpret_cast< vector<Campus>(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_4_clicked(); break;
        case 3: _t->on_CollegeList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_Add_clicked(); break;
        case 5: _t->on_Remove_clicked(); break;
        case 6: _t->on_Change_clicked(); break;
        case 7: _t->on_PriceList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_SouvenirList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminWindow::showMain)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminWindow::*)(vector<Campus> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminWindow::updateMain)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AdminWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AdminWindow.offsetsAndSize,
    qt_meta_data_AdminWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AdminWindow_t
, QtPrivate::TypeAndForceComplete<AdminWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<Campus>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>


>,
    nullptr
} };


const QMetaObject *AdminWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AdminWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void AdminWindow::showMain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminWindow::updateMain(vector<Campus> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
