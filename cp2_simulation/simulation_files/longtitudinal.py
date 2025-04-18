import numpy as np
from constants import * 

def feedforward(u,s,r):
    c = np.sqrt(1/(r*2*s))
    alpha = np.sqrt ((mu*g)**2 - (2*c**2*s*u**2)**2)
    return M * alpha


def sc_feedback():
    return 0 

def speed_feedback():
    return 0


def longtituinal_controller(u,s,r):
    return feedforward(u,s,r) + sc_feedback() + speed_feedback()