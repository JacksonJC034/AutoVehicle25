import numpy as np
import scipy.interpolate as spi
from scipy.optimize import minimize_scalar

def curvature_function(s,x, y):
 
    
    # Fit cubic splines for x(t) and y(t)
    spl_x = spi.UnivariateSpline(s, x, s  = .5)
    spl_y = spi.UnivariateSpline(s, y, s = .5)

    # Define a function to compute radius of curvature at any t
    def radius_of_curvature(t_val):
        dx = spl_x.derivative(1)(t_val)  # First derivative dx/dt
        dy = spl_y.derivative(1)(t_val)  # First derivative dy/dt
        ddx = spl_x.derivative(2)(t_val) # Second derivative d²x/dt²
        ddy = spl_y.derivative(2)(t_val) # Second derivative d²y/dt²
        
        # Compute curvature radius
        numerator = (dx**2 + dy**2) ** (3/2)
        denominator = (dx * ddy - dy * ddx) 
        
        return np.where(denominator != 0, numerator / denominator, np.inf)  # Avoid division by zero
    
    return radius_of_curvature


def spline_velocity (s, vel_prof):
    # Fit cubic spline for velocity profile
    spl_vel = spi.CubicSpline(s, vel_prof)
    return spl_vel


def determine_position(x0, y0, x1, y1, x2, y2):
    # Calculate the cross product of vectors AB and AP
    cross_product = (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0)
    
    # Determine if the point is to the left, right, or on the line
    if cross_product > 0:
        return 1
    elif cross_product < 0:
        return -1
    else:
        return 0


def tangent_line_at(x_spline, y_spline, s, delta=0.1):
    """
    Computes two points defining the tangent line at the point corresponding to parameter s.
    
    Args:
    - x_spline: A scipy.interpolate.CubicSpline object for x(s).
    - y_spline: A scipy.interpolate.CubicSpline object for y(s).
    - s: The parameter value at which the tangent is computed.
    - delta: A small step in x to define the tangent line points.
    
    Returns:
    - (x1, y1), (x2, y2): Two points defining the tangent line.
    """
    # Compute the point (x, y) at s
    x0 = x_spline(s)
    y0 = y_spline(s)
    
    # Compute the derivatives dx/ds and dy/ds
    dx_ds = x_spline.derivative()(s)
    dy_ds = y_spline.derivative()(s)
    
    # Compute the tangent slope m = (dy/ds) / (dx/ds)
    if dx_ds == 0:
        # If dx_ds is zero, the tangent is a vertical line
        x1, x2 = x0, x0
        y1, y2 = y0 - delta, y0 + delta
    else:
        m = dy_ds / dx_ds
        
        # Define two points along the tangent line using a small x-step
        x1 = x0 - delta
        y1 = y0 + m * (x1 - x0)
        
        x2 = x0 + delta
        y2 = y0 + m * (x2 - x0)
    
    return (x1, y1), (x2, y2)


def closest_point_on_spline(x_spline, y_spline, a, b, s_lim ):
    # Parametrize the spline with t


    # Distance function to minimize
    def distance_function(t):
        x, y = x_spline(t), y_spline(t)
        return (x - a) ** 2 + (y - b) ** 2  # Squared Euclidean distance

    # Minimize over t in the valid range
    result = minimize_scalar(distance_function, bounds= s_lim, method='bounded')

    # Get the closest point
    t_min = result.x
    closest_x, closest_y = x_spline(t_min), y_spline(t_min)

    return t_min