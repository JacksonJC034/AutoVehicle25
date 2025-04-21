// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from autocar_msgs:msg/SlipCondition.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__STRUCT_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__autocar_msgs__msg__SlipCondition __attribute__((deprecated))
#else
# define DEPRECATED__autocar_msgs__msg__SlipCondition __declspec(deprecated)
#endif

namespace autocar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SlipCondition_
{
  using Type = SlipCondition_<ContainerAllocator>;

  explicit SlipCondition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_saturated = false;
      this->rear_saturated = false;
      this->front_delta_alpha = 0.0;
      this->front_delta_k = 0.0;
      this->rear_delta_alpha = 0.0;
      this->rear_delta_k = 0.0;
    }
  }

  explicit SlipCondition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_saturated = false;
      this->rear_saturated = false;
      this->front_delta_alpha = 0.0;
      this->front_delta_k = 0.0;
      this->rear_delta_alpha = 0.0;
      this->rear_delta_k = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _front_saturated_type =
    bool;
  _front_saturated_type front_saturated;
  using _rear_saturated_type =
    bool;
  _rear_saturated_type rear_saturated;
  using _front_delta_alpha_type =
    double;
  _front_delta_alpha_type front_delta_alpha;
  using _front_delta_k_type =
    double;
  _front_delta_k_type front_delta_k;
  using _rear_delta_alpha_type =
    double;
  _rear_delta_alpha_type rear_delta_alpha;
  using _rear_delta_k_type =
    double;
  _rear_delta_k_type rear_delta_k;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__front_saturated(
    const bool & _arg)
  {
    this->front_saturated = _arg;
    return *this;
  }
  Type & set__rear_saturated(
    const bool & _arg)
  {
    this->rear_saturated = _arg;
    return *this;
  }
  Type & set__front_delta_alpha(
    const double & _arg)
  {
    this->front_delta_alpha = _arg;
    return *this;
  }
  Type & set__front_delta_k(
    const double & _arg)
  {
    this->front_delta_k = _arg;
    return *this;
  }
  Type & set__rear_delta_alpha(
    const double & _arg)
  {
    this->rear_delta_alpha = _arg;
    return *this;
  }
  Type & set__rear_delta_k(
    const double & _arg)
  {
    this->rear_delta_k = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    autocar_msgs::msg::SlipCondition_<ContainerAllocator> *;
  using ConstRawPtr =
    const autocar_msgs::msg::SlipCondition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      autocar_msgs::msg::SlipCondition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      autocar_msgs::msg::SlipCondition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__autocar_msgs__msg__SlipCondition
    std::shared_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__autocar_msgs__msg__SlipCondition
    std::shared_ptr<autocar_msgs::msg::SlipCondition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SlipCondition_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->front_saturated != other.front_saturated) {
      return false;
    }
    if (this->rear_saturated != other.rear_saturated) {
      return false;
    }
    if (this->front_delta_alpha != other.front_delta_alpha) {
      return false;
    }
    if (this->front_delta_k != other.front_delta_k) {
      return false;
    }
    if (this->rear_delta_alpha != other.rear_delta_alpha) {
      return false;
    }
    if (this->rear_delta_k != other.rear_delta_k) {
      return false;
    }
    return true;
  }
  bool operator!=(const SlipCondition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SlipCondition_

// alias to use template instance with default allocator
using SlipCondition =
  autocar_msgs::msg::SlipCondition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__STRUCT_HPP_
