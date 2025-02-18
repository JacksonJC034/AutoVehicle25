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


def simulate_open_loop():
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
    
    # Open-loop inputs (step steering and constant longitudinal force)
    delta = np.zeros_like(t)
    delta[200:] = np.deg2rad(5)  # 5° steering after 2 seconds
    Fx = 500 * np.ones_like(t)   # Constant longitudinal force
    
    # Initial states: [x, y, psi, vx, vy, omega] (ensure float type)
    states = np.array([0, 0, 0, 20, 0, 0], dtype=float)
    
    # Initialize arrays to store trajectory and velocity (speed)
    trajectory = np.zeros((len(t), 2))  # For x and y positions
    velocities = np.zeros(len(t))       # For speed (magnitude of velocity)
    
    for i in range(len(t)):
        trajectory[i, :] = states[0], states[1]
        # Calculate speed as the magnitude of the velocity vector
        velocities[i] = np.sqrt(states[3]**2 + states[4]**2)
        u = [delta[i], Fx[i]]
        derivatives = bicycle_model(t[i], states, u, params)
        states += np.array(derivatives) * dt
    
    return t, trajectory, velocities

def plot_trajectory_and_velocity(t, trajectory, velocities):
    # Create a figure with two subplots (vertical layout)
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 12))
    
    # Subplot 1: Vehicle trajectory (x-y path)
    ax1.plot(trajectory[:, 0], trajectory[:, 1], 'b-', label='Vehicle Path')
    ax1.set_xlabel('X (m)')
    ax1.set_ylabel('Y (m)')
    ax1.set_title('Open-Loop Vehicle Trajectory')
    ax1.grid(True)
    ax1.axis('equal')
    ax1.legend()
    
    # Subplot 2: Vehicle speed vs. time
    ax2.plot(t, velocities, 'r-', label='Speed')
    ax2.set_xlabel('Time (s)')
    ax2.set_ylabel('Speed (m/s)')
    ax2.set_title('Vehicle Speed Over Time')
    ax2.grid(True)
    ax2.legend()
    
    plt.tight_layout()
    plt.savefig('media/oepn_loop.png', dpi=300)
    plt.show()

def animate_trajectory(trajectory):
    # (Animation function remains unchanged)
    fig, ax = plt.subplots()
    line, = ax.plot([], [], 'b-', lw=2)
    current_pos, = ax.plot([], [], 'ro')
    ax.set_xlim(-10, np.max(trajectory[:, 0]) + 10)
    ax.set_ylim(-10, np.max(trajectory[:, 1]) + 10)
    ax.set_xlabel('X (m)')
    ax.set_ylabel('Y (m)')
    ax.grid(True)
    
    def update(frame):
        line.set_data(trajectory[:frame, 0], trajectory[:frame, 1])
        current_pos.set_data([trajectory[frame-1, 0]], [trajectory[frame-1, 1]])
        return line, current_pos
    
    ani = FuncAnimation(fig, update, frames=len(trajectory), blit=True, repeat=False)
    # Save the animation (if ffmpeg is available or use an alternative)
    ani.save('media/open_loop.mp4', writer='ffmpeg', fps=30)
    plt.close()

if __name__ == "__main__":
    t, trajectory, velocities = simulate_open_loop()
    plot_trajectory_and_velocity(t, trajectory, velocities)
    animate_trajectory(trajectory)
