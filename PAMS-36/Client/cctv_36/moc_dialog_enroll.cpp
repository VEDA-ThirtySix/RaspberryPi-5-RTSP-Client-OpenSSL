/****************************************************************************
** Meta object code from reading C++ file 'dialog_enroll.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/view/dialog_enroll.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_enroll.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12EnrollDialogE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN12EnrollDialogE = QtMocHelpers::stringData(
    "EnrollDialog",
    "dataSubmitted",
    "",
    "clicked_buttonPrev",
    "clicked_buttonEnroll"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN12EnrollDialogE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EnrollDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ZN12EnrollDialogE.offsetsAndSizes,
    qt_meta_data_ZN12EnrollDialogE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN12EnrollDialogE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EnrollDialog, std::true_type>,
        // method 'dataSubmitted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clicked_buttonPrev'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clicked_buttonEnroll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EnrollDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EnrollDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dataSubmitted(); break;
        case 1: _t->clicked_buttonPrev(); break;
        case 2: _t->clicked_buttonEnroll(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (EnrollDialog::*)();
            if (_q_method_type _q_method = &EnrollDialog::dataSubmitted; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *EnrollDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnrollDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN12EnrollDialogE.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EnrollDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void EnrollDialog::dataSubmitted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP