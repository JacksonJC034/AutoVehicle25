import numpy as np
from simulation_files.constants import *
import math
from simulation_files.math_stuff import *

MAX_STEERING_ANGLE = np.pi/8

def feedforward (R,U_x,slip_front,slip_rear):
    u = U_x
    r = R
    K_ug = AXLE_NORMAL_LOAD_FRONT/LATERAL_AXLE_STIFFNESS_FRONT - AXLE_NORMAL_LOAD_REAR/LATERAL_AXLE_STIFFNESS_REAR # understeer gradient
    delta_feedforward = (L + K_ug * u**2/g)*1/r - slip_front + slip_rear
    return delta_feedforward



def lane_keep(vehicle, desired_location, x_spline, y_spline, s_lim):


    # find closest point on the desired trajectory
    closest_s = closest_point_on_spline (x_spline, y_spline, vehicle.x, vehicle.y, s_lim)
    desired_location = x_spline(closest_s), y_spline(closest_s)

    # x1,y1,x2,y2 are two point on the tangent line of the current trajectory 
    (x1,y1),(x2,y2) = tangent_line_at(x_spline, y_spline, closest_s)

    # find the angle of the tangent line 
    psi = math.atan2 (y2-y1, x2-x1)

    # euclidian distance between the vehicle and the desired location
    e = ((vehicle.x - desired_location[0])**2 + (vehicle.y - desired_location[1])**2)**(1/2)
    
    # delta_psi = angle of tangent line - angle of vehicle 
    delta_psi = vehicle.theta - psi

    delta_lane = - 2 * K_LC /LATERAL_AXLE_STIFFNESS_FRONT* ( e + X_LA *np.sin (delta_psi))

    return delta_lane , (x_spline (closest_s), y_spline (closest_s))

def yaw_damping():
    return 0

def lateral_controller(R, U_x, vehicle, desired_location,x_spline,y_spline, s_lim, slip_front = 0, slip_rear = 0):
    delta = K_ff * feedforward(R, U_x,slip_front,slip_rear)
    delta_lk,e = lane_keep(vehicle, desired_location,x_spline,y_spline , s_lim )
    delta = np.clip(delta + delta_lk, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE)
    return delta