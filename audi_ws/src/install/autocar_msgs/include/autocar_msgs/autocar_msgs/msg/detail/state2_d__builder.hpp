// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autocar_msgs:msg/State2D.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__BUILDER_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autocar_msgs/msg/detail/state2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autocar_msgs
{

namespace msg
{

namespace builder
{

class Init_State2D_twist
{
public:
  explicit Init_State2D_twist(::autocar_msgs::msg::State2D & msg)
  : msg_(msg)
  {}
  ::autocar_msgs::msg::State2D twist(::autocar_msgs::msg::State2D::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autocar_msgs::msg::State2D msg_;
};

class Init_State2D_pose
{
public:
  Init_State2D_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State2D_twist pose(::autocar_msgs::msg::State2D::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_State2D_twist(msg_);
  }

private:
  ::autocar_msgs::msg::State2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autocar_msgs::msg::State2D>()
{
  return autocar_msgs::msg::builder::Init_State2D_pose();
}

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__BUILDER_HPP_
