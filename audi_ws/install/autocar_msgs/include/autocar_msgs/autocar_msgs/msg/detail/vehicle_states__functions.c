// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from autocar_msgs:msg/VehicleStates.idl
// generated code does not contain a copyright notice
#include "autocar_msgs/msg/detail/vehicle_states__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
autocar_msgs__msg__VehicleStates__init(autocar_msgs__msg__VehicleStates * msg)
{
  if (!msg) {
    return false;
  }
  // time
  // x
  // y
  // theta
  // fr_angle
  // fl_angle
  // br_angle
  // bl_angle
  return true;
}

void
autocar_msgs__msg__VehicleStates__fini(autocar_msgs__msg__VehicleStates * msg)
{
  if (!msg) {
    return;
  }
  // time
  // x
  // y
  // theta
  // fr_angle
  // fl_angle
  // br_angle
  // bl_angle
}

bool
autocar_msgs__msg__VehicleStates__are_equal(const autocar_msgs__msg__VehicleStates * lhs, const autocar_msgs__msg__VehicleStates * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  // fr_angle
  if (lhs->fr_angle != rhs->fr_angle) {
    return false;
  }
  // fl_angle
  if (lhs->fl_angle != rhs->fl_angle) {
    return false;
  }
  // br_angle
  if (lhs->br_angle != rhs->br_angle) {
    return false;
  }
  // bl_angle
  if (lhs->bl_angle != rhs->bl_angle) {
    return false;
  }
  return true;
}

bool
autocar_msgs__msg__VehicleStates__copy(
  const autocar_msgs__msg__VehicleStates * input,
  autocar_msgs__msg__VehicleStates * output)
{
  if (!input || !output) {
    return false;
  }
  // time
  output->time = input->time;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  // fr_angle
  output->fr_angle = input->fr_angle;
  // fl_angle
  output->fl_angle = input->fl_angle;
  // br_angle
  output->br_angle = input->br_angle;
  // bl_angle
  output->bl_angle = input->bl_angle;
  return true;
}

autocar_msgs__msg__VehicleStates *
autocar_msgs__msg__VehicleStates__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__VehicleStates * msg = (autocar_msgs__msg__VehicleStates *)allocator.allocate(sizeof(autocar_msgs__msg__VehicleStates), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autocar_msgs__msg__VehicleStates));
  bool success = autocar_msgs__msg__VehicleStates__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autocar_msgs__msg__VehicleStates__destroy(autocar_msgs__msg__VehicleStates * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autocar_msgs__msg__VehicleStates__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autocar_msgs__msg__VehicleStates__Sequence__init(autocar_msgs__msg__VehicleStates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__VehicleStates * data = NULL;

  if (size) {
    data = (autocar_msgs__msg__VehicleStates *)allocator.zero_allocate(size, sizeof(autocar_msgs__msg__VehicleStates), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autocar_msgs__msg__VehicleStates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autocar_msgs__msg__VehicleStates__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
autocar_msgs__msg__VehicleStates__Sequence__fini(autocar_msgs__msg__VehicleStates__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      autocar_msgs__msg__VehicleStates__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

autocar_msgs__msg__VehicleStates__Sequence *
autocar_msgs__msg__VehicleStates__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__VehicleStates__Sequence * array = (autocar_msgs__msg__VehicleStates__Sequence *)allocator.allocate(sizeof(autocar_msgs__msg__VehicleStates__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autocar_msgs__msg__VehicleStates__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autocar_msgs__msg__VehicleStates__Sequence__destroy(autocar_msgs__msg__VehicleStates__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autocar_msgs__msg__VehicleStates__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autocar_msgs__msg__VehicleStates__Sequence__are_equal(const autocar_msgs__msg__VehicleStates__Sequence * lhs, const autocar_msgs__msg__VehicleStates__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autocar_msgs__msg__VehicleStates__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autocar_msgs__msg__VehicleStates__Sequence__copy(
  const autocar_msgs__msg__VehicleStates__Sequence * input,
  autocar_msgs__msg__VehicleStates__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autocar_msgs__msg__VehicleStates);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autocar_msgs__msg__VehicleStates * data =
      (autocar_msgs__msg__VehicleStates *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autocar_msgs__msg__VehicleStates__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autocar_msgs__msg__VehicleStates__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autocar_msgs__msg__VehicleStates__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
