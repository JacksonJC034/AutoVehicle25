// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autocar_msgs:msg/State2D.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__STRUCT_H_
#define AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"
// Member 'twist'
#include "autocar_msgs/msg/detail/twist2_d__struct.h"

/// Struct defined in msg/State2D in the package autocar_msgs.
typedef struct autocar_msgs__msg__State2D
{
  geometry_msgs__msg__Pose2D pose;
  autocar_msgs__msg__Twist2D twist;
} autocar_msgs__msg__State2D;

// Struct for a sequence of autocar_msgs__msg__State2D.
typedef struct autocar_msgs__msg__State2D__Sequence
{
  autocar_msgs__msg__State2D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autocar_msgs__msg__State2D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__STRUCT_H_
