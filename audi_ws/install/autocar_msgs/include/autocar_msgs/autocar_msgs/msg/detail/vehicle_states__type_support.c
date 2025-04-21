// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from autocar_msgs:msg/VehicleStates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "autocar_msgs/msg/detail/vehicle_states__rosidl_typesupport_introspection_c.h"
#include "autocar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "autocar_msgs/msg/detail/vehicle_states__functions.h"
#include "autocar_msgs/msg/detail/vehicle_states__struct.h"


// Include directives for member types
// Member `wheel_speeds`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  autocar_msgs__msg__VehicleStates__init(message_memory);
}

void autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_fini_function(void * message_memory)
{
  autocar_msgs__msg__VehicleStates__fini(message_memory);
}

size_t autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__size_function__VehicleStates__wheel_speeds(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__get_const_function__VehicleStates__wheel_speeds(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__get_function__VehicleStates__wheel_speeds(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__fetch_function__VehicleStates__wheel_speeds(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__get_const_function__VehicleStates__wheel_speeds(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__assign_function__VehicleStates__wheel_speeds(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__get_function__VehicleStates__wheel_speeds(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__resize_function__VehicleStates__wheel_speeds(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_member_array[11] = {
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, theta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fr_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, fr_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fl_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, fl_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "br_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, br_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bl_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, bl_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, vx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, vy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wheel_speeds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__VehicleStates, wheel_speeds),  // bytes offset in struct
    NULL,  // default value
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__size_function__VehicleStates__wheel_speeds,  // size() function pointer
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__get_const_function__VehicleStates__wheel_speeds,  // get_const(index) function pointer
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__get_function__VehicleStates__wheel_speeds,  // get(index) function pointer
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__fetch_function__VehicleStates__wheel_speeds,  // fetch(index, &value) function pointer
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__assign_function__VehicleStates__wheel_speeds,  // assign(index, value) function pointer
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__resize_function__VehicleStates__wheel_speeds  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_members = {
  "autocar_msgs__msg",  // message namespace
  "VehicleStates",  // message name
  11,  // number of fields
  sizeof(autocar_msgs__msg__VehicleStates),
  autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_member_array,  // message members
  autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_init_function,  // function to initialize message memory (memory has to be allocated)
  autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_type_support_handle = {
  0,
  &autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_autocar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, autocar_msgs, msg, VehicleStates)() {
  if (!autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_type_support_handle.typesupport_identifier) {
    autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &autocar_msgs__msg__VehicleStates__rosidl_typesupport_introspection_c__VehicleStates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
