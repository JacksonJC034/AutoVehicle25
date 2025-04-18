import numpy as np
from constants import * 

def feedforward(m,a):
    
    return m*a


def sc_feedback():
    return 0 

def speed_feedback():
    return 0


def longtituinal_controller(m,a):
    return feedforward(m,a) + sc_feedback() + speed_feedback()