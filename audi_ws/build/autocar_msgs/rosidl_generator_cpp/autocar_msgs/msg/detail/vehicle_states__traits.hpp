// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autocar_msgs:msg/VehicleStates.idl
// generated code does not contain a copyright notice

#ifndef AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__TRAITS_HPP_
#define AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autocar_msgs/msg/detail/vehicle_states__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace autocar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleStates & msg,
  std::ostream & out)
{
  out << "{";
  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

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

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: fr_angle
  {
    out << "fr_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.fr_angle, out);
    out << ", ";
  }

  // member: fl_angle
  {
    out << "fl_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.fl_angle, out);
    out << ", ";
  }

  // member: br_angle
  {
    out << "br_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.br_angle, out);
    out << ", ";
  }

  // member: bl_angle
  {
    out << "bl_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.bl_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

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

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: fr_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fr_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.fr_angle, out);
    out << "\n";
  }

  // member: fl_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fl_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.fl_angle, out);
    out << "\n";
  }

  // member: br_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "br_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.br_angle, out);
    out << "\n";
  }

  // member: bl_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bl_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.bl_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleStates & msg, bool use_flow_style = false)
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
  const autocar_msgs::msg::VehicleStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  autocar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autocar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const autocar_msgs::msg::VehicleStates & msg)
{
  return autocar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<autocar_msgs::msg::VehicleStates>()
{
  return "autocar_msgs::msg::VehicleStates";
}

template<>
inline const char * name<autocar_msgs::msg::VehicleStates>()
{
  return "autocar_msgs/msg/VehicleStates";
}

template<>
struct has_fixed_size<autocar_msgs::msg::VehicleStates>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<autocar_msgs::msg::VehicleStates>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<autocar_msgs::msg::VehicleStates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTOCAR_MSGS__MSG__DETAIL__VEHICLE_STATES__TRAITS_HPP_
