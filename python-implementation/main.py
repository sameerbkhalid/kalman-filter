import numpy as np
from kalman_filter.data_generation import generate_data, add_noise
from kalman_filter.kalman_filter import apply_kalman_filter
from kalman_filter.plotter import plot_data

def main():
    total_time = 50

    # Generate true data and noisy measurements
    true_values = generate_data(total_time)
    measurements = add_noise(true_values)
    
    # Apply Kalman filter to get estimated states
    estimations = apply_kalman_filter(measurements, total_time)

    # Extract true, measured, and estimated displacement and velocity
    true_disp, measured_disp, estimated_disp = [], [], []
    true_vel, measured_vel, estimated_vel = [], [], []

    for i in range(total_time):
        true_disp.append(true_values[i][0])
        measured_disp.append(measurements[i][0])
        estimated_disp.append(estimations[i][0])

        true_vel.append(true_values[i][1])
        measured_vel.append(measurements[i][1])
        estimated_vel.append(estimations[i][1])

    # Plot Displacement
    plot_data(
        time=list(range(total_time)),
        true_data=true_disp,
        measured_data=measured_disp,
        estimated_data=estimated_disp,
        data_type="displacement",
    )

    # Plot Velocity
    plot_data(
        time=list(range(total_time)),
        true_data=true_vel,
        measured_data=measured_vel,
        estimated_data=estimated_vel,
        data_type="velocity",
    )

if __name__ == "__main__":
    main()
