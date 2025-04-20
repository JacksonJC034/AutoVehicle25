import numpy as np
from constants import *
from path import *

# run path.py to generate my_track.csv
center_line, inner_boundary, outer_boundary, waypoints = generate_race_track(
        num_points=2000, 
        track_width= TRACK_WIDTH
    )



# start the matlab engine
eng = matlab.engine.start_matlab()
eng.eval("set(0, 'DefaultFigureVisible', 'off');", nargout=0) # supress figures 
eng.addpath('/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/simulation_files/MW208_Raceline_Optimization')



# file name of csv, name of track, call minimum curvature path generation function
file_name = "my_track.csv"
track_name = 'my_track'
(MCP_track, original_track) = eng.minCurvaturePathGenFunction (file_name, track_name, nargout = 2)
(vel_prof, len) = eng.velProfCalcFunction (MCP_track, track_name, M, FT_MAX, FB_MAX, FN_MAX, original_track, nargout = 2)



# convert to numpy array 
MCP_track = np.array(MCP_track)
np.savetxt('/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/simulation_files/track_info/MCP_track.csv', MCP_track, delimiter=',', fmt='%s')


vel_prof = np.array(vel_prof)
np.savetxt('/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/simulation_files/track_info/vel_prof.csv', vel_prof, delimiter=',', fmt='%s')

s = np.array (len)
np.savetxt('/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/src/simulation_files/track_info/s.csv', s, delimiter=',', fmt='%s')