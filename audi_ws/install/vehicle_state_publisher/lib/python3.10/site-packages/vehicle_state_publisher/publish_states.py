import rclpy
from rclpy.node import Node
import tf2_ros
import tf2_geometry_msgs
from autocar_msgs.msg import VehicleStates
from atuocar_msgs.msg import SlipCondition
from autocar_msgs.msg import TireSlips
import math
from transforms3d.euler import quat2euler  # Use tf_transformations for conversion
import transforms3d

import numpy as np


dt = 0.1
class VehicleStatePublisher(Node):
    def __init__(self):
        super().__init__('vehicle_state_publisher')
        self.get_logger().info('Vehicle State Publisher Node has been started.')
        self.create_timer(dt, self.publish_state)  
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        self.state_publisher = self.create_publisher(VehicleStates, '/vehicle_states',10)
        # New slip detection components
        self.slip_publisher = self.create_publisher(SlipCondition, '/slip_conditions', 10)
        self.tire_slip_publisher = self.create_publisher(TireSlips, '/tire_slips', 10)
        
        self.prev_fr = 0.0
        self.prev_fl = 0.0
        self.prev_br = 0.0
        self.prev_bl = 0.0
        self.prev_theta = 0.0
        
        self.acc_fr = 0.0
        self.acc_fl = 0.0
        self.acc_br = 0.0
        self.acc_bl = 0.0
        self.acc_theta = 0.0
        
        # State variables
        self.prev_pos = np.zeros(2)
        self.prev_time = self.get_clock().now()
        self.prev_angles = {
            'fr': 0.0, 'fl': 0.0, 
            'br': 0.0, 'bl': 0.0
        }
        
        self.declare_parameters(
            namespace='',
            parameters=[
                ('wheel_radius', 0.3),
                ('alpha_ref', 0.3),
                ('k_ref', 0.2)
            ]
        )
        
        
        self.create_timer(dt, self.publish_state)
            


    def track_continuous_angle(self,new_angle, prev_angle, accumulated_angle):
        # Calculate the difference
        diff = new_angle - prev_angle
        
        # Handle the wrap-around
        if diff > np.pi:
            diff -= 2 * np.pi
        elif diff < -np.pi:
            diff += 2 * np.pi
    
        # Update the accumulated angle
        accumulated_angle += diff
        prev_angle = new_angle
        
        return accumulated_angle, prev_angle
    
    
    def calculate_slip(self, vehicle_states):
        """Main slip calculation logic"""
        # Calculate vehicle velocity
        dt = (self.get_clock().now() - self.prev_time).nanoseconds * 1e-9
        dx = vehicle_states.x - self.prev_pos[0]
        dy = vehicle_states.y - self.prev_pos[1]
        vx = dx / dt
        vy = dy / dt
        
        # Calculate wheel angular velocities
        wheel_speeds = {}
        for wheel in ['fr', 'fl', 'br', 'bl']:
            current_angle = getattr(vehicle_states, f'{wheel}_angle')
            wheel_speeds[wheel] = (current_angle - self.prev_angles[wheel]) / dt
            self.prev_angles[wheel] = current_angle

        # Calculate slip ratios (longitudinal slip)
        k = {}
        for wheel in ['fr', 'fl', 'br', 'bl']:
            wheel_radius = self.get_parameter('wheel_radius').value
            longitudinal_speed = vx  # Simplified model
            wheel_speed = wheel_radius * wheel_speeds[wheel]
            k[wheel] = (wheel_speed - longitudinal_speed) / max(abs(longitudinal_speed), 1e-5)

        # Calculate slip angles (lateral slip)
        alpha = {}
        beta = np.arctan2(vy, vx)  # Vehicle sideslip angle
        for wheel in ['fr', 'fl']:
            delta = getattr(vehicle_states, f'{wheel}_angle')
            alpha[wheel] = delta - beta  # Simplified model for front wheels

        # Store values for next iteration
        self.prev_pos = np.array([vehicle_states.x, vehicle_states.y])
        self.prev_time = self.get_clock().now()

        return k, alpha
    
    
    def publish_state(self):
        # Placeholder for publishing vehicle state
        # current_time = rclpy.time.Time()
        current_time = self.get_clock().now()
        try:
            transform = self.tf_buffer.lookup_transform(
                'fr_1',
                'base_link',
                rclpy.time.Time()
            )
            # print ("transform: ", transform)
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return
        
        quat = transform.transform.rotation
        quaternion = (quat.w, quat.x, quat.y, quat.z)
        # Convert quaternion to Euler angles
        rotation_mat = transforms3d.quaternions.quat2mat(quaternion)
        fr_angle = transforms3d.euler.mat2euler(rotation_mat)[0]
        self.acc_fr, self.prev_fr= self.track_continuous_angle(fr_angle, self.prev_fr, self.acc_fr)
        
        
        
        try:
            transform = self.tf_buffer.lookup_transform(
                'fl_1',
                'base_link',
                rclpy.time.Time()
            )
            # print ("transform: ", transform)
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return
        
        quat = transform.transform.rotation
        quaternion = (quat.w, quat.x, quat.y, quat.z)
        # Convert quaternion to Euler angles
        rotation_mat = transforms3d.quaternions.quat2mat(quaternion)
        fl_angle = transforms3d.euler.mat2euler(rotation_mat)[0]
        self.acc_fl, self.prev_fl= self.track_continuous_angle(fl_angle, self.prev_fl, self.acc_fl)
 

        try:
            transform = self.tf_buffer.lookup_transform(
                'bl_1',
                'base_link',
                rclpy.time.Time()
            )
            # print ("transform: ", transform)
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return
        
        quat = transform.transform.rotation
        quaternion = (quat.w, quat.x, quat.y, quat.z)
        # Convert quaternion to Euler angles
        rotation_mat = transforms3d.quaternions.quat2mat(quaternion)
        bl_angle = transforms3d.euler.mat2euler(rotation_mat)[0]   
        self.acc_bl, self.prev_bl= self.track_continuous_angle(bl_angle, self.prev_bl, self.acc_bl)

        try:
            transform = self.tf_buffer.lookup_transform(
                'br_1',
                'base_link',
                rclpy.time.Time()
            )
            # print ("transform: ", transform)
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return
        
        quat = transform.transform.rotation
        quaternion = (quat.w, quat.x, quat.y, quat.z)
        # Convert quaternion to Euler angles
        rotation_mat = transforms3d.quaternions.quat2mat(quaternion)
        br_angle = transforms3d.euler.mat2euler(rotation_mat)[0]
        self.acc_br, self.prev_br= self.track_continuous_angle(br_angle, self.prev_br, self.acc_br)
   
        
        
        
        try:
            transform = self.tf_buffer.lookup_transform(
                'base_link',
                'odom',
                rclpy.time.Time()
            )
            # print ("transform: ", transform)
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return
        
        trans = transform.transform.translation
        quat = transform.transform.rotation
        quaternion = (quat.w, quat.x, quat.y, quat.z)
        rotation_mat = transforms3d.quaternions.quat2mat(quaternion)
        theta = transforms3d.euler.mat2euler(rotation_mat)[2]
        self.acc_theta, self.prev_theta = self.track_continuous_angle(theta, self.prev_theta, self.acc_theta)
        
        vehicle_states = VehicleStates()
        vehicle_states.time = current_time.nanoseconds * 1e-9
        vehicle_states.x = trans.x
        vehicle_states.y = trans.y
        vehicle_states.theta = self.acc_theta
        vehicle_states.fr_angle = self.acc_fr
        vehicle_states.fl_angle = self.acc_fl
        vehicle_states.bl_angle = self.acc_bl
        vehicle_states.br_angle = self.acc_br
        
        
        self.state_publisher.publish(vehicle_states)
        
        # Now publish the slip values:
        k, alpha = self.calculate_slip(vehicle_states)
        
        # Publish raw slip values
        tire_slips = TireSlips()
        tire_slips.header.stamp = self.get_clock().now().to_msg()
        tire_slips.front_alpha = (alpha['fr'] + alpha['fl']) / 2.0
        tire_slips.rear_alpha = 0.0  # Rear steering not implemented
        tire_slips.front_k = (k['fr'] + k['fl']) / 2.0
        tire_slips.rear_k = (k['br'] + k['bl']) / 2.0
        self.tire_slip_publisher.publish(tire_slips)

        # Publish processed slip conditions
        slip_condition = SlipCondition()
        # ... (populate using your slip detection logic)
        self.slip_publisher.publish(slip_condition)
        

def main(args=None):
    rclpy.init(args=args)
    node = VehicleStatePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()



if __name__ == '__main__':
    main()
