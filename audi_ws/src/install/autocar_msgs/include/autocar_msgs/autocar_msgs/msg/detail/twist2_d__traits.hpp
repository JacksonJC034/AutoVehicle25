// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autocar_msgs:msg/Twist2D.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__TWIST2_D__TRAITS_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__TWIST2_D__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autocar_msgs/msg/detail/twist2_d__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace autocar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Twist2D & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: w
  {
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Twist2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Twist2D & msg, bool use_flow_style = false)
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
  const autocar_msgs::msg::Twist2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  autocar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autocar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const autocar_msgs::msg::Twist2D & msg)
{
  return autocar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<autocar_msgs::msg::Twist2D>()
{
  return "autocar_msgs::msg::Twist2D";
}

template<>
inline const char * name<autocar_msgs::msg::Twist2D>()
{
  return "autocar_msgs/msg/Twist2D";
}

template<>
struct has_fixed_size<autocar_msgs::msg::Twist2D>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<autocar_msgs::msg::Twist2D>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<autocar_msgs::msg::Twist2D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTOCAR_MSGS__MSG__DETAIL__TWIST2_D__TRAITS_HPP_
