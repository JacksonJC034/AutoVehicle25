import rclpy
from rclpy.node import Node
import tf2_ros
import tf2_geometry_msgs
from autocar_msgs.msg import VehicleStates
from transforms3d.euler import quat2euler  # Use tf_transformations for conversion

dt = 0.1
class VehicleStatePublisher(Node):
    def __init__(self):
        super().__init__('vehicle_state_publisher')
        self.get_logger().info('Vehicle State Publisher Node has been started.')
        self.create_timer(dt, self.publish_state)  
        self.tf_buffer = tf2_ros.Buffer() 
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        self.state_publisher = self.create_publisher(VehicleStates, '/vehicle_states',10)
        

    def publish_state(self):
        # Placeholder for publishing vehicle state
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
        quaternion = (quat.x, quat.y, quat.z, quat.w)
        # Convert quaternion to Euler angles
        roll, pitch, yaw = quat2euler(quaternion)
        
 
        
        print (roll,pitch,yaw)

def main(args=None):
    rclpy.init(args=args)
    node = VehicleStatePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
