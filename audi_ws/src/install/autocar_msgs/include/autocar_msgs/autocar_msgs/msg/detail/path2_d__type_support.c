// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from autocar_msgs:msg/Path2D.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "autocar_msgs/msg/detail/path2_d__rosidl_typesupport_introspection_c.h"
#include "autocar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "autocar_msgs/msg/detail/path2_d__functions.h"
#include "autocar_msgs/msg/detail/path2_d__struct.h"


// Include directives for member types
// Member `poses`
#include "geometry_msgs/msg/pose2_d.h"
// Member `poses`
#include "geometry_msgs/msg/detail/pose2_d__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  autocar_msgs__msg__Path2D__init(message_memory);
}

void autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_fini_function(void * message_memory)
{
  autocar_msgs__msg__Path2D__fini(message_memory);
}

size_t autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__size_function__Path2D__poses(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose2D__Sequence * member =
    (const geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return member->size;
}

const void * autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__get_const_function__Path2D__poses(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose2D__Sequence * member =
    (const geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return &member->data[index];
}

void * autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__get_function__Path2D__poses(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose2D__Sequence * member =
    (geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return &member->data[index];
}

void autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__fetch_function__Path2D__poses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Pose2D * item =
    ((const geometry_msgs__msg__Pose2D *)
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__get_const_function__Path2D__poses(untyped_member, index));
  geometry_msgs__msg__Pose2D * value =
    (geometry_msgs__msg__Pose2D *)(untyped_value);
  *value = *item;
}

void autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__assign_function__Path2D__poses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Pose2D * item =
    ((geometry_msgs__msg__Pose2D *)
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__get_function__Path2D__poses(untyped_member, index));
  const geometry_msgs__msg__Pose2D * value =
    (const geometry_msgs__msg__Pose2D *)(untyped_value);
  *item = *value;
}

bool autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__resize_function__Path2D__poses(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose2D__Sequence * member =
    (geometry_msgs__msg__Pose2D__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose2D__Sequence__fini(member);
  return geometry_msgs__msg__Pose2D__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_member_array[1] = {
  {
    "poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(autocar_msgs__msg__Path2D, poses),  // bytes offset in struct
    NULL,  // default value
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__size_function__Path2D__poses,  // size() function pointer
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__get_const_function__Path2D__poses,  // get_const(index) function pointer
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__get_function__Path2D__poses,  // get(index) function pointer
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__fetch_function__Path2D__poses,  // fetch(index, &value) function pointer
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__assign_function__Path2D__poses,  // assign(index, value) function pointer
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__resize_function__Path2D__poses  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_members = {
  "autocar_msgs__msg",  // message namespace
  "Path2D",  // message name
  1,  // number of fields
  sizeof(autocar_msgs__msg__Path2D),
  autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_member_array,  // message members
  autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_init_function,  // function to initialize message memory (memory has to be allocated)
  autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_type_support_handle = {
  0,
  &autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_autocar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, autocar_msgs, msg, Path2D)() {
  autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose2D)();
  if (!autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_type_support_handle.typesupport_identifier) {
    autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &autocar_msgs__msg__Path2D__rosidl_typesupport_introspection_c__Path2D_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
