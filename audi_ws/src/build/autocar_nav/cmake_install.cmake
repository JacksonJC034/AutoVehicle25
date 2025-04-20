# Install script for directory: /home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/install/autocar_nav")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav/environment" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav/environment" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/autocar_nav-0.0.0-py3.10.egg-info" TYPE DIRECTORY FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_python/autocar_nav/autocar_nav.egg-info/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/local/lib/python3.10/dist-packages/autocar_nav" TYPE DIRECTORY FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/autocar_nav/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/usr/bin/python3" "-m" "compileall"
        "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/install/autocar_nav/local/lib/python3.10/dist-packages/autocar_nav"
      )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav" TYPE DIRECTORY FILES
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/config"
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/data"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/autocar_nav" TYPE PROGRAM FILES
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/nodes/globalplanner.py"
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/nodes/localisation.py"
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/nodes/localplanner.py"
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/nodes/clickplanner.py"
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/nodes/tracker.py"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/autocar_nav")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/autocar_nav")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav/environment" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav/environment" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_index/share/ament_index/resource_index/packages/autocar_nav")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav/cmake" TYPE FILE FILES
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_core/autocar_navConfig.cmake"
    "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/ament_cmake_core/autocar_navConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/autocar_nav" TYPE FILE FILES "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/AutoCarROS2/autocar_nav/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/build/autocar_nav/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
