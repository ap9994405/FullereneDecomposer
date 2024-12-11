/****************************************************************************
** Meta object code from reading C++ file 'decomposer2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "decomposer2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'decomposer2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Decomposer2_t {
    QByteArrayData data[25];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Decomposer2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Decomposer2_t qt_meta_stringdata_Decomposer2 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Decomposer2"
QT_MOC_LITERAL(1, 12, 19), // "ZZPolynomialRequest"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "GraphModel*"
QT_MOC_LITERAL(4, 45, 5), // "model"
QT_MOC_LITERAL(5, 51, 24), // "childZZPolynomialRequest"
QT_MOC_LITERAL(6, 76, 12), // "setRootGraph"
QT_MOC_LITERAL(7, 89, 5), // "graph"
QT_MOC_LITERAL(8, 95, 8), // "getLeafs"
QT_MOC_LITERAL(9, 104, 18), // "QList<GraphModel*>"
QT_MOC_LITERAL(10, 123, 5), // "clear"
QT_MOC_LITERAL(11, 129, 17), // "setAllowFragments"
QT_MOC_LITERAL(12, 147, 6), // "enable"
QT_MOC_LITERAL(13, 154, 14), // "allowFragments"
QT_MOC_LITERAL(14, 169, 9), // "exportSVG"
QT_MOC_LITERAL(15, 179, 8), // "filename"
QT_MOC_LITERAL(16, 188, 10), // "compressed"
QT_MOC_LITERAL(17, 199, 13), // "setGridRotate"
QT_MOC_LITERAL(18, 213, 6), // "rotate"
QT_MOC_LITERAL(19, 220, 10), // "reposition"
QT_MOC_LITERAL(20, 231, 21), // "graphSelectionChanged"
QT_MOC_LITERAL(21, 253, 8), // "addChild"
QT_MOC_LITERAL(22, 262, 6), // "parent"
QT_MOC_LITERAL(23, 269, 5), // "child"
QT_MOC_LITERAL(24, 275, 10) // "tagChanged"

    },
    "Decomposer2\0ZZPolynomialRequest\0\0"
    "GraphModel*\0model\0childZZPolynomialRequest\0"
    "setRootGraph\0graph\0getLeafs\0"
    "QList<GraphModel*>\0clear\0setAllowFragments\0"
    "enable\0allowFragments\0exportSVG\0"
    "filename\0compressed\0setGridRotate\0"
    "rotate\0reposition\0graphSelectionChanged\0"
    "addChild\0parent\0child\0tagChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Decomposer2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x0a /* Public */,
       8,    0,   88,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    2,   94,    2, 0x0a /* Public */,
      17,    1,   99,    2, 0x0a /* Public */,
      19,    0,  102,    2, 0x0a /* Public */,
      20,    1,  103,    2, 0x08 /* Private */,
      21,    2,  106,    2, 0x08 /* Private */,
      24,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    7,
    0x80000000 | 9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   15,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   22,   23,
    QMetaType::Void,

       0        // eod
};

void Decomposer2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Decomposer2 *_t = static_cast<Decomposer2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ZZPolynomialRequest((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 1: _t->childZZPolynomialRequest((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 2: _t->setRootGraph((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 3: { QList<GraphModel*> _r = _t->getLeafs();
            if (_a[0]) *reinterpret_cast< QList<GraphModel*>*>(_a[0]) = _r; }  break;
        case 4: _t->clear(); break;
        case 5: _t->setAllowFragments((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: { bool _r = _t->allowFragments();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->exportSVG((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->setGridRotate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->reposition(); break;
        case 10: _t->graphSelectionChanged((*reinterpret_cast< GraphModel*(*)>(_a[1]))); break;
        case 11: _t->addChild((*reinterpret_cast< GraphModel*(*)>(_a[1])),(*reinterpret_cast< GraphModel*(*)>(_a[2]))); break;
        case 12: _t->tagChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Decomposer2::*_t)(GraphModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Decomposer2::ZZPolynomialRequest)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Decomposer2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Decomposer2.data,
      qt_meta_data_Decomposer2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Decomposer2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Decomposer2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Decomposer2.stringdata0))
        return static_cast<void*>(const_cast< Decomposer2*>(this));
    return QWidget::qt_metacast(_clname);
}

int Decomposer2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Decomposer2::ZZPolynomialRequest(GraphModel * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
