// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autocar_msgs:msg/SlipCondition.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__TRAITS_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autocar_msgs/msg/detail/slip_condition__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace autocar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SlipCondition & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: front_saturated
  {
    out << "front_saturated: ";
    rosidl_generator_traits::value_to_yaml(msg.front_saturated, out);
    out << ", ";
  }

  // member: rear_saturated
  {
    out << "rear_saturated: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_saturated, out);
    out << ", ";
  }

  // member: front_delta_alpha
  {
    out << "front_delta_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.front_delta_alpha, out);
    out << ", ";
  }

  // member: front_delta_k
  {
    out << "front_delta_k: ";
    rosidl_generator_traits::value_to_yaml(msg.front_delta_k, out);
    out << ", ";
  }

  // member: rear_delta_alpha
  {
    out << "rear_delta_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_delta_alpha, out);
    out << ", ";
  }

  // member: rear_delta_k
  {
    out << "rear_delta_k: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_delta_k, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SlipCondition & msg,
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

  // member: front_saturated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_saturated: ";
    rosidl_generator_traits::value_to_yaml(msg.front_saturated, out);
    out << "\n";
  }

  // member: rear_saturated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_saturated: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_saturated, out);
    out << "\n";
  }

  // member: front_delta_alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_delta_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.front_delta_alpha, out);
    out << "\n";
  }

  // member: front_delta_k
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_delta_k: ";
    rosidl_generator_traits::value_to_yaml(msg.front_delta_k, out);
    out << "\n";
  }

  // member: rear_delta_alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_delta_alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_delta_alpha, out);
    out << "\n";
  }

  // member: rear_delta_k
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rear_delta_k: ";
    rosidl_generator_traits::value_to_yaml(msg.rear_delta_k, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SlipCondition & msg, bool use_flow_style = false)
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
  const autocar_msgs::msg::SlipCondition & msg,
  std::ostream & out, size_t indentation = 0)
{
  autocar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autocar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const autocar_msgs::msg::SlipCondition & msg)
{
  return autocar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<autocar_msgs::msg::SlipCondition>()
{
  return "autocar_msgs::msg::SlipCondition";
}

template<>
inline const char * name<autocar_msgs::msg::SlipCondition>()
{
  return "autocar_msgs/msg/SlipCondition";
}

template<>
struct has_fixed_size<autocar_msgs::msg::SlipCondition>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<autocar_msgs::msg::SlipCondition>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<autocar_msgs::msg::SlipCondition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTOCAR_MSGS__MSG__DETAIL__SLIP_CONDITION__TRAITS_HPP_
