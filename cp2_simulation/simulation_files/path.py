import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline
import matplotlib.patches as patches
from matplotlib.path import Path
import csv
import matlab.engine

def generate_race_track(
    num_points=1000, 
    track_width=12
):
    """
    Generate a closed-loop race track with a straight section followed by a hairpin curve.
    
    Args:
        num_points: Number of points for the final path
        track_width: Width of the track
        
    Returns:
        Tuple of (center_line, inner_boundary, outer_boundary, waypoints)
    """
    
     ###################################### TRACK 1 ##############################################################
    waypoints = [
        # (0,0),
        # (200,0),
        # (400,0),
        # (600,0),
        # (800,0),
        # (800,200),
        # (0,400),
        # (0,0)
        (0, 0),       # 1: Start point
        (50, 0),       # 2: Start of straight section
        (200, 50),      # 3: Straight section
        (650, 0),      # 4: Straight section
        (900, 0),      # 5: Straight section
        (1250, 0),      # 6: End of straight section
        (1300, 10),      # 7: Beginning of hairpin
        (1280, 50),      # 8: Middle of hairpin turn
        # (28, 5),      # 9: Continuing hairpin
        (1150, 40),     # 10: End of hairpin
        (900, 150),      # 11: Start of top straight
        (900, 300),      # 12: Slight curve
        (800, 400),     # 13: Continue curve
        (750, 340),
        (620, 380),     # 14: Top section
        (600, 200),
        (570, 50),      # 15: Beginning of left turn
        (400, 100),      # 16: Left turn
        (300, 170),      # 17: Continuing left turn
        (150, 130),      # 18: Final turn
        (0, 50),        # 19: Close the loop (same as point 1)
        (0, 0)
    ]
    #############################################################################################################
    # waypoints = [
    #     (0, 0),
    #     (200, 0),
    #     (300, 0),
    #     (400, -80),
    #     (475, -20),
    #     (550, -100),
    #     (660, -300),
    #     (850, -300),
    #     (800, -100),
    #     (600, 0),
    #     (200, 150),
    #     (-100, 200),
    #     (-50, 0),
    #     (0, -300),
    #     (400, -300),
    #     (500, -150),
    #     (400, -150),
    #     (300, -250),
    #     (200, -290),
    #     (200, -150),
    #     (50, -100),
    #     (0, 0)
    # ]
    
    # Extract x and y coordinates
    x_points = np.array([p[0] for p in waypoints])
    y_points = np.array([p[1] for p in waypoints])
    
    # Create parameter values (distance along the path)
    t = np.zeros(len(waypoints))
    for i in range(1, len(waypoints)):
        t[i] = t[i-1] + np.sqrt((x_points[i] - x_points[i-1])**2 + (y_points[i] - y_points[i-1])**2)
    
    # Create periodic cubic spline interpolation for a smoother closed loop
    cs_x = CubicSpline(t, x_points, bc_type='periodic')
    cs_y = CubicSpline(t, y_points, bc_type='periodic')
    
    # Generate points along the smooth path
    t_smooth = np.linspace(0, t[-1], num_points)
    x_smooth = cs_x(t_smooth)
    y_smooth = cs_y(t_smooth)
    
    # Calculate derivatives (tangent vectors)
    dx = cs_x.derivative()(t_smooth)
    dy = cs_y.derivative()(t_smooth)
    
    # Normalize tangent vectors
    norm = np.sqrt(dx**2 + dy**2)
    dx = dx / norm
    dy = dy / norm
    
    # Calculate normal vectors (perpendicular to tangent)
    nx = -dy
    ny = dx
    
    # Calculate inner and outer boundaries
    inner_x = x_smooth - nx * track_width / 2
    inner_y = y_smooth - ny * track_width / 2
    outer_x = x_smooth + nx * track_width / 2
    outer_y = y_smooth + ny * track_width / 2
    
    center_line = (x_smooth, y_smooth)
    filename = "../MW208_Raceline_Optimization/my_track.csv"

    
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["x", "y", "inner_offset", "outer_offset"])  # Header
        for x, y in zip(x_smooth, y_smooth):
            writer.writerow([x, y, track_width/2, track_width/2])
    inner_boundary = (inner_x, inner_y)
    outer_boundary = (outer_x, outer_y)
    
    return center_line, inner_boundary, outer_boundary, waypoints

def generate_clothoid_trajectory(center_line, track_width, num_points=500):
    """
    Generate a realistic vehicle trajectory using clothoid-like principles,
    but staying within the track boundaries and ensuring a closed loop.
    
    Args:
        center_line: Tuple of (x, y) arrays representing the center line
        num_points: Number of points for the clothoid path
        
    Returns:
        Tuple of (x, y) arrays representing the clothoid path
    """
    x_center, y_center = center_line
    
    # Calculate the curvature at each point on the center line
    curvature = np.zeros(len(x_center))
    
    for i in range(1, len(x_center)-1):
        # Get three consecutive points
        x1, y1 = x_center[i-1], y_center[i-1]
        x2, y2 = x_center[i], y_center[i]
        x3, y3 = x_center[i+1], y_center[i+1]
        
        # Vectors between points
        v1 = np.array([x2 - x1, y2 - y1])
        v2 = np.array([x3 - x2, y3 - y2])
        
        # Normalize vectors
        v1_norm = np.linalg.norm(v1)
        v2_norm = np.linalg.norm(v2)
        
        if v1_norm > 0 and v2_norm > 0:
            v1 = v1 / v1_norm
            v2 = v2 / v2_norm
            
            # Dot product for angle
            dot_product = np.clip(np.dot(v1, v2), -1.0, 1.0)
            angle = np.arccos(dot_product)
            
            # Cross product for sign
            cross_product = np.cross(np.append(v1, 0), np.append(v2, 0))[2]
            sign = np.sign(cross_product)
            
            # Approximate curvature
            curvature[i] = angle * sign
    
    # First and last points should have same curvature for continuity
    curvature[0] = curvature[-1] = (curvature[1] + curvature[-2]) / 2
    
    # Find points of high curvature (turns)
    turns = []
    threshold = np.std(curvature) * 1
    
    for i in range(1, len(curvature)-1):
        if abs(curvature[i]) > threshold:
            if len(turns) == 0 or i - turns[-1][0] > 50:  # Ensure turns are separated
                turns.append((i, curvature[i]))
    
    # Create racing line trajectory
    # Sample points from the center line but shift toward inside of turns
    indices = np.linspace(0, len(x_center)-1, num_points, dtype=int)
    x_trajectory = []
    y_trajectory = []
    
    # Ensure we start and end at the same point for a closed loop
    start_point = (x_center[0], y_center[0])
    
    for idx in indices:
        x, y = x_center[idx], y_center[idx]
        
        # Calculate shift based on nearby turns
        # Shifts more toward inside of turn and approaches outside on straights
        shift_x, shift_y = 0, 0
        
        for turn_idx, turn_curvature in turns:
            # Distance to turn (in index space)
            distance = min(
                abs(idx - turn_idx),
                abs(idx - turn_idx + len(x_center)),
                abs(idx - turn_idx - len(x_center))
            )
            
            # Influence decreases with distance
            influence = max(0, 1 - (distance / 200)**2)
            
            if influence > 0:
                # Direction to shift (normal to centerline)
                nx = -y_center[turn_idx+1] + y_center[turn_idx-1]
                ny = x_center[turn_idx+1] - x_center[turn_idx-1]
                
                # Normalize
                norm = np.sqrt(nx**2 + ny**2)
                if norm > 0:
                    nx, ny = nx/norm, ny/norm
                    
                    # Shift toward inside of turn
                    # negative curvature = right turn, shift left
                    # positive curvature = left turn, shift right
                    shift_factor = -np.sign(turn_curvature) * 0.4 * influence
                    shift_x += nx * shift_factor
                    shift_y += ny * shift_factor
        
        # Apply the shift but keep within reasonable bounds (70% of track width)
        max_shift = 0.35  # 70% of half-track width
        shift_norm = np.sqrt(shift_x**2 + shift_y**2)
        
        if shift_norm > max_shift:
            shift_x = shift_x * max_shift / shift_norm
            shift_y = shift_y * max_shift / shift_norm
            
        # Add racing line point
        x_trajectory.append(x + shift_x)
        y_trajectory.append(y + shift_y)
    
    # Ensure the path is closed by matching start and end points exactly
    x_trajectory[0] = x_trajectory[-1] = start_point[0]
    y_trajectory[0] = y_trajectory[-1] = start_point[1]
    
    # Apply smoothing to the trajectory
    # Create a parameter array for the trajectory
    t_traj = np.linspace(0, 1, len(x_trajectory))
    
    # Create a periodic spline for the trajectory
    cs_x_traj = CubicSpline(t_traj, x_trajectory, bc_type='periodic')
    cs_y_traj = CubicSpline(t_traj, y_trajectory, bc_type='periodic')
    
    # Generate points along the smooth trajectory
    t_smooth = np.linspace(0, 1, num_points)
    x_smooth = cs_x_traj(t_smooth)
    y_smooth = cs_y_traj(t_smooth)
    
    
    
    
    

    
    return x_smooth, y_smooth

def visualize_race_track(center_line, inner_boundary, outer_boundary, waypoints, track_width = 1.0, title="Race Track", clothoid_path = None):
    """
    Visualize the race track with center line and boundaries.
    
    Args:
        center_line: Tuple of (x, y) arrays representing the center line
        inner_boundary: Tuple of (x, y) arrays representing the inner boundary
        outer_boundary: Tuple of (x, y) arrays representing the outer boundary
        waypoints: List of (x, y) tuples representing the original waypoints
        title: Title for the plot
    """
    fig, ax = plt.subplots(figsize=(14, 10))
    
    x_center, y_center = center_line
    x_inner, y_inner = inner_boundary
    x_outer, y_outer = outer_boundary
    x_points = [p[0] for p in waypoints]
    y_points = [p[1] for p in waypoints]
    
    # Create a polygon for the track surface
    track_vertices = np.column_stack([
        np.append(x_outer, x_inner[::-1]),
        np.append(y_outer, y_inner[::-1])
    ])
    track_path = Path(track_vertices)
    track = patches.PathPatch(track_path, facecolor='gray', alpha=0.5, edgecolor='none')
    ax.add_patch(track)
    
    # Plot boundaries
    ax.plot(x_inner, y_inner, 'k-', linewidth=2, label='Inner Boundary')
    ax.plot(x_outer, y_outer, 'k-', linewidth=2, label='Outer Boundary')
    
    if clothoid_path is not None:
        clothoid_x, clothoid_y = clothoid_path
    
        # Plot clothoid path
        ax.plot(clothoid_x, clothoid_y, 'y--', linewidth=2, label='Vehicle Trajectory (Optimial)')
        
        # Plot waypoints
        ax.plot(x_points, y_points, 'ro', markersize=6, label='Waypoints')
        
        # Add direction indicators along the clothoid path
        num_arrows = 20
        arrow_indices = np.linspace(0, len(clothoid_x)-1, num_arrows, dtype=int)
        
        for i in arrow_indices:
            if i+5 < len(clothoid_x):
                dx = clothoid_x[i+5] - clothoid_x[i]
                dy = clothoid_y[i+5] - clothoid_y[i]
                arrow = patches.FancyArrowPatch(
                    (clothoid_x[i], clothoid_y[i]),
                    (clothoid_x[i] + dx/3, clothoid_y[i] + dy/3),
                    arrowstyle='->', 
                    mutation_scale=15,
                    color='blue'
                )
                ax.add_patch(arrow)
    
    # Find index corresponding to x=4 for Start/Finish line
    distances = np.abs(x_center )
    start_idx = np.argmin(distances)
    
    # Add "Start/Finish" line at position (4, 0)
    ax.plot([x_inner[start_idx], x_outer[start_idx]], 
            [y_inner[start_idx], y_outer[start_idx]], 
            'r-', linewidth=4)
    ax.text(4, 0, "START/FINISH", 
            color='red', fontsize=12, ha='center', va='bottom', fontweight='bold')
    
    # Add numbers to waypoints
    for i, (x, y) in enumerate(waypoints):
        ax.annotate(f"{i+1}", (x, y), fontsize=12, ha='center', va='center',
                   bbox=dict(boxstyle="circle", fc="white", ec="black", alpha=0.7))
    
    ax.set_title(title, fontsize=16)
    ax.set_xlabel('X', fontsize=12)
    ax.set_ylabel('Y', fontsize=12)
    ax.legend(loc='upper right')
    ax.grid(True, alpha=0.3)
    ax.set_aspect('equal')  # Equal aspect ratio
    ax.set_facecolor('#1E5631')  # Green background to represent grass
    
    # Adjust plot limits to include a margin
    margin = 3
    xlim = [min(np.min(x_inner), np.min(x_outer)) - margin, 
            max(np.max(x_inner), np.max(x_outer)) + margin]
    ylim = [min(np.min(y_inner), np.min(y_outer)) - margin, 
            max(np.max(y_inner), np.max(y_outer)) + margin]
    # ax.set_xlim(xlim)
    # ax.set_ylim(ylim)
    
    plt.tight_layout()
    return fig, ax


def main():
    # Generate race track
    center_line, inner_boundary, outer_boundary, waypoints = generate_race_track(
        num_points=2000, 
        track_width= 12
    )
    
    # Visualize the race tracky_traj
    fig, ax = visualize_race_track(
        center_line, 
        inner_boundary, 
        outer_boundary, 
        waypoints,
        clothoid_path= None,
        title="Race Track with Vehicle Trajectory"
    )
    
    plt.show()

if __name__ == "__main__":
    main()