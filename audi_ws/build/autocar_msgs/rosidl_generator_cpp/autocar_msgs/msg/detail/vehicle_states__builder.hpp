// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autocar_msgs:msg/VehicleStates.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__BUILDER_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autocar_msgs/msg/detail/vehicle_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autocar_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleStates_bl_angle
{
public:
  explicit Init_VehicleStates_bl_angle(::autocar_msgs::msg::VehicleStates & msg)
  : msg_(msg)
  {}
  ::autocar_msgs::msg::VehicleStates bl_angle(::autocar_msgs::msg::VehicleStates::_bl_angle_type arg)
  {
    msg_.bl_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

class Init_VehicleStates_br_angle
{
public:
  explicit Init_VehicleStates_br_angle(::autocar_msgs::msg::VehicleStates & msg)
  : msg_(msg)
  {}
  Init_VehicleStates_bl_angle br_angle(::autocar_msgs::msg::VehicleStates::_br_angle_type arg)
  {
    msg_.br_angle = std::move(arg);
    return Init_VehicleStates_bl_angle(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

class Init_VehicleStates_fl_angle
{
public:
  explicit Init_VehicleStates_fl_angle(::autocar_msgs::msg::VehicleStates & msg)
  : msg_(msg)
  {}
  Init_VehicleStates_br_angle fl_angle(::autocar_msgs::msg::VehicleStates::_fl_angle_type arg)
  {
    msg_.fl_angle = std::move(arg);
    return Init_VehicleStates_br_angle(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

class Init_VehicleStates_fr_angle
{
public:
  explicit Init_VehicleStates_fr_angle(::autocar_msgs::msg::VehicleStates & msg)
  : msg_(msg)
  {}
  Init_VehicleStates_fl_angle fr_angle(::autocar_msgs::msg::VehicleStates::_fr_angle_type arg)
  {
    msg_.fr_angle = std::move(arg);
    return Init_VehicleStates_fl_angle(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

class Init_VehicleStates_theta
{
public:
  explicit Init_VehicleStates_theta(::autocar_msgs::msg::VehicleStates & msg)
  : msg_(msg)
  {}
  Init_VehicleStates_fr_angle theta(::autocar_msgs::msg::VehicleStates::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_VehicleStates_fr_angle(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

class Init_VehicleStates_y
{
public:
  explicit Init_VehicleStates_y(::autocar_msgs::msg::VehicleStates & msg)
  : msg_(msg)
  {}
  Init_VehicleStates_theta y(::autocar_msgs::msg::VehicleStates::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_VehicleStates_theta(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

class Init_VehicleStates_x
{
public:
  explicit Init_VehicleStates_x(::autocar_msgs::msg::VehicleStates & msg)
  : msg_(msg)
  {}
  Init_VehicleStates_y x(::autocar_msgs::msg::VehicleStates::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_VehicleStates_y(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

class Init_VehicleStates_time
{
public:
  Init_VehicleStates_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleStates_x time(::autocar_msgs::msg::VehicleStates::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_VehicleStates_x(msg_);
  }

private:
  ::autocar_msgs::msg::VehicleStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autocar_msgs::msg::VehicleStates>()
{
  return autocar_msgs::msg::builder::Init_VehicleStates_time();
}

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__BUILDER_HPP_
