/****************************************************************************
** Meta object code from reading C++ file 'graphmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "graphmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphModel_t {
    QByteArrayData data[35];
    char stringdata0[412];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphModel_t qt_meta_stringdata_GraphModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GraphModel"
QT_MOC_LITERAL(1, 11, 16), // "SelectionChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "GraphModel*"
QT_MOC_LITERAL(4, 41, 5), // "model"
QT_MOC_LITERAL(5, 47, 12), // "Disconnected"
QT_MOC_LITERAL(6, 60, 12), // "StateChanged"
QT_MOC_LITERAL(7, 73, 17), // "PolynomialChanged"
QT_MOC_LITERAL(8, 91, 10), // "TagChanged"
QT_MOC_LITERAL(9, 102, 12), // "getDaughters"
QT_MOC_LITERAL(10, 115, 18), // "QList<GraphModel*>"
QT_MOC_LITERAL(11, 134, 9), // "EdgeModel"
QT_MOC_LITERAL(12, 144, 4), // "edge"
QT_MOC_LITERAL(13, 149, 13), // "getDaughters2"
QT_MOC_LITERAL(14, 163, 10), // "selectBond"
QT_MOC_LITERAL(15, 174, 12), // "unselectBond"
QT_MOC_LITERAL(16, 187, 14), // "isBondSelected"
QT_MOC_LITERAL(17, 202, 15), // "getSelectedBond"
QT_MOC_LITERAL(18, 218, 12), // "getFragments"
QT_MOC_LITERAL(19, 231, 10), // "getZZInput"
QT_MOC_LITERAL(20, 242, 11), // "connections"
QT_MOC_LITERAL(21, 254, 11), // "getZZInput2"
QT_MOC_LITERAL(22, 266, 9), // "hydrogens"
QT_MOC_LITERAL(23, 276, 7), // "setmode"
QT_MOC_LITERAL(24, 284, 4), // "mode"
QT_MOC_LITERAL(25, 289, 7), // "setDead"
QT_MOC_LITERAL(26, 297, 6), // "isDead"
QT_MOC_LITERAL(27, 304, 7), // "prepare"
QT_MOC_LITERAL(28, 312, 8), // "prepare2"
QT_MOC_LITERAL(29, 321, 17), // "getNoBondDaughter"
QT_MOC_LITERAL(30, 339, 18), // "getNoAtomsDaughter"
QT_MOC_LITERAL(31, 358, 17), // "getNoRingDaughter"
QT_MOC_LITERAL(32, 376, 17), // "getNoStarDaughter"
QT_MOC_LITERAL(33, 394, 9), // "startstar"
QT_MOC_LITERAL(34, 404, 7) // "endstar"

    },
    "GraphModel\0SelectionChanged\0\0GraphModel*\0"
    "model\0Disconnected\0StateChanged\0"
    "PolynomialChanged\0TagChanged\0getDaughters\0"
    "QList<GraphModel*>\0EdgeModel\0edge\0"
    "getDaughters2\0selectBond\0unselectBond\0"
    "isBondSelected\0getSelectedBond\0"
    "getFragments\0getZZInput\0connections\0"
    "getZZInput2\0hydrogens\0setmode\0mode\0"
    "setDead\0isDead\0prepare\0prepare2\0"
    "getNoBondDaughter\0getNoAtomsDaughter\0"
    "getNoRingDaughter\0getNoStarDaughter\0"
    "startstar\0endstar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       5,    1,  137,    2, 0x06 /* Public */,
       6,    1,  140,    2, 0x06 /* Public */,
       7,    1,  143,    2, 0x06 /* Public */,
       8,    1,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  149,    2, 0x0a /* Public */,
      13,    1,  152,    2, 0x0a /* Public */,
      14,    1,  155,    2, 0x0a /* Public */,
      15,    0,  158,    2, 0x0a /* Public */,
      16,    0,  159,    2, 0x0a /* Public */,
      17,    0,  160,    2, 0x0a /* Public */,
      18,    0,  161,    2, 0x0a /* Public */,
      19,    1,  162,    2, 0x0a /* Public */,
      21,    2,  165,    2, 0x0a /* Public */,
      23,    1,  170,    2, 0x0a /* Public */,
      25,    1,  173,    2, 0x0a /* Public */,
      27,    0,  176,    2, 0x0a /* Public */,
      28,    0,  177,    2, 0x0a /* Public */,
      29,    1,  178,    2, 0x08 /* Private */,
      30,    1,  181,    2, 0x08 /* Private */,
      31,    1,  184,    2, 0x08 /* Private */,
      32,    3,  187,    2, 0x08 /* Private */,
      32,    2,  194,    2, 0x28 /* Private | MethodCloned */,
      32,    1,  199,    2, 0x28 /* Private | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    0x80000000 | 10, 0x80000000 | 11,   12,
    0x80000000 | 10, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Bool,
    0x80000000 | 11,
    0x80000000 | 10,
    QMetaType::QString, QMetaType::Bool,   20,
    QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   20,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 3, 0x80000000 | 11,   12,
    0x80000000 | 3, 0x80000000 | 11,   12,
    0x80000000 | 10, 0x80000000 | 11,   12,
    0x80000000 | 10, 0x80000000 | 11, QMetaType::Bool, QMetaType::Bool,   12,   33,   34,
    0x80000000 | 10, 0x80000000 | 11, QMetaType::Bool,   12,   33,
    0x80000000 | 10, 0x80000000 | 11,   12,

       0        // eod
};

void GraphModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphModel *_t = static_cast<GraphModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SelectionChanged((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 1: _t->Disconnected((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 2: _t->StateChanged((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 3: _t->PolynomialChanged((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 4: _t->TagChanged((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 5: { QList<GraphModel*> _r = _t->getDaughters((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        case 6: { QList<GraphModel*> _r = _t->getDaughters2((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        case 7: _t->selectBond((*reinterpret_cast< EdgeModel(*)>(_a[1]))); break;
        case 8: _t->unselectBond(); break;
        case 9: { bool _r = _t->isBondSelected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { EdgeModel _r = _t->getSelectedBond();
            if (_a[0]) *reinterpret_cast< EdgeModel*>(_a[0]) = _r; }  break;
        case 11: { QList<GraphModel*> _r = _t->getFragments();
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        case 12: { QString _r = _t->getZZInput((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->getZZInput2((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: _t->setmode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setDead((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->prepare(); break;
        case 17: _t->prepare2(); break;
        case 18: { GraphModel* _r = _t->getNoBondDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< GraphModel**>(_a[0]) = _r; }  break;
        case 19: { GraphModel* _r = _t->getNoAtomsDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< GraphModel**>(_a[0]) = _r; }  break;
        case 20: { QList<GraphModel*> _r = _t->getNoRingDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        case 21: { QList<GraphModel*> _r = _t->getNoStarDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        case 22: { QList<GraphModel*> _r = _t->getNoStarDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        case 23: { QList<GraphModel*> _r = _t->getNoStarDaughter((*reinterpret_cast< EdgeModel(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphModel::*_t)(GraphModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel::SelectionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphModel::*_t)(GraphModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel::Disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphModel::*_t)(GraphModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel::StateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GraphModel::*_t)(GraphModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel::PolynomialChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GraphModel::*_t)(GraphModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphModel::TagChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject GraphModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GraphModel.data,
      qt_meta_data_GraphModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GraphModel.stringdata0))
        return static_cast<void*>(const_cast< GraphModel*>(this));
    return QObject::qt_metacast(_clname);
}

int GraphModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void GraphModel::SelectionChanged(GraphModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphModel::Disconnected(GraphModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphModel::StateChanged(GraphModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphModel::PolynomialChanged(GraphModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphModel::TagChanged(GraphModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
