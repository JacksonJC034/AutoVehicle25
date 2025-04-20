%% Racing Line Optimizer
% Import track data

track = readmatrix("my_track.csv")
% Define variables

trackName = 'Silverstone';
m = 75; % Mass of vehicle
ftmax = 1.6; % Max acceleration (m/s^2)
fbmax = 1.8; % Min acceleration (m/s^2)
fnmax = 3.0; % Max cornering acceleration (m/s^2)
% Generate optimized path

[trajMCP, trackData] = minCurvaturePathGenFunction(track,trackName);
% Click on the drop down menu to select the method for generating the optimized path
% Generate velocity profile

[velProf,len] = velProfCalcFunction(trajMCP,trackName,m,ftmax,fbmax,fnmax,trackData);
% References:
%% 
% * The Silverstone racetrack data has been ta    ken from the following GitHub 
% repository: <https://github.com/TUMFTM/racetrack-database https://github.com/TUMFTM/racetrack-database> 
% * The function, "velProfCalcFunction" uses the function, "curvature" that 
% has been taken from the following File Exchange: <https://www.mathworks.com/matlabcentral/fileexchange/69452-curvature-of-a-1d-curve-in-a-2d-or-3d-space 
% https://www.mathworks.com/matlabcentral/fileexchange/69452-curvature-of-a-1d-curve-in-a-2d-or-3d-space>