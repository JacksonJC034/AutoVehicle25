// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autocar_msgs:msg/VehicleStates.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__STRUCT_H_
#define AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'wheel_speeds'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/VehicleStates in the package autocar_msgs.
typedef struct autocar_msgs__msg__VehicleStates
{
  double time;
  double x;
  double y;
  double theta;
  double fr_angle;
  double fl_angle;
  double br_angle;
  double bl_angle;
  double vx;
  double vy;
  /// [fr, fl, br, bl]
  rosidl_runtime_c__double__Sequence wheel_speeds;
} autocar_msgs__msg__VehicleStates;

// Struct for a sequence of autocar_msgs__msg__VehicleStates.
typedef struct autocar_msgs__msg__VehicleStates__Sequence
{
  autocar_msgs__msg__VehicleStates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autocar_msgs__msg__VehicleStates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__STRUCT_H_
