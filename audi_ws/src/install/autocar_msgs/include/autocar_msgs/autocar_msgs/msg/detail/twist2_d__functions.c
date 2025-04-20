// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from autocar_msgs:msg/Twist2D.idl
// generated code does not contain a copyright notice
#include "autocar_msgs/msg/detail/twist2_d__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
autocar_msgs__msg__Twist2D__init(autocar_msgs__msg__Twist2D * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // w
  return true;
}

void
autocar_msgs__msg__Twist2D__fini(autocar_msgs__msg__Twist2D * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // w
}

bool
autocar_msgs__msg__Twist2D__are_equal(const autocar_msgs__msg__Twist2D * lhs, const autocar_msgs__msg__Twist2D * rhs)
{
  if (!lhs || !rhs) {
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
  // w
  if (lhs->w != rhs->w) {
    return false;
  }
  return true;
}

bool
autocar_msgs__msg__Twist2D__copy(
  const autocar_msgs__msg__Twist2D * input,
  autocar_msgs__msg__Twist2D * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // w
  output->w = input->w;
  return true;
}

autocar_msgs__msg__Twist2D *
autocar_msgs__msg__Twist2D__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__Twist2D * msg = (autocar_msgs__msg__Twist2D *)allocator.allocate(sizeof(autocar_msgs__msg__Twist2D), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autocar_msgs__msg__Twist2D));
  bool success = autocar_msgs__msg__Twist2D__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autocar_msgs__msg__Twist2D__destroy(autocar_msgs__msg__Twist2D * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autocar_msgs__msg__Twist2D__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autocar_msgs__msg__Twist2D__Sequence__init(autocar_msgs__msg__Twist2D__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__Twist2D * data = NULL;

  if (size) {
    data = (autocar_msgs__msg__Twist2D *)allocator.zero_allocate(size, sizeof(autocar_msgs__msg__Twist2D), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autocar_msgs__msg__Twist2D__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autocar_msgs__msg__Twist2D__fini(&data[i - 1]);
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
autocar_msgs__msg__Twist2D__Sequence__fini(autocar_msgs__msg__Twist2D__Sequence * array)
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
      autocar_msgs__msg__Twist2D__fini(&array->data[i]);
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

autocar_msgs__msg__Twist2D__Sequence *
autocar_msgs__msg__Twist2D__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__Twist2D__Sequence * array = (autocar_msgs__msg__Twist2D__Sequence *)allocator.allocate(sizeof(autocar_msgs__msg__Twist2D__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autocar_msgs__msg__Twist2D__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autocar_msgs__msg__Twist2D__Sequence__destroy(autocar_msgs__msg__Twist2D__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autocar_msgs__msg__Twist2D__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autocar_msgs__msg__Twist2D__Sequence__are_equal(const autocar_msgs__msg__Twist2D__Sequence * lhs, const autocar_msgs__msg__Twist2D__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autocar_msgs__msg__Twist2D__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autocar_msgs__msg__Twist2D__Sequence__copy(
  const autocar_msgs__msg__Twist2D__Sequence * input,
  autocar_msgs__msg__Twist2D__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autocar_msgs__msg__Twist2D);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autocar_msgs__msg__Twist2D * data =
      (autocar_msgs__msg__Twist2D *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autocar_msgs__msg__Twist2D__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autocar_msgs__msg__Twist2D__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autocar_msgs__msg__Twist2D__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
