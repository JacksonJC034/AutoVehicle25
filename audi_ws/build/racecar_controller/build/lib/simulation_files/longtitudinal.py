import numpy as np
from simulation_files.constants import * 

def feedforward(m,a):
    
    return m*a


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

def speed_feedback():
    
    return 0


def longituinal_controller(m,a, angular_vel, v):
    #for each
    ff_force = feedforward(m,a) 
    #sc_feedback_total = 0
    #for i in range(len(angular_val)): 
        #sc_feedback_total += sc_feedback(angular_vel[i], v)
    #sc_feed_back_total /= 4
    #lcForce = ff_force + sc_feeback_total
    return ff_force