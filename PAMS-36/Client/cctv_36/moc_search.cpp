/****************************************************************************
** Meta object code from reading C++ file 'search.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/controller/search.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'search.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN6SearchE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN6SearchE = QtMocHelpers::stringData(
    "Search",
    "performSearch",
    "",
    "handleSearchInput",
    "text",
    "showSearchMenu",
    "selectCustomerInfo",
    "QItemSelection",
    "selected",
    "deselected",
    "handleCalendarDateChanged",
    "date",
    "toggleCalendar",
    "on_plateDataReceived",
    "buffer"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN6SearchE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    1,   57,    2, 0x0a,    2 /* Public */,
       5,    0,   60,    2, 0x08,    4 /* Private */,
       6,    2,   61,    2, 0x08,    5 /* Private */,
      10,    1,   66,    2, 0x08,    8 /* Private */,
      12,    0,   69,    2, 0x08,   10 /* Private */,
      13,    1,   70,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, QMetaType::QDate,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject Search::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN6SearchE.offsetsAndSizes,
    qt_meta_data_ZN6SearchE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN6SearchE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Search, std::true_type>,
        // method 'performSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSearchInput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showSearchMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectCustomerInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        // method 'handleCalendarDateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>,
        // method 'toggleCalendar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_plateDataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
    >,
    nullptr
} };

void Search::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Search *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->performSearch(); break;
        case 1: _t->handleSearchInput((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->showSearchMenu(); break;
        case 3: _t->selectCustomerInfo((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 4: _t->handleCalendarDateChanged((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 5: _t->toggleCalendar(); break;
        case 6: _t->on_plateDataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Search::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Search::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN6SearchE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Search::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
