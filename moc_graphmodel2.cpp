/****************************************************************************
** Meta object code from reading C++ file 'graphmodel2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphmodel2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphmodel2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphModel2_t {
    QByteArrayData data[28];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphModel2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphModel2_t qt_meta_stringdata_GraphModel2 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GraphModel2"
QT_MOC_LITERAL(1, 12, 16), // "SelectionChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "GraphModel2*"
QT_MOC_LITERAL(4, 43, 5), // "model"
QT_MOC_LITERAL(5, 49, 12), // "Disconnected"
QT_MOC_LITERAL(6, 62, 12), // "StateChanged"
QT_MOC_LITERAL(7, 75, 17), // "PolynomialChanged"
QT_MOC_LITERAL(8, 93, 10), // "TagChanged"
QT_MOC_LITERAL(9, 104, 12), // "getDaughters"
QT_MOC_LITERAL(10, 117, 19), // "QList<GraphModel2*>"
QT_MOC_LITERAL(11, 137, 9), // "EdgeModel"
QT_MOC_LITERAL(12, 147, 4), // "edge"
QT_MOC_LITERAL(13, 152, 10), // "selectBond"
QT_MOC_LITERAL(14, 163, 12), // "unselectBond"
QT_MOC_LITERAL(15, 176, 14), // "isBondSelected"
QT_MOC_LITERAL(16, 191, 15), // "getSelectedBond"
QT_MOC_LITERAL(17, 207, 12), // "getFragments"
QT_MOC_LITERAL(18, 220, 10), // "getZZInput"
QT_MOC_LITERAL(19, 231, 11), // "connections"
QT_MOC_LITERAL(20, 243, 11), // "getZZInput2"
QT_MOC_LITERAL(21, 255, 9), // "hydrogens"
QT_MOC_LITERAL(22, 265, 7), // "setDead"
QT_MOC_LITERAL(23, 273, 6), // "isDead"
QT_MOC_LITERAL(24, 280, 7), // "prepare"
QT_MOC_LITERAL(25, 288, 17), // "getNoBondDaughter"
QT_MOC_LITERAL(26, 306, 18), // "getNoAtomsDaughter"
QT_MOC_LITERAL(27, 325, 17) // "getNoRingDaughter"

    },
    "GraphModel2\0SelectionChanged\0\0"
    "GraphModel2*\0model\0Disconnected\0"
    "StateChanged\0PolynomialChanged\0"
    "TagChanged\0getDaughters\0QList<GraphModel2*>\0"
    "EdgeModel\0edge\0selectBond\0unselectBond\0"
    "isBondSelected\0getSelectedBond\0"
    "getFragments\0getZZInput\0connections\0"
    "getZZInput2\0hydrogens\0setDead\0isDead\0"
    "prepare\0getNoBondDaughter\0getNoAtomsDaughter\0"
    "getNoRingDaughter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphModel2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       6,    1,  110,    2, 0x06 /* Public */,
       7,    1,  113,    2, 0x06 /* Public */,
       8,    1,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  119,    2, 0x0a /* Public */,
      13,    1,  122,    2, 0x0a /* Public */,
      14,    0,  125,    2, 0x0a /* Public */,
      15,    0,  126,    2, 0x0a /* Public */,
      16,    0,  127,    2, 0x0a /* Public */,
      17,    0,  128,    2, 0x0a /* Public */,
      18,    1,  129,    2, 0x0a /* Public */,
      20,    2,  132,    2, 0x0a /* Public */,
      22,    1,  137,    2, 0x0a /* Public */,
      24,    0,  140,    2, 0x0a /* Public */,
      25,    1,  141,    2, 0x08 /* Private */,
      26,    1,  144,    2, 0x08 /* Private */,
      27,    1,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    0x80000000 | 10, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Bool,
    0x80000000 | 11,
    0x80000000 | 10,
    QMetaType::QString, QMetaType::Bool,   19,
    QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   19,   21,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    0x80000000 | 3, 0x80000000 | 11,   12,
    0x80000000 | 3, 0x80000000 | 11,   12,
    0x80000000 | 10, 0x80000000 | 11,   12,

       0        // eod
};

void GraphModel2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphModel2 *_t = static_cast<GraphModel2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SelectionChanged((*reinterpret_cast< GraphModel2*(*)>(_a[1]))); break;
        case 1: _t->Disconnected((*reinterpret_cast< GraphModel2*(*)>(_a[1]))); break;
        case 2: _t->StateChanged((*reinterpret_cast< GraphModel2*(*)>(_a[1]))); break;
        case 3: _t->PolynomialChanged((*reinterpret_cast< GraphModel2*(*)>(_a[1]))); break;
        case 4: _t->TagChanged((*reinterpret_cast< GraphModel2*(*)>(_a[1]))); break;
        case 5: { QList<GraphModel2*> _r = _t->getDaughters((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel2*>*>(_a[0]) = _r; }  break;
        case 6: _t->selectBond((*reinterpret_cast< EdgeModel(*)>(_a[1]))); break;
        case 7: _t->unselectBond(); break;
        case 8: { bool _r = _t->isBondSelected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { EdgeModel _r = _t->getSelectedBond();
            if (_a[0]) *reinterpret_cast< EdgeModel*>(_a[0]) = _r; }  break;
        case 10: { QList<GraphModel2*> _r = _t->getFragments();
            if (_a[0]) *reinterpret_cast< QList<GraphModel2*>*>(_a[0]) = _r; }  break;
        case 11: { QString _r = _t->getZZInput((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QString _r = _t->getZZInput2((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: _t->setDead((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->prepare(); break;
        case 15: { GraphModel2* _r = _t->getNoBondDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< GraphModel2**>(_a[0]) = _r; }  break;
        case 16: { GraphModel2* _r = _t->getNoAtomsDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< GraphModel2**>(_a[0]) = _r; }  break;
        case 17: { QList<GraphModel2*> _r = _t->getNoRingDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel2*>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel2* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel2* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel2* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel2* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel2* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphModel2::*_t)(GraphModel2 * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel2::SelectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphModel2::*_t)(GraphModel2 * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel2::Disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphModel2::*_t)(GraphModel2 * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel2::StateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GraphModel2::*_t)(GraphModel2 * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel2::PolynomialChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GraphModel2::*_t)(GraphModel2 * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel2::TagChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject GraphModel2::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GraphModel2.data,
      qt_meta_data_GraphModel2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphModel2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphModel2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphModel2.stringdata0))
        return static_cast<void*>(const_cast< GraphModel2*>(this));
    return QObject::qt_metacast(_clname);
}

int GraphModel2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void GraphModel2::SelectionChanged(GraphModel2 * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphModel2::Disconnected(GraphModel2 * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphModel2::StateChanged(GraphModel2 * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphModel2::PolynomialChanged(GraphModel2 * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphModel2::TagChanged(GraphModel2 * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
