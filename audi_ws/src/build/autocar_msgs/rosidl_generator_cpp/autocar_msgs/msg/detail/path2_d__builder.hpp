// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autocar_msgs:msg/Path2D.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__PATH2_D__BUILDER_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__PATH2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autocar_msgs/msg/detail/path2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autocar_msgs
{

namespace msg
{

namespace builder
{

class Init_Path2D_poses
{
public:
  Init_Path2D_poses()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autocar_msgs::msg::Path2D poses(::autocar_msgs::msg::Path2D::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autocar_msgs::msg::Path2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autocar_msgs::msg::Path2D>()
{
  return autocar_msgs::msg::builder::Init_Path2D_poses();
}

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__PATH2_D__BUILDER_HPP_
