// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from autocar_msgs:msg/VehicleStates.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__STRUCT_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__autocar_msgs__msg__VehicleStates __attribute__((deprecated))
#else
# define DEPRECATED__autocar_msgs__msg__VehicleStates __declspec(deprecated)
#endif

namespace autocar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleStates_
{
  using Type = VehicleStates_<ContainerAllocator>;

  explicit VehicleStates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->fr_angle = 0.0;
      this->fl_angle = 0.0;
      this->br_angle = 0.0;
      this->bl_angle = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
    }
  }

  explicit VehicleStates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->fr_angle = 0.0;
      this->fl_angle = 0.0;
      this->br_angle = 0.0;
      this->bl_angle = 0.0;
      this->vx = 0.0;
      this->vy = 0.0;
    }
  }

  // field types and members
  using _time_type =
    double;
  _time_type time;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _theta_type =
    double;
  _theta_type theta;
  using _fr_angle_type =
    double;
  _fr_angle_type fr_angle;
  using _fl_angle_type =
    double;
  _fl_angle_type fl_angle;
  using _br_angle_type =
    double;
  _br_angle_type br_angle;
  using _bl_angle_type =
    double;
  _bl_angle_type bl_angle;
  using _vx_type =
    double;
  _vx_type vx;
  using _vy_type =
    double;
  _vy_type vy;
  using _wheel_speeds_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _wheel_speeds_type wheel_speeds;

  // setters for named parameter idiom
  Type & set__time(
    const double & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__fr_angle(
    const double & _arg)
  {
    this->fr_angle = _arg;
    return *this;
  }
  Type & set__fl_angle(
    const double & _arg)
  {
    this->fl_angle = _arg;
    return *this;
  }
  Type & set__br_angle(
    const double & _arg)
  {
    this->br_angle = _arg;
    return *this;
  }
  Type & set__bl_angle(
    const double & _arg)
  {
    this->bl_angle = _arg;
    return *this;
  }
  Type & set__vx(
    const double & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const double & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__wheel_speeds(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->wheel_speeds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    autocar_msgs::msg::VehicleStates_<ContainerAllocator> *;
  using ConstRawPtr =
    const autocar_msgs::msg::VehicleStates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      autocar_msgs::msg::VehicleStates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      autocar_msgs::msg::VehicleStates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__autocar_msgs__msg__VehicleStates
    std::shared_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__autocar_msgs__msg__VehicleStates
    std::shared_ptr<autocar_msgs::msg::VehicleStates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleStates_ & other) const
  {
    if (this->time != other.time) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->fr_angle != other.fr_angle) {
      return false;
    }
    if (this->fl_angle != other.fl_angle) {
      return false;
    }
    if (this->br_angle != other.br_angle) {
      return false;
    }
    if (this->bl_angle != other.bl_angle) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->wheel_speeds != other.wheel_speeds) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleStates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleStates_

// alias to use template instance with default allocator
using VehicleStates =
  autocar_msgs::msg::VehicleStates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__STRUCT_HPP_
