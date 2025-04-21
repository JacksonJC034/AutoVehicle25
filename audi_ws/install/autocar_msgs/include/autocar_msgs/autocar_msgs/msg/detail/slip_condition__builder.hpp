// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autocar_msgs:msg/SlipCondition.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__BUILDER_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autocar_msgs/msg/detail/slip_condition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autocar_msgs
{

namespace msg
{

namespace builder
{

class Init_SlipCondition_rear_delta_k
{
public:
  explicit Init_SlipCondition_rear_delta_k(::autocar_msgs::msg::SlipCondition & msg)
  : msg_(msg)
  {}
  ::autocar_msgs::msg::SlipCondition rear_delta_k(::autocar_msgs::msg::SlipCondition::_rear_delta_k_type arg)
  {
    msg_.rear_delta_k = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autocar_msgs::msg::SlipCondition msg_;
};

class Init_SlipCondition_rear_delta_alpha
{
public:
  explicit Init_SlipCondition_rear_delta_alpha(::autocar_msgs::msg::SlipCondition & msg)
  : msg_(msg)
  {}
  Init_SlipCondition_rear_delta_k rear_delta_alpha(::autocar_msgs::msg::SlipCondition::_rear_delta_alpha_type arg)
  {
    msg_.rear_delta_alpha = std::move(arg);
    return Init_SlipCondition_rear_delta_k(msg_);
  }

private:
  ::autocar_msgs::msg::SlipCondition msg_;
};

class Init_SlipCondition_front_delta_k
{
public:
  explicit Init_SlipCondition_front_delta_k(::autocar_msgs::msg::SlipCondition & msg)
  : msg_(msg)
  {}
  Init_SlipCondition_rear_delta_alpha front_delta_k(::autocar_msgs::msg::SlipCondition::_front_delta_k_type arg)
  {
    msg_.front_delta_k = std::move(arg);
    return Init_SlipCondition_rear_delta_alpha(msg_);
  }

private:
  ::autocar_msgs::msg::SlipCondition msg_;
};

class Init_SlipCondition_front_delta_alpha
{
public:
  explicit Init_SlipCondition_front_delta_alpha(::autocar_msgs::msg::SlipCondition & msg)
  : msg_(msg)
  {}
  Init_SlipCondition_front_delta_k front_delta_alpha(::autocar_msgs::msg::SlipCondition::_front_delta_alpha_type arg)
  {
    msg_.front_delta_alpha = std::move(arg);
    return Init_SlipCondition_front_delta_k(msg_);
  }

private:
  ::autocar_msgs::msg::SlipCondition msg_;
};

class Init_SlipCondition_rear_saturated
{
public:
  explicit Init_SlipCondition_rear_saturated(::autocar_msgs::msg::SlipCondition & msg)
  : msg_(msg)
  {}
  Init_SlipCondition_front_delta_alpha rear_saturated(::autocar_msgs::msg::SlipCondition::_rear_saturated_type arg)
  {
    msg_.rear_saturated = std::move(arg);
    return Init_SlipCondition_front_delta_alpha(msg_);
  }

private:
  ::autocar_msgs::msg::SlipCondition msg_;
};

class Init_SlipCondition_front_saturated
{
public:
  explicit Init_SlipCondition_front_saturated(::autocar_msgs::msg::SlipCondition & msg)
  : msg_(msg)
  {}
  Init_SlipCondition_rear_saturated front_saturated(::autocar_msgs::msg::SlipCondition::_front_saturated_type arg)
  {
    msg_.front_saturated = std::move(arg);
    return Init_SlipCondition_rear_saturated(msg_);
  }

private:
  ::autocar_msgs::msg::SlipCondition msg_;
};

class Init_SlipCondition_header
{
public:
  Init_SlipCondition_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SlipCondition_front_saturated header(::autocar_msgs::msg::SlipCondition::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SlipCondition_front_saturated(msg_);
  }

private:
  ::autocar_msgs::msg::SlipCondition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autocar_msgs::msg::SlipCondition>()
{
  return autocar_msgs::msg::builder::Init_SlipCondition_header();
}

}  // namespace autocar_msgs

#endif  // AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__BUILDER_HPP_
