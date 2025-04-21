// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from autocar_msgs:msg/SlipCondition.idl
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
#include "autocar_msgs/msg/detail/slip_condition__struct.h"
#include "autocar_msgs/msg/detail/slip_condition__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool autocar_msgs__msg__slip_condition__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("autocar_msgs.msg._slip_condition.SlipCondition", full_classname_dest, 46) == 0);
  }
  autocar_msgs__msg__SlipCondition * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // front_saturated
    PyObject * field = PyObject_GetAttrString(_pymsg, "front_saturated");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->front_saturated = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rear_saturated
    PyObject * field = PyObject_GetAttrString(_pymsg, "rear_saturated");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->rear_saturated = (Py_True == field);
    Py_DECREF(field);
  }
  {  // front_delta_alpha
    PyObject * field = PyObject_GetAttrString(_pymsg, "front_delta_alpha");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->front_delta_alpha = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // front_delta_k
    PyObject * field = PyObject_GetAttrString(_pymsg, "front_delta_k");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->front_delta_k = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rear_delta_alpha
    PyObject * field = PyObject_GetAttrString(_pymsg, "rear_delta_alpha");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rear_delta_alpha = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rear_delta_k
    PyObject * field = PyObject_GetAttrString(_pymsg, "rear_delta_k");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rear_delta_k = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * autocar_msgs__msg__slip_condition__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SlipCondition */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("autocar_msgs.msg._slip_condition");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SlipCondition");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  autocar_msgs__msg__SlipCondition * ros_message = (autocar_msgs__msg__SlipCondition *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // front_saturated
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->front_saturated ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "front_saturated", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rear_saturated
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->rear_saturated ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rear_saturated", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // front_delta_alpha
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->front_delta_alpha);
    {
      int rc = PyObject_SetAttrString(_pymessage, "front_delta_alpha", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // front_delta_k
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->front_delta_k);
    {
      int rc = PyObject_SetAttrString(_pymessage, "front_delta_k", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rear_delta_alpha
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rear_delta_alpha);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rear_delta_alpha", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rear_delta_k
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rear_delta_k);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rear_delta_k", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
