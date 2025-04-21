import numpy as np
from simulation_files.constants import * 

def feedforward(m,a):
    
    return m*a

# def feedforward(mass, mu, c, s, U_x_desired):
#     """Equation (4)"""
#     a_x_ff = np.sqrt((mu * g)**2 - (2 * c**2 * s * U_x_desired**2)**2)
#     return mass * a_x_ff


def sc_feedback(angular_vel, v):
    K = (TIRE_RADIUS* angular_vel - v)/v
    A = 0
    Kbar = K/k_peak
    Abar = A/a_ref
    K_delta = abs(Kbar)
    A_delta = abs(Abar) if Abar > 0 else 0

    
    if Kbar <= 0:
        sc_fb = k_gain * K_delta + a_gain * A_delta
    else:
        sc_fb = -k_gain * K_delta - a_gain * A_delta 

    return sc_fb 
    # return 0
    
def slip_feedback(alpha, k):
    """Equations (6)-(9)"""
    # Normalize slips
    alpha_bar = abs(alpha) / a_ref
    k_bar = abs(k) / k_peak

    # Saturation check
    sat = (alpha_bar**2 + k_bar**2) > 1.0

    if sat:
        # Calculate delta terms for saturated axle
        delta_alpha = max(alpha_bar - 1.0, 0.0)
        delta_k = abs(k_bar) - np.sqrt(1.0 - alpha_bar**2) if alpha_bar <= 1.0 else abs(k_bar)

        
        # Apply slip feedback gains
        return k_gain * delta_k + a_gain * delta_alpha
    else:
        # Minimum slip margin control (equation 10-11)
        delta_k_min = np.sqrt(1.0 - alpha_bar**2) - abs(k_bar)
        return K_NOSLIP * delta_k_min

def speed_feedback(U_x_desired, U_x_actual, sat):
    """Equation (12)"""
    if not (sat):
        return k_speed * (U_x_desired - U_x_actual)
    return 0.0


# def longitudinal_controller(m,a, angular_vel, v):
#     #for each
#     ff_force = feedforward(m,a) 
#     #sc_feedback_total = 0
#     #for i in range(len(angular_val)): 
#         #sc_feedback_total += sc_feedback(angular_vel[i], v)
#     #sc_feed_back_total /= 4
#     #lcForce = ff_force + sc_feeback_total
#     return ff_force

def longitudinal_controller(mass, acc, U_x_desired, U_x_actual,
                           alpha, k):
    """Full longitudinal controller per equation (13)"""
    # Calculate components
    F_ff = feedforward(mass, acc)
    F_fb = slip_feedback(alpha, k, a_ref, k_peak)
    F_speed = speed_feedback(U_x_desired, U_x_actual, 
                            (alpha/a_ref)**2 + (k/k_peak)**2 > 1.0)

    # Sum components and apply limits
    F_total = F_ff + F_fb + F_speed
    return np.clip(F_total, -MAX_BRAKING_FORCE, MAX_THROTTLE_FORCE)