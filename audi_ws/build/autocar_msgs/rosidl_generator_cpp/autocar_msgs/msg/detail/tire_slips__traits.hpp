// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autocar_msgs:msg/TireSlips.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__TRAITS_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autocar_msgs/msg/detail/tire_slips__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace autocar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TireSlips & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: front_alpha
  {
    out << "front_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.front_alpha, out);
    out << ", ";
  }

  // member: rear_alpha
  {
    out << "rear_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_alpha, out);
    out << ", ";
  }

  // member: front_k
  {
    out << "front_k: ";
    rosidl_generator_traits::value_to_yaml(msg.front_k, out);
    out << ", ";
  }

  // member: rear_k
  {
    out << "rear_k: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_k, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TireSlips & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: front_alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.front_alpha, out);
    out << "\n";
  }

  // member: rear_alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_alpha, out);
    out << "\n";
  }

  // member: front_k
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_k: ";
    rosidl_generator_traits::value_to_yaml(msg.front_k, out);
    out << "\n";
  }

  // member: rear_k
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_k: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_k, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TireSlips & msg, bool use_flow_style = false)
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
  const autocar_msgs::msg::TireSlips & msg,
  std::ostream & out, size_t indentation = 0)
{
  autocar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autocar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const autocar_msgs::msg::TireSlips & msg)
{
  return autocar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<autocar_msgs::msg::TireSlips>()
{
  return "autocar_msgs::msg::TireSlips";
}

template<>
inline const char * name<autocar_msgs::msg::TireSlips>()
{
  return "autocar_msgs/msg/TireSlips";
}

template<>
struct has_fixed_size<autocar_msgs::msg::TireSlips>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<autocar_msgs::msg::TireSlips>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<autocar_msgs::msg::TireSlips>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTOCAR_MSGS__MSG__DETAIL__TIRE_SLIPS__TRAITS_HPP_
