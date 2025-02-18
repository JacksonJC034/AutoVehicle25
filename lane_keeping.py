import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

def bicycle_model(t, states, u, params):
    # States: [x, y, psi, vx, vy, omega]
    # Inputs: [delta (steering), Fx (longitudinal force)]
    x, y, psi, vx, vy, omega = states
    delta, Fx = u
    m = params['m']
    Iz = params['Iz']
    lf = params['lf']
    lr = params['lr']
    g = 9.81
    
    # Slip angles (simplified)
    alpha_f = delta - np.arctan((vy + lf * omega) / (vx + 1e-6))  # Avoid division by zero
    alpha_r = -np.arctan((vy - lr * omega) / (vx + 1e-6))
    
    # Nonlinear tire forces (Fiala model)
    mu = params['mu']
    Fz_f = (m * g * lr) / (lf + lr)
    Fz_r = (m * g * lf) / (lf + lr)
    
    # Front lateral force
    Fy_f = mu * Fz_f * np.sin(1.5 * np.arctan(-alpha_f / 0.1))  # Simplified Fiala
    
    # Rear lateral force
    Fy_r = mu * Fz_r * np.sin(1.5 * np.arctan(-alpha_r / 0.1))
    
    # Dynamics
    ax = (Fx - Fy_f * np.sin(delta)) / m + vy * omega
    ay = (Fy_f * np.cos(delta) + Fy_r) / m - vx * omega
    domega = (lf * Fy_f * np.cos(delta) - lr * Fy_r) / Iz
    
    # Derivatives of the position and orientation
    dxdt = vx * np.cos(psi) - vy * np.sin(psi)
    dydt = vx * np.sin(psi) + vy * np.cos(psi)
    dpsidt = omega
    
    return [dxdt, dydt, dpsidt, ax, ay, domega]

def simulate_lane_keeping():
    # Vehicle parameters (example values)
    params = {
        'm': 1500,       # Mass (kg)
        'Iz': 2500,      # Yaw inertia (kg·m²)
        'lf': 1.2,       # Front axle to CG (m)
        'lr': 1.5,       # Rear axle to CG (m)
        'mu': 0.9        # Friction coefficient
    }
    
    # Time vector
    t = np.linspace(0, 10, 1000)
    dt = t[1] - t[0]
    
    # Initialize arrays for inputs and states
    delta = np.zeros_like(t)
    Fx = 500 * np.ones_like(t)   # Constant longitudinal force
    
    # Initial states with initial lateral error
    states = np.array([0, 1.0, 0, 10, 0, 0], dtype=float)  # Start with y=1.0m
    
    # Controller parameters
    Kp = 0.3   # Proportional gain for lateral error
    Kd = 0.5   # Derivative gain for dydt
    delta_max = np.deg2rad(5)  # Maximum steering angle (5 degrees)
    
    # Initialize arrays to store trajectory and velocity
    trajectory = np.zeros((len(t), 2))
    velocities = np.zeros(len(t))
    
    for i in range(len(t)):
        # Store current position and velocity
        trajectory[i, :] = states[0], states[1]
        velocities[i] = np.sqrt(states[3]**2 + states[4]**2)
        
        # Calculate control input (steering angle)
        current_y = states[1]
        current_psi = states[2]
        current_vx = states[3]
        current_vy = states[4]
        
        # Calculate derivative of y (dydt)
        dydt = current_vx * np.sin(current_psi) + current_vy * np.cos(current_psi)
        
        # PD control law
        delta_desired = Kp * current_y + Kd * dydt
        
        # Apply steering limits
        delta[i] = np.clip(delta_desired, -delta_max, delta_max)
        
        # Update states using Euler integration
        u = [delta[i], Fx[i]]
        derivatives = bicycle_model(t[i], states, u, params)
        states += np.array(derivatives) * dt
    
    return t, trajectory, velocities

def plot_trajectory_and_velocity(t, trajectory, velocities):
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 12))
    
    # Trajectory plot
    ax1.plot(trajectory[:, 0], trajectory[:, 1], 'b-', label='Vehicle Path')
    ax1.plot(trajectory[0, 0], trajectory[0, 1], 'go', label='Start')
    ax1.plot(trajectory[-1, 0], trajectory[-1, 1], 'ro', label='End')
    ax1.set_xlabel('X (m)')
    ax1.set_ylabel('Y (m)')
    ax1.set_title('Lane-Keeping Vehicle Trajectory')
    ax1.grid(True)
    ax1.legend()
    ax1.axis('equal')
    
    # Velocity plot
    ax2.plot(t, velocities, 'r-', label='Speed')
    ax2.set_xlabel('Time (s)')
    ax2.set_ylabel('Speed (m/s)')
    ax2.set_title('Vehicle Speed Over Time')
    ax2.grid(True)
    ax2.legend()
    
    plt.tight_layout()
    plt.savefig('media/lane_keeping.png', dpi=300)
    plt.show()

def animate_trajectory(trajectory):
    fig, ax = plt.subplots()
    line, = ax.plot([], [], 'b-', lw=2)
    current_pos, = ax.plot([], [], 'ro')
    ax.set_xlim(-10, np.max(trajectory[:, 0]) + 10)
    ax.set_ylim(-10, np.max(trajectory[:, 1]) + 10)
    ax.set_xlabel('X (m)')
    ax.set_ylabel('Y (m)')
    ax.grid(True)
    ax.set_title('Lane-Keeping Trajectory Animation')
    
    def update(frame):
        # Update the path line with the trajectory up to the current frame
        line.set_data(trajectory[:frame, 0], trajectory[:frame, 1])
        # Wrap the scalars in lists so set_data receives sequences
        current_pos.set_data([trajectory[frame-1, 0]], [trajectory[frame-1, 1]])
        return line, current_pos
    
    ani = FuncAnimation(fig, update, frames=len(trajectory), blit=True, repeat=False)
    ani.save('media/lane_keeping.mp4', writer='ffmpeg', fps=30)
    plt.close()

if __name__ == "__main__":
    t, trajectory, velocities = simulate_lane_keeping()
    plot_trajectory_and_velocity(t, trajectory, velocities)
    animate_trajectory(trajectory)
