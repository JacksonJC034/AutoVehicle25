// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from autocar_msgs:msg/VehicleStates.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "autocar_msgs/msg/detail/vehicle_states__struct.h"
#include "autocar_msgs/msg/detail/vehicle_states__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool autocar_msgs__msg__vehicle_states__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("autocar_msgs.msg._vehicle_states.VehicleStates", full_classname_dest, 46) == 0);
  }
  autocar_msgs__msg__VehicleStates * ros_message = _ros_message;
  {  // time
    PyObject * field = PyObject_GetAttrString(_pymsg, "time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fr_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "fr_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fr_angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // fl_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "fl_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fl_angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // br_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "br_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->br_angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bl_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "bl_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bl_angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * autocar_msgs__msg__vehicle_states__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VehicleStates */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("autocar_msgs.msg._vehicle_states");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VehicleStates");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  autocar_msgs__msg__VehicleStates * ros_message = (autocar_msgs__msg__VehicleStates *)raw_ros_message;
  {  // time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fr_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fr_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fr_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fl_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fl_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fl_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // br_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->br_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "br_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bl_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bl_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bl_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
