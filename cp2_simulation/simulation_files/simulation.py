from path import *
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import matlab.engine 
from constants import *


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



# Plot the velocity profile
plt.figure (1) 
plt.scatter (MCP_track[:,0], MCP_track[:,1], c = vel_prof, cmap = cm.jet, s = 2)
plt.axis('equal')
colBar = plt.colorbar()
colBar.set_label("Velocity [m/s]")


# Visualize the race tracky_traj
fig, ax = visualize_race_track(
        center_line, 
        inner_boundary, 
        outer_boundary, 
        waypoints,
        clothoid_path = (MCP_track[:,0], MCP_track[:,1]),
        title="Race Track with Clothoid Path for Vehicle Trajectory"
)
# //ax.plot (x,y)

plt.show()