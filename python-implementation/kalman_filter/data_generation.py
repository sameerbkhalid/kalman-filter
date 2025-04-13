import numpy as np

def generate_data(total_time):
    velocity = 2.0
    displacement = 0.0
    acceleration = 2.0

    true_values = []
    for _ in range(total_time):
        displacement += velocity + 0.5 * acceleration
        velocity += acceleration
        true_values.append([displacement, velocity])
    
    return np.array(true_values)

def add_noise(true_values, disp_std=100.0, vel_std=10.0):
    noise_disp = np.random.normal(0, disp_std, size=true_values.shape[0])
    noise_vel = np.random.normal(0, vel_std, size=true_values.shape[0])
    
    noisy_values = true_values.copy()
    noisy_values[:, 0] += noise_disp
    noisy_values[:, 1] += noise_vel
    return noisy_values
