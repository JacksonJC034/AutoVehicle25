// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from autocar_msgs:msg/TireSlips.idl
// generated code does not contain a copyright notice
#include "autocar_msgs/msg/detail/tire_slips__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
autocar_msgs__msg__TireSlips__init(autocar_msgs__msg__TireSlips * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    autocar_msgs__msg__TireSlips__fini(msg);
    return false;
  }
  // front_alpha
  // rear_alpha
  // front_k
  // rear_k
  return true;
}

void
autocar_msgs__msg__TireSlips__fini(autocar_msgs__msg__TireSlips * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // front_alpha
  // rear_alpha
  // front_k
  // rear_k
}

bool
autocar_msgs__msg__TireSlips__are_equal(const autocar_msgs__msg__TireSlips * lhs, const autocar_msgs__msg__TireSlips * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // front_alpha
  if (lhs->front_alpha != rhs->front_alpha) {
    return false;
  }
  // rear_alpha
  if (lhs->rear_alpha != rhs->rear_alpha) {
    return false;
  }
  // front_k
  if (lhs->front_k != rhs->front_k) {
    return false;
  }
  // rear_k
  if (lhs->rear_k != rhs->rear_k) {
    return false;
  }
  return true;
}

bool
autocar_msgs__msg__TireSlips__copy(
  const autocar_msgs__msg__TireSlips * input,
  autocar_msgs__msg__TireSlips * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // front_alpha
  output->front_alpha = input->front_alpha;
  // rear_alpha
  output->rear_alpha = input->rear_alpha;
  // front_k
  output->front_k = input->front_k;
  // rear_k
  output->rear_k = input->rear_k;
  return true;
}

autocar_msgs__msg__TireSlips *
autocar_msgs__msg__TireSlips__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__TireSlips * msg = (autocar_msgs__msg__TireSlips *)allocator.allocate(sizeof(autocar_msgs__msg__TireSlips), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autocar_msgs__msg__TireSlips));
  bool success = autocar_msgs__msg__TireSlips__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autocar_msgs__msg__TireSlips__destroy(autocar_msgs__msg__TireSlips * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autocar_msgs__msg__TireSlips__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autocar_msgs__msg__TireSlips__Sequence__init(autocar_msgs__msg__TireSlips__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__TireSlips * data = NULL;

  if (size) {
    data = (autocar_msgs__msg__TireSlips *)allocator.zero_allocate(size, sizeof(autocar_msgs__msg__TireSlips), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autocar_msgs__msg__TireSlips__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autocar_msgs__msg__TireSlips__fini(&data[i - 1]);
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
autocar_msgs__msg__TireSlips__Sequence__fini(autocar_msgs__msg__TireSlips__Sequence * array)
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
      autocar_msgs__msg__TireSlips__fini(&array->data[i]);
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

autocar_msgs__msg__TireSlips__Sequence *
autocar_msgs__msg__TireSlips__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autocar_msgs__msg__TireSlips__Sequence * array = (autocar_msgs__msg__TireSlips__Sequence *)allocator.allocate(sizeof(autocar_msgs__msg__TireSlips__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autocar_msgs__msg__TireSlips__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autocar_msgs__msg__TireSlips__Sequence__destroy(autocar_msgs__msg__TireSlips__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autocar_msgs__msg__TireSlips__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autocar_msgs__msg__TireSlips__Sequence__are_equal(const autocar_msgs__msg__TireSlips__Sequence * lhs, const autocar_msgs__msg__TireSlips__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autocar_msgs__msg__TireSlips__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autocar_msgs__msg__TireSlips__Sequence__copy(
  const autocar_msgs__msg__TireSlips__Sequence * input,
  autocar_msgs__msg__TireSlips__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autocar_msgs__msg__TireSlips);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autocar_msgs__msg__TireSlips * data =
      (autocar_msgs__msg__TireSlips *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autocar_msgs__msg__TireSlips__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autocar_msgs__msg__TireSlips__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autocar_msgs__msg__TireSlips__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
