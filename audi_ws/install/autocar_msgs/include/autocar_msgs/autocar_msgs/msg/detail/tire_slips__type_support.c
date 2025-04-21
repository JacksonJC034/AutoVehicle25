// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from autocar_msgs:msg/TireSlips.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "autocar_msgs/msg/detail/tire_slips__rosidl_typesupport_introspection_c.h"
#include "autocar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "autocar_msgs/msg/detail/tire_slips__functions.h"
#include "autocar_msgs/msg/detail/tire_slips__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  autocar_msgs__msg__TireSlips__init(message_memory);
}

void autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_fini_function(void * message_memory)
{
  autocar_msgs__msg__TireSlips__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__TireSlips, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "front_alpha",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__TireSlips, front_alpha),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rear_alpha",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__TireSlips, rear_alpha),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "front_k",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__TireSlips, front_k),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rear_k",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__TireSlips, rear_k),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_members = {
  "autocar_msgs__msg",  // message namespace
  "TireSlips",  // message name
  5,  // number of fields
  sizeof(autocar_msgs__msg__TireSlips),
  autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_member_array,  // message members
  autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_init_function,  // function to initialize message memory (memory has to be allocated)
  autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_type_support_handle = {
  0,
  &autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_autocar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, autocar_msgs, msg, TireSlips)() {
  autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_type_support_handle.typesupport_identifier) {
    autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &autocar_msgs__msg__TireSlips__rosidl_typesupport_introspection_c__TireSlips_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
