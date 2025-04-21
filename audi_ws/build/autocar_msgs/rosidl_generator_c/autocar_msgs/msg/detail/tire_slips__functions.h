// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from autocar_msgs:msg/TireSlips.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__FUNCTIONS_H_
#define AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "autocar_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "autocar_msgs/msg/detail/tire_slips__struct.h"

/// Initialize msg/TireSlips message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * autocar_msgs__msg__TireSlips
 * )) before or use
 * autocar_msgs__msg__TireSlips__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
bool
autocar_msgs__msg__TireSlips__init(autocar_msgs__msg__TireSlips * msg);

/// Finalize msg/TireSlips message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
void
autocar_msgs__msg__TireSlips__fini(autocar_msgs__msg__TireSlips * msg);

/// Create msg/TireSlips message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * autocar_msgs__msg__TireSlips__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
autocar_msgs__msg__TireSlips *
autocar_msgs__msg__TireSlips__create();

/// Destroy msg/TireSlips message.
/**
 * It calls
 * autocar_msgs__msg__TireSlips__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
void
autocar_msgs__msg__TireSlips__destroy(autocar_msgs__msg__TireSlips * msg);

/// Check for msg/TireSlips message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
bool
autocar_msgs__msg__TireSlips__are_equal(const autocar_msgs__msg__TireSlips * lhs, const autocar_msgs__msg__TireSlips * rhs);

/// Copy a msg/TireSlips message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
bool
autocar_msgs__msg__TireSlips__copy(
  const autocar_msgs__msg__TireSlips * input,
  autocar_msgs__msg__TireSlips * output);

/// Initialize array of msg/TireSlips messages.
/**
 * It allocates the memory for the number of elements and calls
 * autocar_msgs__msg__TireSlips__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
bool
autocar_msgs__msg__TireSlips__Sequence__init(autocar_msgs__msg__TireSlips__Sequence * array, size_t size);

/// Finalize array of msg/TireSlips messages.
/**
 * It calls
 * autocar_msgs__msg__TireSlips__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
void
autocar_msgs__msg__TireSlips__Sequence__fini(autocar_msgs__msg__TireSlips__Sequence * array);

/// Create array of msg/TireSlips messages.
/**
 * It allocates the memory for the array and calls
 * autocar_msgs__msg__TireSlips__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
autocar_msgs__msg__TireSlips__Sequence *
autocar_msgs__msg__TireSlips__Sequence__create(size_t size);

/// Destroy array of msg/TireSlips messages.
/**
 * It calls
 * autocar_msgs__msg__TireSlips__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
void
autocar_msgs__msg__TireSlips__Sequence__destroy(autocar_msgs__msg__TireSlips__Sequence * array);

/// Check for msg/TireSlips message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
bool
autocar_msgs__msg__TireSlips__Sequence__are_equal(const autocar_msgs__msg__TireSlips__Sequence * lhs, const autocar_msgs__msg__TireSlips__Sequence * rhs);

/// Copy an array of msg/TireSlips messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_autocar_msgs
bool
autocar_msgs__msg__TireSlips__Sequence__copy(
  const autocar_msgs__msg__TireSlips__Sequence * input,
  autocar_msgs__msg__TireSlips__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__FUNCTIONS_H_
