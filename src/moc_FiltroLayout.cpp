/****************************************************************************
** Meta object code from reading C++ file 'FiltroLayout.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "view/sensoriqt/FiltroLayout.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FiltroLayout.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12FiltroLayoutE_t {};
} // unnamed namespace

template <> constexpr inline auto FiltroLayout::qt_create_metaobjectdata<qt_meta_tag_ZN12FiltroLayoutE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FiltroLayout",
        "dettaglioClicked",
        "",
        "Articolo*",
        "nuovo",
        "listanuova",
        "salvaclic",
        "cancellaclic",
        "modificaclic",
        "filtraggio",
        "ricercaScelta",
        "nuovoClicked",
        "nuovoSalvato",
        "aggiorna",
        "dettaglio",
        "salvaSlot",
        "cancellaSlot",
        "modificaSlot"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dettaglioClicked'
        QtMocHelpers::SignalData<void(Articolo *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'nuovo'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'listanuova'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'salvaclic'
        QtMocHelpers::SignalData<void(Articolo *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'cancellaclic'
        QtMocHelpers::SignalData<void(Articolo *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'modificaclic'
        QtMocHelpers::SignalData<void(Articolo *)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'filtraggio'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'ricercaScelta'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'nuovoClicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'nuovoSalvato'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'aggiorna'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'dettaglio'
        QtMocHelpers::SlotData<void(Articolo *)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'salvaSlot'
        QtMocHelpers::SlotData<void(Articolo *)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'cancellaSlot'
        QtMocHelpers::SlotData<void(Articolo *)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'modificaSlot'
        QtMocHelpers::SlotData<void(Articolo *)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FiltroLayout, qt_meta_tag_ZN12FiltroLayoutE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject FiltroLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FiltroLayoutE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FiltroLayoutE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12FiltroLayoutE_t>.metaTypes,
    nullptr
} };

void FiltroLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FiltroLayout *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dettaglioClicked((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 1: _t->nuovo(); break;
        case 2: _t->listanuova(); break;
        case 3: _t->salvaclic((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 4: _t->cancellaclic((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 5: _t->modificaclic((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 6: _t->filtraggio(); break;
        case 7: _t->ricercaScelta(); break;
        case 8: _t->nuovoClicked(); break;
        case 9: _t->nuovoSalvato(); break;
        case 10: _t->aggiorna(); break;
        case 11: _t->dettaglio((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 12: _t->salvaSlot((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 13: _t->cancellaSlot((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 14: _t->modificaSlot((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FiltroLayout::*)(Articolo * )>(_a, &FiltroLayout::dettaglioClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (FiltroLayout::*)()>(_a, &FiltroLayout::nuovo, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (FiltroLayout::*)()>(_a, &FiltroLayout::listanuova, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (FiltroLayout::*)(Articolo * )>(_a, &FiltroLayout::salvaclic, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (FiltroLayout::*)(Articolo * )>(_a, &FiltroLayout::cancellaclic, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (FiltroLayout::*)(Articolo * )>(_a, &FiltroLayout::modificaclic, 5))
            return;
    }
}

const QMetaObject *FiltroLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FiltroLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12FiltroLayoutE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FiltroLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void FiltroLayout::dettaglioClicked(Articolo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void FiltroLayout::nuovo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FiltroLayout::listanuova()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FiltroLayout::salvaclic(Articolo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void FiltroLayout::cancellaclic(Articolo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void FiltroLayout::modificaclic(Articolo * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
