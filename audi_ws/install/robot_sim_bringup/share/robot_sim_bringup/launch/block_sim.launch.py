#!/usr/bin/env python3
from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription
from launch_ros.actions import Node, LifecycleNode
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
import os
def generate_launch_description():
    world_path = os.path.join('/home','dliujm','um_files','rob_498_av','AutoVehicle25','audi_ws', 'src', 'robot_sim_bringup', 'worlds', 'vehicle_world.sdf')

   
    parameters = [{'use_sim_time': True}]


    ld = LaunchDescription()

    # Launch Gazebo with your world file.
    ign_gazebo = ExecuteProcess(
        cmd=['ign', 'gazebo', '-r', world_path],
        output='screen'
    )
    ld.add_action(ign_gazebo)

    clock_bridge = Node(
       package='ros_gz_bridge',
       executable='parameter_bridge',
       arguments=['/clock@rosgraph_msgs/msg/Clock@ignition.msgs.Clock'],
       output='screen'
    )
    ld.add_action(clock_bridge)

    # Bridge for the camera sensor.
    # Adjust message types if necessary.
    camera_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/camera@sensor_msgs/msg/Image@ignition.msgs.Image'],
        output='screen'
    )
    ld.add_action(camera_bridge)

    # Bridge for the lidar sensor.
    # For example, if the lidar publishes as LaserScan.
    lidar_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/lidar@sensor_msgs/msg/LaserScan@ignition.msgs.LaserScan'],
        # remappings=[('/lidar', '/livox')],
        output='screen',
        parameters=[{'use_sim_time': True}]
    )
    ld.add_action(lidar_bridge)
    
    lidar_points_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        # arguments=['/livox/lidar@sensor_msgs/msg/PointCloud2@ignition.msgs.PointCloudPacked'],
        arguments=['/lidar/points@sensor_msgs/msg/PointCloud2@ignition.msgs.PointCloudPacked'],
        # remappings=[('/lidar/points', '/livox/lidar')],
        output='screen',
        parameters=[{'use_sim_time': True}]
    )
    ld.add_action(lidar_points_bridge)

    # Bridge for cmd_vel: ROS (geometry_msgs/Twist) -> Ignition (msgs/Twist)
    cmd_vel_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        # arguments=['/model/lucy_robot/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist'],
        arguments=['/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist'],
        output='screen'
    )
    ld.add_action(cmd_vel_bridge)

    # Bridge for odometry: Ignition (msgs/Odometry) -> ROS (nav_msgs/Odometry)
    odom_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/model/lucy_robot/odometry@nav_msgs/msg/Odometry@ignition.msgs.Odometry'],
        output='screen',
        parameters=[{'use_sim_time': True}]
    )
    ld.add_action(odom_bridge)
    
    
    # # Robot state publisher from URDF
    # robot_state_publisher = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     name='robot_state_publisher',
    #     output='screen',
    #     parameters=[{'robot_description': open(urdf_path).read(), 'use_sim_time': True}]
    # )
    # ld.add_action(robot_state_publisher)

    # joint_state_publisher = Node(
    #     package='joint_state_publisher',
    #     executable='joint_state_publisher',
    #     name='joint_state_publisher',
    #     output='screen',
    #     parameters=[{'use_sim_time': True}]
    # )
    # ld.add_action(joint_state_publisher)
    
    # odom_tf_broadcaster_node = Node(
    #     package='odom_tf_broadcaster_pkg',
    #     executable='sim_gt_odom_tf_broadcaster',
    #     name='sim_gt_odom_tf_broadcaster',
    #     output='screen',
    #     parameters=[{'use_sim_time': True}]
    # )
    # ld.add_action(odom_tf_broadcaster_node)

    # pc_to_scan = Node(
    #     package='pointcloud_to_laserscan', executable='pointcloud_to_laserscan_node',
    #     remappings=[('cloud_in', 'lidar/points'),
    #                 ('scan', 'lidar')],
    #     parameters=[{
    #         'transform_tolerance': 0.01,
    #         'min_height': 0.0,
    #         'max_height': 5.0,
    #         # 'angle_min': -1.047,  # -M_PI/2
    #         'angle_min': -1.5708,  # -M_PI/2
    #         'angle_max': 1.5708,  # M_PI/2
    #         'angle_increment': 0.0087,  # M_PI/360.0
    #         'scan_time': 0.3333,
    #         'range_min': 0.0,
    #         'range_max': 20.0,
    #         'use_inf': True,
    #         'inf_epsilon': 1.0,
    #         'use_sim_time': True
    #     }],
    #     name='pointcloud_to_laserscan'
    # )
    # ld.add_action(pc_to_scan)

    # slam_toolbox_launch = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         PathJoinSubstitution([
    #             FindPackageShare('slam_toolbox'),
    #             'launch',
    #             'online_async_launch.py',
    #         ])
    #     ),
    #     launch_arguments={'slam_params_file': slam_params_path, 'use_sim_time': 'True'}.items()
    # )
    
    # ld.add_action(slam_toolbox_launch)

    # costmap_node = LifecycleNode(
    #     package = 'nav2_costmap_2d',
    #     executable = 'nav2_costmap_2d',
    #     name = 'costmap',
    #     namespace = 'costmap',
    #     output = 'screen',
    #     parameters = [costmap_params_path],
    # )
    # ld.add_action(costmap_node)

    # lifecycle_node = LifecycleNode(
    #     package = 'nav2_lifecycle_manager',
    #     executable = 'lifecycle_manager',
    #     name = 'lifecycle_manager',
    #     namespace = 'costmap',
    #     parameters = [
    #         {'autostart' : True},
    #         {'node_names' : ['costmap']},
    #     ],
    # )
    # ld.add_action(lifecycle_node)
    

    return ld
