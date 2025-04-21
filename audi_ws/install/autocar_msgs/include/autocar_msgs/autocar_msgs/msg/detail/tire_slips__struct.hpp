// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from autocar_msgs:msg/TireSlips.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__STRUCT_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__STRUCT_HPP_

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
# define DEPRECATED__autocar_msgs__msg__TireSlips __attribute__((deprecated))
#else
# define DEPRECATED__autocar_msgs__msg__TireSlips __declspec(deprecated)
#endif

namespace autocar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TireSlips_
{
  using Type = TireSlips_<ContainerAllocator>;

  explicit TireSlips_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_alpha = 0.0;
      this->rear_alpha = 0.0;
      this->front_k = 0.0;
      this->rear_k = 0.0;
    }
  }

  explicit TireSlips_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->front_alpha = 0.0;
      this->rear_alpha = 0.0;
      this->front_k = 0.0;
      this->rear_k = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _front_alpha_type =
    double;
  _front_alpha_type front_alpha;
  using _rear_alpha_type =
    double;
  _rear_alpha_type rear_alpha;
  using _front_k_type =
    double;
  _front_k_type front_k;
  using _rear_k_type =
    double;
  _rear_k_type rear_k;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__front_alpha(
    const double & _arg)
  {
    this->front_alpha = _arg;
    return *this;
  }
  Type & set__rear_alpha(
    const double & _arg)
  {
    this->rear_alpha = _arg;
    return *this;
  }
  Type & set__front_k(
    const double & _arg)
  {
    this->front_k = _arg;
    return *this;
  }
  Type & set__rear_k(
    const double & _arg)
  {
    this->rear_k = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    autocar_msgs::msg::TireSlips_<ContainerAllocator> *;
  using ConstRawPtr =
    const autocar_msgs::msg::TireSlips_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      autocar_msgs::msg::TireSlips_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      autocar_msgs::msg::TireSlips_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__autocar_msgs__msg__TireSlips
    std::shared_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__autocar_msgs__msg__TireSlips
    std::shared_ptr<autocar_msgs::msg::TireSlips_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TireSlips_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->front_alpha != other.front_alpha) {
      return false;
    }
    if (this->rear_alpha != other.rear_alpha) {
      return false;
    }
    if (this->front_k != other.front_k) {
      return false;
    }
    if (this->rear_k != other.rear_k) {
      return false;
    }
    return true;
  }
  bool operator!=(const TireSlips_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TireSlips_

// alias to use template instance with default allocator
using TireSlips =
  autocar_msgs::msg::TireSlips_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__STRUCT_HPP_
