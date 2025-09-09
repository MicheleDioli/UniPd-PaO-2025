/****************************************************************************
** Meta object code from reading C++ file 'ListaQT.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/sensoriqt/ListaQT.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListaQT.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
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

template <> constexpr inline auto ListaQT::qt_create_metaobjectdata<qt_meta_tag_ZN7ListaQTE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
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
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dettaglioClicked'
        QtMocHelpers::SignalData<void(Articolo *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'salvaclic'
        QtMocHelpers::SignalData<void(Articolo *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'cancellaclic'
        QtMocHelpers::SignalData<void(Articolo *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'modificlic'
        QtMocHelpers::SignalData<void(Articolo *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'nuovoClicked'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clicatoNuovo'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'itemClicked'
        QtMocHelpers::SlotData<void(Articolo *)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'salva'
        QtMocHelpers::SlotData<void(Articolo *)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'cancella'
        QtMocHelpers::SlotData<void(Articolo *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'dettaglio'
        QtMocHelpers::SlotData<void(Articolo *)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'modifica'
        QtMocHelpers::SlotData<void(Articolo *)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ListaQT, qt_meta_tag_ZN7ListaQTE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ListaQT::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ListaQTE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ListaQTE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7ListaQTE_t>.metaTypes,
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
        if (QtMocHelpers::indexOfMethod<void (ListaQT::*)(Articolo * )>(_a, &ListaQT::dettaglioClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ListaQT::*)(Articolo * )>(_a, &ListaQT::salvaclic, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ListaQT::*)(Articolo * )>(_a, &ListaQT::cancellaclic, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ListaQT::*)(Articolo * )>(_a, &ListaQT::modificlic, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ListaQT::*)()>(_a, &ListaQT::nuovoClicked, 4))
            return;
    }
}

const QMetaObject *ListaQT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListaQT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ListaQTE_t>.strings))
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
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ListaQT::salvaclic(Articolo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ListaQT::cancellaclic(Articolo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ListaQT::modificlic(Articolo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ListaQT::nuovoClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
