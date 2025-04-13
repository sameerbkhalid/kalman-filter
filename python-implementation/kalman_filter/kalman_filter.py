import numpy as np
import matplotlib.pyplot as plt

def apply_kalman_filter(measurements, total_time):
    A = np.array([[1, 1],
                  [0, 1]])
    Q = np.array([[0.004, 0.002],
                  [0.002, 0.001]])
    R = np.array([[0.4, 0.01],
                  [0.04, 0.01]])
    C = np.eye(2)

    P = np.zeros((2, 2))
    x = np.array([30.0, 20.0])

    estimated_states = []

    for k in range(total_time):
        z = measurements[k]

        # Prediction
        x = A @ x
        P = A @ P @ A.T + Q

        # Kalman Gain
        K = P @ C.T @ np.linalg.inv(C @ P @ C.T + R)

        # Update
        x = x + K @ (z - C @ x)
        P = (np.eye(2) - K @ C) @ P

        estimated_states.append(x.copy())

    return np.array(estimated_states)

