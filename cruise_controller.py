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

    # Compute slip angles (simplified)
    # Note: Parentheses ensure proper evaluation order.
    alpha_f = delta - np.arctan((vy + lf * omega) / (vx + 1e-6))
    alpha_r = -np.arctan((vy - lr * omega) / (vx + 1e-6))
    
    # Tire forces using a simplified Fiala model
    mu = params['mu']
    Fz_f = (m * g * lr) / (lf + lr)
    Fz_r = (m * g * lf) / (lf + lr)
    
    Fy_f = mu * Fz_f * np.sin(1.5 * np.arctan(-alpha_f / 0.1))
    Fy_r = mu * Fz_r * np.sin(1.5 * np.arctan(-alpha_r / 0.1))
    
    # Dynamics equations
    ax = (Fx - Fy_f * np.sin(delta)) / m + vy * omega
    ay = (Fy_f * np.cos(delta) + Fy_r) / m - vx * omega
    domega = (lf * Fy_f * np.cos(delta) - lr * Fy_r) / Iz
    
    # Kinematic equations
    dxdt = vx * np.cos(psi) - vy * np.sin(psi)
    dydt = vx * np.sin(psi) + vy * np.cos(psi)
    dpsidt = omega
    
    return [dxdt, dydt, dpsidt, ax, ay, domega]

def simulate_cruise_control():
    # Vehicle parameters
    params = {
        'm': 1500,
        'Iz': 2500,
        'lf': 1.2,
        'lr': 1.5,
        'mu': 0.9
    }
    
    # Time vector and timestep
    t = np.linspace(0, 10, 1000)
    dt = t[1] - t[0]
    
    # Initial states: [x, y, psi, vx, vy, omega]
    # Starting with a lateral offset y=1.0 m and an initial vx=15 m/s
    states = np.array([0, 1.0, 0, 15.0, 0, 0], dtype=float)
    
    # Initialize control inputs (arrays over time)
    delta = np.zeros_like(t)  # steering angle (radians)
    Fx = np.zeros_like(t)     # longitudinal force (N)
    
    # Control parameters
    target_speed = 20.0        # desired forward speed in m/s
    max_steer = np.deg2rad(5)   # maximum steering angle (5 deg in radians)
    max_Fx = 8000              # maximum Fx (N)
    
    # PID gains for lane-keeping (steering control)
    Kp_y = 0.4
    Kd_y = 0.6
    Ki_y = 0.05
    y_integral = 0.0
    
    # PID gains for speed control
    Kp_speed = 800.0
    Ki_speed = 50.0
    Kd_speed = 200.0
    speed_integral = 0.0
    prev_speed_error = 0.0
    
    # Rate limiting parameters
    max_delta_rate = 1.0   # maximum change in delta [rad/s]
    max_Fx_rate = 2000.0   # maximum change in Fx [N/s]
    
    # Storage arrays for simulation results
    trajectory = np.zeros((len(t), 2))  # [x, y]
    velocities = np.zeros(len(t))       # overall speed = sqrt(vx^2+vy^2)
    controls = np.zeros((len(t), 2))      # [delta, Fx]
    
    for i in range(len(t)):
        # Store current state values
        trajectory[i, :] = states[0], states[1]
        velocities[i] = np.sqrt(states[3]**2 + states[4]**2)
        
        # Retrieve current state values
        y_pos = states[1]
        psi = states[2]
        vx = states[3]
        vy = states[4]
        
        # Compute lateral speed (dydt) using kinematics
        current_dydt = vx * np.sin(psi) + vy * np.cos(psi)
        
        # ----- Lane-Keeping Control (for steering) -----
        # We want to drive y -> 0.
        y_error = y_pos
        y_integral += y_error * dt
        delta_desired = Kp_y * y_error + Kd_y * current_dydt + Ki_y * y_integral
        # Saturate the desired steering angle to allowable limits
        delta_desired = np.clip(delta_desired, -max_steer, max_steer)
        
        # ----- Speed Control (for longitudinal force) -----
        speed_error = target_speed - vx
        speed_integral += speed_error * dt
        speed_derivative = (speed_error - prev_speed_error) / dt
        Fx_desired = Kp_speed * speed_error + Ki_speed * speed_integral + Kd_speed * speed_derivative
        Fx_desired = np.clip(Fx_desired, -max_Fx, max_Fx)
        prev_speed_error = speed_error
        
        # ----- Rate Limiting (Slew-Rate Limiter) -----
        if i == 0:
            # For the first step, no previous value exists
            delta[i] = delta_desired
            Fx[i] = Fx_desired
        else:
            # Limit the change in steering angle per timestep
            delta_change = np.clip(delta_desired - delta[i-1], -max_delta_rate * dt, max_delta_rate * dt)
            delta[i] = delta[i-1] + delta_change
            
            # Limit the change in longitudinal force per timestep
            Fx_change = np.clip(Fx_desired - Fx[i-1], -max_Fx_rate * dt, max_Fx_rate * dt)
            Fx[i] = Fx[i-1] + Fx_change
        
        # Save control values
        controls[i, :] = delta[i], Fx[i]
        
        # Update the vehicle state using Euler integration
        u = [delta[i], Fx[i]]
        derivatives = bicycle_model(t[i], states, u, params)
        states += np.array(derivatives) * dt
        
    return t, trajectory, velocities, controls

def plot_results(t, trajectory, velocities, controls):
    fig, axs = plt.subplots(2, 1, figsize=(10, 8))
    
    # Trajectory plot
    axs[0].plot(trajectory[:, 0], trajectory[:, 1], 'b-')
    axs[0].set_title('Vehicle Trajectory')
    axs[0].set_xlabel('X [m]')
    axs[0].set_ylabel('Y [m]')
    axs[0].grid(True)
    axs[0].axis('equal')
    
    # Overall speed plot
    axs[1].plot(t, velocities, 'r-', label='Speed (m/s)')
    axs[1].set_title('Overall Vehicle Speed')
    axs[1].set_xlabel('Time [s]')
    axs[1].set_ylabel('Speed [m/s]')
    axs[1].grid(True)
    axs[1].legend()
    
    plt.tight_layout()
    plt.savefig('media/cruise_control.png', dpi=300)
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
    ax.set_title('Cruise Control Trajectory Animation')
    
    def update(frame):
        # Update the path line with the trajectory up to the current frame
        line.set_data(trajectory[:frame, 0], trajectory[:frame, 1])
        # Wrap the scalars in lists so set_data receives sequences
        current_pos.set_data([trajectory[frame-1, 0]], [trajectory[frame-1, 1]])
        return line, current_pos
    
    ani = FuncAnimation(fig, update, frames=len(trajectory), blit=True, repeat=False)
    ani.save('media/cruise_control.mp4', writer='ffmpeg', fps=30)
    plt.close()

if __name__ == "__main__":
    t, trajectory, velocities, controls = simulate_cruise_control()
    plot_results(t, trajectory, velocities, controls)
    animate_trajectory(trajectory)
