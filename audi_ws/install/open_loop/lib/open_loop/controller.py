#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import math
from geometry_msgs.msg import Twist
from gazebo_msgs.msg import LinkStates

class BicycleController(Node):
    def __init__(self):
        super().__init__('bicycle_controller')
        # Parameters matching your Python simulation
        self.declare_parameters(
            namespace='',
            parameters=[
                ('m', 1500),
                ('Iz', 2500),
                ('lf', 1.2),
                ('lr', 1.5),
                ('mu', 0.9)
            ])
        
        # State variables [x, y, ψ, vx, vy, ω]
        self.states = [0.0, 0.0, 0.0, 20.0, 0.0, 0.0]
        
        # Create publisher for steering and propulsion
        self.cmd_pub = self.create_publisher(Twist, '/model/hatchback/cmd_vel', 10)
        
        # Timer for update loop (100Hz)
        self.timer = self.create_timer(0.01, self.update)

    def bicycle_model(self, delta, Fx):
        # Your original Python model adapted for Gazebo
        m = self.get_parameter('m').value
        Iz = self.get_parameter('Iz').value
        lf = self.get_parameter('lf').value
        lr = self.get_parameter('lr').value
        mu = self.get_parameter('mu').value
        
        x, y, psi, vx, vy, omega = self.states
        
        # Tire forces (same as your original code)
        alpha_f = delta - math.atan((vy + lf * omega) / (vx + 1e-6))
        alpha_r = -math.atan((vy - lr * omega) / (vx + 1e-6))
        
        Fz_f = (m * 9.81 * lr) / (lf + lr)
        Fz_r = (m * 9.81 * lf) / (lf + lr)
        
        Fy_f = mu * Fz_f * math.sin(1.5 * math.atan(-alpha_f / 0.1))
        Fy_r = mu * Fz_r * math.sin(1.5 * math.atan(-alpha_r / 0.1))
        
        # Dynamics calculations
        ax = (Fx - Fy_f * math.sin(delta)) / m + vy * omega
        ay = (Fy_f * math.cos(delta) + Fy_r) / m - vx * omega
        domega = (lf * Fy_f * math.cos(delta) - lr * Fy_r) / Iz
        
        # Update states using Euler integration
        dt = 0.01
        self.states[3] += ax * dt  # vx
        self.states[4] += ay * dt  # vy
        self.states[5] += domega * dt  # omega
        self.states[2] += omega * dt  # psi (yaw)
        
        # Update position (not directly used but good for logging)
        self.states[0] += (vx * math.cos(psi) - vy * math.sin(psi)) * dt
        self.states[1] += (vx * math.sin(psi) + vy * math.cos(psi)) * dt

    def update(self):
        # Open-loop control inputs
        if self.get_clock().now().nanoseconds > 2e9:  # After 2 seconds
            delta = math.radians(5)
        else:
            delta = 0.0
            
        Fx = 500.0
        
        # Update model
        self.bicycle_model(delta, Fx)
        
        # Publish commands to Gazebo
        cmd_msg = Twist()
        cmd_msg.linear.x = self.states[3]  # vx
        cmd_msg.angular.z = self.states[5]  # omega
        
        # For steering, we need to use a separate topic
        self.cmd_pub.publish(cmd_msg)
        
        # Optional: Publish steering angle to joint
        # (Requires joint command publisher)

def main():
    rclpy.init()
    controller = BicycleController()
    rclpy.spin(controller)
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()