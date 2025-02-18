from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        # Launch Ignition Gazebo
        ExecuteProcess(
            cmd=['ign', 'gazebo', '-v', '4', '-r', '/home/fishros/AVAudi/audi_ws/src/open_loop/worlds/world.sdf'],
            output='screen'
        ),
        
        # ROS-Ign bridge
        Node(
            package='ros_ign_bridge',
            executable='parameter_bridge',
            arguments=[
            '/model/bicycle_car/cmd_vel@geometry_msgs/msg/Twist[ignition.msgs.Twist]'
        ],
            output='screen'
        ),
        
        # Controller node
        Node(
            package='open_loop',
            executable='controller.py',
            output='screen'
        )
    ])