/****************************************************************************
** Meta object code from reading C++ file 'ListaQT.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/view/Sensoriqt/ListaQT.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListaQT.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7ListaQTE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN7ListaQTE = QtMocHelpers::stringData(
    "ListaQT",
    "dettaglioClicked",
    "",
    "Articolo*",
    "articolo",
    "salvaclic",
    "cancellaclic",
    "modificlic",
    "nuovoClicked",
    "clicatoNuovo",
    "itemClicked",
    "salva",
    "cancella",
    "dettaglio",
    "modifica"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN7ListaQTE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       5,    1,   83,    2, 0x06,    3 /* Public */,
       6,    1,   86,    2, 0x06,    5 /* Public */,
       7,    1,   89,    2, 0x06,    7 /* Public */,
       8,    0,   92,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   93,    2, 0x0a,   10 /* Public */,
      10,    1,   94,    2, 0x0a,   11 /* Public */,
      11,    1,   97,    2, 0x0a,   13 /* Public */,
      12,    1,  100,    2, 0x0a,   15 /* Public */,
      13,    1,  103,    2, 0x0a,   17 /* Public */,
      14,    1,  106,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject ListaQT::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN7ListaQTE.offsetsAndSizes,
    qt_meta_data_ZN7ListaQTE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN7ListaQTE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ListaQT, std::true_type>,
        // method 'dettaglioClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'salvaclic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'cancellaclic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'modificlic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'nuovoClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clicatoNuovo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'salva'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'cancella'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'dettaglio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'modifica'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>
    >,
    nullptr
} };

void ListaQT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ListaQT *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dettaglioClicked((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 1: _t->salvaclic((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 2: _t->cancellaclic((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 3: _t->modificlic((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 4: _t->nuovoClicked(); break;
        case 5: _t->clicatoNuovo(); break;
        case 6: _t->itemClicked((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 7: _t->salva((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 8: _t->cancella((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 9: _t->dettaglio((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 10: _t->modifica((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (ListaQT::*)(Articolo * );
            if (_q_method_type _q_method = &ListaQT::dettaglioClicked; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (ListaQT::*)(Articolo * );
            if (_q_method_type _q_method = &ListaQT::salvaclic; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (ListaQT::*)(Articolo * );
            if (_q_method_type _q_method = &ListaQT::cancellaclic; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (ListaQT::*)(Articolo * );
            if (_q_method_type _q_method = &ListaQT::modificlic; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (ListaQT::*)();
            if (_q_method_type _q_method = &ListaQT::nuovoClicked; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *ListaQT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListaQT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN7ListaQTE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ListaQT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ListaQT::dettaglioClicked(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ListaQT::salvaclic(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ListaQT::cancellaclic(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ListaQT::modificlic(Articolo * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ListaQT::nuovoClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
