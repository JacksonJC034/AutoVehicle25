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
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
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
