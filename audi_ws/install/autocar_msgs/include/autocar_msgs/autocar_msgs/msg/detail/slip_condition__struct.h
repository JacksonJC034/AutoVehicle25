// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autocar_msgs:msg/SlipCondition.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__STRUCT_H_
#define AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/SlipCondition in the package autocar_msgs.
typedef struct autocar_msgs__msg__SlipCondition
{
  std_msgs__msg__Header header;
  bool front_saturated;
  bool rear_saturated;
  double front_delta_alpha;
  double front_delta_k;
  double rear_delta_alpha;
  double rear_delta_k;
} autocar_msgs__msg__SlipCondition;

// Struct for a sequence of autocar_msgs__msg__SlipCondition.
typedef struct autocar_msgs__msg__SlipCondition__Sequence
{
  autocar_msgs__msg__SlipCondition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autocar_msgs__msg__SlipCondition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__STRUCT_H_
