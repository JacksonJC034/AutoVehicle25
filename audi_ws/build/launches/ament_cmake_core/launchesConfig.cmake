# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_launches_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED launches_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(launches_FOUND FALSE)
  elseif(NOT launches_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(launches_FOUND FALSE)
  endif()
  return()
endif()
set(_launches_CONFIG_INCLUDED TRUE)

# output package information
if(NOT launches_FIND_QUIETLY)
  message(STATUS "Found launches: 0.0.0 (${launches_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'launches' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${launches_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(launches_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${launches_DIR}/${_extra}")
endforeach()
