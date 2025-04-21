M = 750.0 # mass of the car (kg)
g = 9.81
FT_MAX = 16.0 # max traction acceleration (m/s^2)
FB_MAX = 16.0 # max braking acceleration (m/s^2)
FN_MAX = 30.0 # max cornering acceleration (m/s^2)
MAX_THROTTLE_FORCE = M * FT_MAX # max throttle force (N)
MAX_BRAKING_FORCE = M * FB_MAX # max braking force (N)
MAX_LATERAL_FORCE = M * FN_MAX # max lateral force (N)
L = 3 # vehicle wheel base length 
DIST_AXLE_FRONT = 1.5   # distance from front axle to center of mass
DIST_AXLE_REAR= 1.5 # distance from rear axle to center of mass
AXLE_NORMAL_LOAD_FRONT= DIST_AXLE_REAR/L * M * g # normal load on front axle
AXLE_NORMAL_LOAD_REAR = DIST_AXLE_FRONT/L * M * g # normal load on rear axle
LATERAL_AXLE_STIFFNESS_FRONT = 210000 # lateral stiffness of front axle (N/m)
LATERAL_AXLE_STIFFNESS_REAR = 210000# lateral stiffness of rear axle (N/m)
TRACK_WIDTH = 12 # width of the track (m)
TIRE_RADIUS = 0.635
k_gain = 1500
a_gain = 1500
k_peak = 5
a_ref = 5
a_peak = 8 
k_speed = 2000
NUM_ITER = 1000# number of iterations of simulation
dt = 0.01 # time step

K_ff = 1 # feedforward gain
K_LC = 2.5 # lane keep controller gain
X_LA = 25 # look ahead distance

mu = 0.7 # friction coefficient

K_SLIP = 0.5       # Slip compensation gain
K_NOSLIP = 1.2     # Aggressiveness when no slip
SLIP_THRESHOLD = 0.8  # Normalized slip ratio threshold
SAFETY_MARGIN = 0.1   # Distance from slip circle boundary