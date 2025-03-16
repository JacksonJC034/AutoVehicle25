import numpy as np
from constants import *

def feedforward (R,U_x,t):
    u = U_x[t]
    K_ug = AXLE_NORMAL_LOAD_FRONT/LATERAL_AXLE_STIFFNESS_FRONT - AXLE_NORMAL_LOAD_REAR/LATERAL_AXLE_STIFFNESS_REAR # understeer gradient
    delta_feedforward = (L + K_ug * u**2/g)*1/R
    return delta_feedforward