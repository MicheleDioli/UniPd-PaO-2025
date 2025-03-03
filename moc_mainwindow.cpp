/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/view/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "nuovoClicked",
    "",
    "nuovoSalvato",
    "annullatoClicked",
    "mostaArticolo",
    "Articolo*",
    "salvaSlot",
    "cancellaSlot",
    "infoSlot",
    "importaSlot",
    "modificaSlot",
    "confermaModifica"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    0,   76,    2, 0x0a,    3 /* Public */,
       5,    1,   77,    2, 0x0a,    4 /* Public */,
       7,    1,   80,    2, 0x0a,    6 /* Public */,
       8,    1,   83,    2, 0x0a,    8 /* Public */,
       9,    0,   86,    2, 0x0a,   10 /* Public */,
      10,    0,   87,    2, 0x0a,   11 /* Public */,
      11,    1,   88,    2, 0x0a,   12 /* Public */,
      12,    0,   91,    2, 0x0a,   14 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'nuovoClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nuovoSalvato'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'annullatoClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mostaArticolo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'salvaSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'cancellaSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'infoSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'importaSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'modificaSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Articolo *, std::false_type>,
        // method 'confermaModifica'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->nuovoClicked(); break;
        case 1: _t->nuovoSalvato(); break;
        case 2: _t->annullatoClicked(); break;
        case 3: _t->mostaArticolo((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 4: _t->salvaSlot((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 5: _t->cancellaSlot((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 6: _t->infoSlot(); break;
        case 7: _t->importaSlot(); break;
        case 8: _t->modificaSlot((*reinterpret_cast< std::add_pointer_t<Articolo*>>(_a[1]))); break;
        case 9: _t->confermaModifica(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
