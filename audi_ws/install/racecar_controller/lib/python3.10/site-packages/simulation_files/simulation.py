from simulation_files.path import *
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import matlab.engine 
from simulation_files.constants import *
from simulation_files.math_stuff import *
import scipy.interpolate as spi
from simulation_files.lateral import *
import matplotlib.patches as patches
from simulation_files.longtitudinal import * 
import math
from matplotlib.transforms import Affine2D
import rclpy
from rclpy.node import Node
from autocar_msgs.msg import VehicleStates
from geometry_msgs.msg import Twist, Vector3
from ament_index_python import get_package_share_directory
import os

# class Vehicle:
#     def __init__(self, x=0, y=0, theta=0, v=0):
#         self.x = x
#         self.y = y
#         self.theta = theta
#         # vehicle front tire slip angle
#         self.alpha_f = 0
        
#         # vehicle rear tire slip 
#         self.alpha_r = 0
        
        
        
        
#         self.v = v
#         self.s = 1e-5

#     def update(self, throttle, steering):
      
        
#         # Update position
#         self.x = float(self.x + self.v * np.cos(float(self.theta)) * dt)
#         self.y = float(self.y + self.v * np.sin(float(self.theta)) * dt)

#         # update s
#         self.s = float (self.s + self.v * dt)
        
#         # Update orientation
#         self.theta += (self.v / L) * np.tan(steering) * dt

#         # Update velocity
#         self.v = self.v + throttle/M * dt

class Vehicle (Node): 
    def __init__(self):
        super().__init__('vehicle')
        self.vehicle_state_listener = self.create_subscription(VehicleStates, '/vehicle_states', self.vehicle_state_callback, 10)
        self.vehicle_message = self.create_publisher(Twist, '/autocar/cmd_vel', 10)
        self.time = 0.0
        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0
        self.fr_angle = 0.0
        self.fl_angle = 0.0
        self.br_angle = 0.0
        self.bl_angle = 0.0
        
        self.s =  1e-6 ## total distance tranversed
        self.v = 0.0 ## vehicle speed 
        
        self.pre_time = 0.0
        self.prev_x = 0.0 
        self.prev_y = 0.0
        self.prev_theta = 0.0
        self.prev_fr_angle = 0.0
        self.prev_fl_angle = 0.0
        self.prev_br_angle = 0.0
        self.prev_bl_angle = 0.0
        self.MCP_track, self.vel_prof, self.U_x, self.A_x, self.x_cont, self.y_cont, self.roc = get_track()
        
        
    
    
    def vehicle_state_callback(self,msg):
        self.prev_time = self.time
        self.prev_x = self.x
        self.prev_y = self.y
        self.prev_theta = self.theta
        self.prev_fr_angle = self.fr_angle
        self.prev_fl_angle = self.fl_angle
        self.prev_br_angle = self.br_angle
        self.prev_bl_angle = self.bl_angle
        
        self.time = msg.time
        self.x = msg.x
        self.y = msg.y
        self.theta = msg.theta
        self.fr_angle = msg.fr_angle
        self.fl_angle = msg.fl_angle
        self.br_angle = msg.br_angle
        self.bl_angle = msg.bl_angle
        
        self.s += np.sqrt((self.x - self.prev_x)**2 + (self.y - self.prev_y)**2)
        self.v = np.sqrt((self.x - self.prev_x)**2 + (self.y - self.prev_y)**2)/(self.time - self.prev_time)
        self.update()
    
    def update(self):
        print ("speed is", self.v)
    
        
        self.get_logger().info('Updating vehicle velocity.')
        steering_input = lateral_controller(self.roc (self.s), 
        self.U_x(self.s), self, (self.x_cont(self.s), self.y_cont(self.s)), 
        self.x_cont, self.y_cont, (self.s-100,self.s+100), slip_front = 0, slip_rear = 0)
        angular_vel = 0.0 #
        throttle_input = longituinal_controller (M,self.A_x(self.s), angular_vel, self.v)

        
        cmd_vel_msg = Twist()
        # print ("length of x is", len (self.v + throttle_input/M *(self.time - self.prev_time)))
        self.v = self.v + throttle_input/M *(self.time - self.prev_time)
        cmd_vel_msg.linear = Vector3(x=self.v, y=0.0, z=0.0)
        
        cmd_vel_msg.angular = Vector3(x=0.0, y=0.0, z=steering_input)
        self.vehicle_message.publish(cmd_vel_msg)


def get_track():
    # run path.py to generate my_track.csv
    package_share_dir = get_package_share_directory('racecar_controller')
    
    csv_path = os.path.join(package_share_dir, 'track_info', 'MCP_track.csv')
    MCP_track = np.loadtxt (csv_path, delimiter = ',')
    
    csv_path = os.path.join(package_share_dir, 'track_info', 'vel_prof.csv')
    vel_prof = np.loadtxt (csv_path, delimiter = ',')
    
    csv_path = os.path.join(package_share_dir, 'track_info', 's.csv')
    s = np.loadtxt (csv_path, delimiter = ',')
    
    # s = [item[0] for item in s]
    
    # spline velocity profile
    U_x = spline_velocity(s, vel_prof)
    A_x = U_x.derivative(1)
    
    # plt.plot (s, A_x(s))
    # plt.show()

    # spline track  
    x_cont = spi.UnivariateSpline (s, MCP_track[:,0], s = 0)
    y_cont = spi.UnivariateSpline (s, MCP_track[:,1], s = 0)       

    # define function of radius of curvature
    roc = curvature_function(s, MCP_track[:,0], MCP_track[:,1])
    
    return MCP_track, vel_prof, U_x, A_x, x_cont, y_cont, roc




def main(args=None):
    rclpy.init(args=args)
    node = Vehicle()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
# distance traversed is s








# # initialize vehicle and simulaiton
# vehicle = Vehicle(x = MCP_track[0,0], y = MCP_track[0,1], theta = math.atan2 (MCP_track[1,1]-MCP_track[0,1], MCP_track[1,0] - MCP_track[0,0]), v = 0)
# x_history = []
# y_history =  []
# e_history = []
# steering_history = []
# lk_history = []






# iter = 0 
# while vehicle.s < s[-1]:
#     vehicle.alpha_f = (AXLE_NORMAL_LOAD_FRONT/g * U_x(vehicle.s)**2/roc(vehicle.s))/LATERAL_AXLE_STIFFNESS_FRONT
#     vehicle.alpha_r = (AXLE_NORMAL_LOAD_REAR/g * U_x(vehicle.s)**2/roc(vehicle.s))/LATERAL_AXLE_STIFFNESS_REAR
#     steering_input,e  = lateral_controller(roc (vehicle.s), U_x(vehicle.s), vehicle, (x_cont(vehicle.s), y_cont(vehicle.s)), x_cont, y_cont, (vehicle.s-100,vehicle.s+100), slip_front = vehicle.alpha_f, slip_rear = vehicle.alpha_f)
# #      print ("steering" , steering_input)
#     throttle_input = longtituinal_controller (M,A_x(vehicle.s)) #longtituinal_controller (U_x(vehicle.s), vehicle.s, roc(vehicle.s))
    
#     vehicle.update (throttle_input, steering_input)
#     x_history.append(vehicle.x)
#     y_history.append(vehicle.y)
#     e_history.append(e)
#     steering_history.append(float(steering_input))





# e_history = np.array (e_history)
# x_closest = e_history [:,0]
# y_closest = e_history [:,1]

# x_history =  np.array (x_history)
# y_history = np.array (y_history) + 3


# # print ("x", x_history)
# # print ("y", y_history)

# def visualization ():
#         # Plot the velocity profile
#         # plt.figure (1) 
#         # plt.scatter (MCP_track[:,0], MCP_track[:,1], c = vel_prof, cmap = cm.jet, s = 2)
#         # plt.axis('equal')
#         # colBar = plt.colorbar()
#         # colBar.set_label("Velocity [m/s]")

        
        
#         # plt.figure (2)
#         # plt.plot (s, 1/roc(s)*100)
#         # plt.plot (s, U_x(s))   
#         # e_history = np.array (e_history)
#         # plt.plot (np.arange(len(e_history)), e_history)

#         # plt.plot (e_history, label = 'e') 
#         # plt.axhline (y = 0, color = 'r', linestyle = '--')
#         # plt.plot (steering_history*1000, label = 'steering')
#         # plt.legend() 

#         # Visualize the race tracky_traj
#         fig, ax = visualize_race_track(
#                 center_line, 
#                 inner_boundary, 
#                 outer_boundary, 
#                 waypoints,
#                 clothoid_path = (x_history, y_history),
#                 title="Race Track with Simulation Vehicle Trajectory"
#         )

#         rect = patches.Rectangle ((886.5,324),4,10, facecolor='red', label = 'Vehicle')
#         t = Affine2D().rotate_deg_around(886,324, 24) + ax.transData
#         rect.set_transform(t)
#         ax.add_patch(rect)
#         # Add an arrow pointing to the box
#         arrow_x, arrow_y = 886.5 + 4 / 2, 324 + 10 / 2  # Pointing to center
#         ax.annotate("vehicle", xy=(arrow_x, arrow_y), xytext=(arrow_x + 2, arrow_y + 1),
#                     arrowprops=dict(facecolor='red', arrowstyle='->'), fontsize=12, color='red')

#         # ax.plot (x_closest, y_closest, 'k--', label = 'closest point')
#         # ax.legend()
        



#         # //ax.plot (x,y)

#         plt.show()


# visualization() 