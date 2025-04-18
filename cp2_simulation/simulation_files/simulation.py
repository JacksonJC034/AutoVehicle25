from path import *
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import matlab.engine 
from constants import *
from math_stuff import *
import scipy.interpolate as spi
from lateral import *
import matplotlib.patches as patches
from longtitudinal import * 
import math
from matplotlib.transforms import Affine2D

class Vehicle:
    def __init__(self, x=0, y=0, theta=0, v=0):
        self.x = x
        self.y = y
        self.theta = theta
        # vehicle front tire slip angle
        self.alpha_f = 0
        
        # vehicle rear tire slip 
        self.alpha_r = 0
        
        
        
        
        self.v = v
        self.s = 1e-5

    def update(self, throttle, steering):
      
        
        # Update position
        self.x = float(self.x + self.v * np.cos(float(self.theta)) * dt)
        self.y = float(self.y + self.v * np.sin(float(self.theta)) * dt)

        # update s
        self.s = float (self.s + self.v * dt)
        
        # Update orientation
        self.theta += (self.v / L) * np.tan(steering) * dt

        # Update velocity
        self.v = self.v + throttle/M * dt
        




# run path.py to generate my_track.csv
center_line, inner_boundary, outer_boundary, waypoints = generate_race_track(
        num_points=2000, 
        track_width= TRACK_WIDTH
    )



# start the matlab engine
eng = matlab.engine.start_matlab()
eng.eval("set(0, 'DefaultFigureVisible', 'off');", nargout=0) # supress figures 
eng.addpath('../MW208_Raceline_Optimization')



# file name of csv, name of track, call minimum curvature path generation function
file_name = "my_track.csv"
track_name = 'my_track'
(MCP_track, original_track) = eng.minCurvaturePathGenFunction (file_name, track_name, nargout = 2)
(vel_prof, len) = eng.velProfCalcFunction (MCP_track, track_name, M, FT_MAX, FB_MAX, FN_MAX, original_track, nargout = 2)



# convert to numpy array 
MCP_track = np.array(MCP_track)
vel_prof = np.array(vel_prof)
s = np.array (len)



# distance traversed is s
s = [item[0] for item in s]



# spline velocity profile
U_x = spline_velocity(s, vel_prof)
A_x = U_x.derivative(1)

# spline track  
x_cont = spi.UnivariateSpline (s, MCP_track[:,0], s = 0)
y_cont = spi.UnivariateSpline (s, MCP_track[:,1], s = 0)       

# define function of radius of curvature
roc = curvature_function(s, MCP_track[:,0], MCP_track[:,1])



# initialize vehicle and simulaiton
vehicle = Vehicle(x = MCP_track[0,0], y = MCP_track[0,1], theta = math.atan2 (MCP_track[1,1]-MCP_track[0,1], MCP_track[1,0] - MCP_track[0,0]), v = 0)
x_history = []
y_history =  []
e_history = []
steering_history = []
lk_history = []






iter = 0 
while vehicle.s < s[-1]:
    vehicle.alpha_f = (AXLE_NORMAL_LOAD_FRONT/g * U_x(vehicle.s)**2/roc(vehicle.s))/LATERAL_AXLE_STIFFNESS_FRONT
    vehicle.alpha_r = (AXLE_NORMAL_LOAD_REAR/g * U_x(vehicle.s)**2/roc(vehicle.s))/LATERAL_AXLE_STIFFNESS_REAR
    steering_input,e  = lateral_controller(roc (vehicle.s), U_x(vehicle.s), vehicle, (x_cont(vehicle.s), y_cont(vehicle.s)), x_cont, y_cont, (vehicle.s-100,vehicle.s+100), slip_front = vehicle.alpha_f, slip_rear = vehicle.alpha_f)
#      print ("steering" , steering_input)
    throttle_input = longtituinal_controller (M,A_x(vehicle.s)) #longtituinal_controller (U_x(vehicle.s), vehicle.s, roc(vehicle.s))
    
    vehicle.update (throttle_input, steering_input)
    x_history.append(vehicle.x)
    y_history.append(vehicle.y)
    e_history.append(e)
    steering_history.append(float(steering_input))





e_history = np.array (e_history)
x_closest = e_history [:,0]
y_closest = e_history [:,1]

x_history =  np.array (x_history)
y_history = np.array (y_history) + 3


# print ("x", x_history)
# print ("y", y_history)

def visualization ():
        # Plot the velocity profile
        # plt.figure (1) 
        # plt.scatter (MCP_track[:,0], MCP_track[:,1], c = vel_prof, cmap = cm.jet, s = 2)
        # plt.axis('equal')
        # colBar = plt.colorbar()
        # colBar.set_label("Velocity [m/s]")

        
        
        # plt.figure (2)
        # plt.plot (s, 1/roc(s)*100)
        # plt.plot (s, U_x(s))   
        # e_history = np.array (e_history)
        # plt.plot (np.arange(len(e_history)), e_history)

        # plt.plot (e_history, label = 'e') 
        # plt.axhline (y = 0, color = 'r', linestyle = '--')
        # plt.plot (steering_history*1000, label = 'steering')
        # plt.legend() 

        # Visualize the race tracky_traj
        fig, ax = visualize_race_track(
                center_line, 
                inner_boundary, 
                outer_boundary, 
                waypoints,
                clothoid_path = (x_history, y_history),
                title="Race Track with Simulation Vehicle Trajectory"
        )

        rect = patches.Rectangle ((886.5,324),4,10, facecolor='red', label = 'Vehicle')
        t = Affine2D().rotate_deg_around(886,324, 24) + ax.transData
        rect.set_transform(t)
        ax.add_patch(rect)
        # Add an arrow pointing to the box
        arrow_x, arrow_y = 886.5 + 4 / 2, 324 + 10 / 2  # Pointing to center
        ax.annotate("vehicle", xy=(arrow_x, arrow_y), xytext=(arrow_x + 2, arrow_y + 1),
                    arrowprops=dict(facecolor='red', arrowstyle='->'), fontsize=12, color='red')

        # ax.plot (x_closest, y_closest, 'k--', label = 'closest point')
        # ax.legend()
        



        # //ax.plot (x,y)

        plt.show()


visualization() 