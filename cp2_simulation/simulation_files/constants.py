M = 750.0 # mass of the car (kg)
g = 9.81
FT_MAX = 16.0 # max traction acceleration (m/s^2)
FB_MAX = 16.0 # max braking acceleration (m/s^2)
FN_MAX = 30.0 # max cornering acceleration (m/s^2)
L = 3 # vehicle wheel base length 
DIST_AXLE_FRONT = 1.5   # distance from front axle to center of mass
DIST_AXLE_REAR= 1.5 # distance from rear axle to center of mass
AXLE_NORMAL_LOAD_FRONT= DIST_AXLE_REAR/L * M * g # normal load on front axle
AXLE_NORMAL_LOAD_REAR = DIST_AXLE_FRONT/L * M * g # normal load on rear axle
LATERAL_AXLE_STIFFNESS_FRONT = 210000 # lateral stiffness of front axle (N/m)
LATERAL_AXLE_STIFFNESS_REAR = 210000# lateral stiffness of rear axle (N/m)
TRACK_WIDTH = 12 # width of the track (m)

NUM_ITER = 1000# number of iterations of simulation
dt = 0.01 # time step

K_ff = 1 # feedforward gain
K_LC = 2.5#  lane keep controller gain
X_LA = 25# look ahead distance

mu = 0.7 # friction coefficient