// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autocar_msgs:msg/Path2D.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__PATH2_D__STRUCT_H_
#define AUTOCAR_MSGS__MSG__DETAIL__PATH2_D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'poses'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"

/// Struct defined in msg/Path2D in the package autocar_msgs.
typedef struct autocar_msgs__msg__Path2D
{
  geometry_msgs__msg__Pose2D__Sequence poses;
} autocar_msgs__msg__Path2D;

// Struct for a sequence of autocar_msgs__msg__Path2D.
typedef struct autocar_msgs__msg__Path2D__Sequence
{
  autocar_msgs__msg__Path2D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autocar_msgs__msg__Path2D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOCAR_MSGS__MSG__DETAIL__PATH2_D__STRUCT_H_
