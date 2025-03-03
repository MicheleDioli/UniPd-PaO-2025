/****************************************************************************
** Meta object code from reading C++ file 'Cliccabile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/view/Sensoriqt/Cliccabile.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Cliccabile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
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
struct qt_meta_tag_ZN10CliccabileE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10CliccabileE = QtMocHelpers::stringData(
    "Cliccabile",
    "clicked",
    "",
    "Articolo*",
    "salva",
    "cancella",
    "dettagli",
    "modifica",
    "salvaclic",
    "cancellaclic",
    "dettagliclic",
    "modificaclic"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10CliccabileE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    1,   71,    2, 0x06,    3 /* Public */,
       5,    1,   74,    2, 0x06,    5 /* Public */,
       6,    1,   77,    2, 0x06,    7 /* Public */,
       7,    1,   80,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   83,    2, 0x0a,   11 /* Public */,
       9,    0,   84,    2, 0x0a,   12 /* Public */,
      10,    0,   85,    2, 0x0a,   13 /* Public */,
      11,    0,   86,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Cliccabile::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN10CliccabileE.offsetsAndSizes,
    qt_meta_data_ZN10CliccabileE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10CliccabileE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Cliccabile, std::true_type>,
        // method 'clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'salva'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'cancella'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'dettagli'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'modifica'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'salvaclic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cancellaclic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dettagliclic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modificaclic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Cliccabile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Cliccabile *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 1: _t->salva((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 2: _t->cancella((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 3: _t->dettagli((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 4: _t->modifica((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 5: _t->salvaclic(); break;
        case 6: _t->cancellaclic(); break;
        case 7: _t->dettagliclic(); break;
        case 8: _t->modificaclic(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Cliccabile::*)(Articolo * );
            if (_q_method_type _q_method = &Cliccabile::clicked; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Cliccabile::*)(Articolo * );
            if (_q_method_type _q_method = &Cliccabile::salva; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Cliccabile::*)(Articolo * );
            if (_q_method_type _q_method = &Cliccabile::cancella; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Cliccabile::*)(Articolo * );
            if (_q_method_type _q_method = &Cliccabile::dettagli; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (Cliccabile::*)(Articolo * );
            if (_q_method_type _q_method = &Cliccabile::modifica; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *Cliccabile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cliccabile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10CliccabileE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Cliccabile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Cliccabile::clicked(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cliccabile::salva(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Cliccabile::cancella(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Cliccabile::dettagli(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Cliccabile::modifica(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
