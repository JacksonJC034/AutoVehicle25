// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autocar_msgs:msg/TireSlips.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__BUILDER_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autocar_msgs/msg/detail/tire_slips__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autocar_msgs
{

namespace msg
{

namespace builder
{

class Init_TireSlips_rear_k
{
public:
  explicit Init_TireSlips_rear_k(::autocar_msgs::msg::TireSlips & msg)
  : msg_(msg)
  {}
  ::autocar_msgs::msg::TireSlips rear_k(::autocar_msgs::msg::TireSlips::_rear_k_type arg)
  {
    msg_.rear_k = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autocar_msgs::msg::TireSlips msg_;
};

class Init_TireSlips_front_k
{
public:
  explicit Init_TireSlips_front_k(::autocar_msgs::msg::TireSlips & msg)
  : msg_(msg)
  {}
  Init_TireSlips_rear_k front_k(::autocar_msgs::msg::TireSlips::_front_k_type arg)
  {
    msg_.front_k = std::move(arg);
    return Init_TireSlips_rear_k(msg_);
  }

private:
  ::autocar_msgs::msg::TireSlips msg_;
};

class Init_TireSlips_rear_alpha
{
public:
  explicit Init_TireSlips_rear_alpha(::autocar_msgs::msg::TireSlips & msg)
  : msg_(msg)
  {}
  Init_TireSlips_front_k rear_alpha(::autocar_msgs::msg::TireSlips::_rear_alpha_type arg)
  {
    msg_.rear_alpha = std::move(arg);
    return Init_TireSlips_front_k(msg_);
  }

private:
  ::autocar_msgs::msg::TireSlips msg_;
};

class Init_TireSlips_front_alpha
{
public:
  explicit Init_TireSlips_front_alpha(::autocar_msgs::msg::TireSlips & msg)
  : msg_(msg)
  {}
  Init_TireSlips_rear_alpha front_alpha(::autocar_msgs::msg::TireSlips::_front_alpha_type arg)
  {
    msg_.front_alpha = std::move(arg);
    return Init_TireSlips_rear_alpha(msg_);
  }

private:
  ::autocar_msgs::msg::TireSlips msg_;
};

class Init_TireSlips_header
{
public:
  Init_TireSlips_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TireSlips_front_alpha header(::autocar_msgs::msg::TireSlips::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TireSlips_front_alpha(msg_);
  }

private:
  ::autocar_msgs::msg::TireSlips msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autocar_msgs::msg::TireSlips>()
{
  return autocar_msgs::msg::builder::Init_TireSlips_header();
}

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__BUILDER_HPP_
