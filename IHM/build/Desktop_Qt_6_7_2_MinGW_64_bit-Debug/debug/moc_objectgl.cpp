/****************************************************************************
** Meta object code from reading C++ file 'objectgl.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../objectgl.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectgl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSObjectOpenGLENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSObjectOpenGLENDCLASS = QtMocHelpers::stringData(
    "ObjectOpenGL",
    "xRotationChanged",
    "",
    "angle",
    "yRotationChanged",
    "zRotationChanged",
    "FrontView",
    "RearView",
    "LeftView",
    "RightView",
    "TopView",
    "BottomView",
    "IsometricView",
    "SetXRotation",
    "SetYRotation",
    "SetZRotation"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSObjectOpenGLENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,
       4,    1,   95,    2, 0x06,    3 /* Public */,
       5,    1,   98,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  101,    2, 0x0a,    7 /* Public */,
       7,    0,  102,    2, 0x0a,    8 /* Public */,
       8,    0,  103,    2, 0x0a,    9 /* Public */,
       9,    0,  104,    2, 0x0a,   10 /* Public */,
      10,    0,  105,    2, 0x0a,   11 /* Public */,
      11,    0,  106,    2, 0x0a,   12 /* Public */,
      12,    0,  107,    2, 0x0a,   13 /* Public */,
      13,    1,  108,    2, 0x0a,   14 /* Public */,
      14,    1,  111,    2, 0x0a,   16 /* Public */,
      15,    1,  114,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject ObjectOpenGL::staticMetaObject = { {
    QMetaObject::SuperData::link<QGLWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSObjectOpenGLENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSObjectOpenGLENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSObjectOpenGLENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ObjectOpenGL, std::true_type>,
        // method 'xRotationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'yRotationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'zRotationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'FrontView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RearView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LeftView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RightView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'TopView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BottomView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'IsometricView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SetXRotation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SetYRotation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SetZRotation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ObjectOpenGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ObjectOpenGL *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->FrontView(); break;
        case 4: _t->RearView(); break;
        case 5: _t->LeftView(); break;
        case 6: _t->RightView(); break;
        case 7: _t->TopView(); break;
        case 8: _t->BottomView(); break;
        case 9: _t->IsometricView(); break;
        case 10: _t->SetXRotation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->SetYRotation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->SetZRotation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ObjectOpenGL::*)(int );
            if (_t _q_method = &ObjectOpenGL::xRotationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ObjectOpenGL::*)(int );
            if (_t _q_method = &ObjectOpenGL::yRotationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ObjectOpenGL::*)(int );
            if (_t _q_method = &ObjectOpenGL::zRotationChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ObjectOpenGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObjectOpenGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSObjectOpenGLENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int ObjectOpenGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ObjectOpenGL::xRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ObjectOpenGL::yRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ObjectOpenGL::zRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
