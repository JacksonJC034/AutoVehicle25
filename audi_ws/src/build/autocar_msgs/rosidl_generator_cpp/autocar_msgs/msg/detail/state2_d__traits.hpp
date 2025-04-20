// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autocar_msgs:msg/State2D.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__TRAITS_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autocar_msgs/msg/detail/state2_d__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__traits.hpp"
// Member 'twist'
#include "autocar_msgs/msg/detail/twist2_d__traits.hpp"

namespace autocar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const State2D & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: twist
  {
    out << "twist: ";
    to_flow_style_yaml(msg.twist, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist:\n";
    to_block_style_yaml(msg.twist, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State2D & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace autocar_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autocar_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autocar_msgs::msg::State2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  autocar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autocar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const autocar_msgs::msg::State2D & msg)
{
  return autocar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<autocar_msgs::msg::State2D>()
{
  return "autocar_msgs::msg::State2D";
}

template<>
inline const char * name<autocar_msgs::msg::State2D>()
{
  return "autocar_msgs/msg/State2D";
}

template<>
struct has_fixed_size<autocar_msgs::msg::State2D>
  : std::integral_constant<bool, has_fixed_size<autocar_msgs::msg::Twist2D>::value && has_fixed_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct has_bounded_size<autocar_msgs::msg::State2D>
  : std::integral_constant<bool, has_bounded_size<autocar_msgs::msg::Twist2D>::value && has_bounded_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct is_message<autocar_msgs::msg::State2D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTOCAR_MSGS__MSG__DETAIL__STATE2_D__TRAITS_HPP_
