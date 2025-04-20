// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autocar_msgs:msg/Twist2D.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__TWIST2_D__BUILDER_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__TWIST2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autocar_msgs/msg/detail/twist2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autocar_msgs
{

namespace msg
{

namespace builder
{

class Init_Twist2D_w
{
public:
  explicit Init_Twist2D_w(::autocar_msgs::msg::Twist2D & msg)
  : msg_(msg)
  {}
  ::autocar_msgs::msg::Twist2D w(::autocar_msgs::msg::Twist2D::_w_type arg)
  {
    msg_.w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autocar_msgs::msg::Twist2D msg_;
};

class Init_Twist2D_y
{
public:
  explicit Init_Twist2D_y(::autocar_msgs::msg::Twist2D & msg)
  : msg_(msg)
  {}
  Init_Twist2D_w y(::autocar_msgs::msg::Twist2D::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Twist2D_w(msg_);
  }

private:
  ::autocar_msgs::msg::Twist2D msg_;
};

class Init_Twist2D_x
{
public:
  Init_Twist2D_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Twist2D_y x(::autocar_msgs::msg::Twist2D::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Twist2D_y(msg_);
  }

private:
  ::autocar_msgs::msg::Twist2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autocar_msgs::msg::Twist2D>()
{
  return autocar_msgs::msg::builder::Init_Twist2D_x();
}

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__TWIST2_D__BUILDER_HPP_
