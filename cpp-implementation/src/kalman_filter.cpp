#include "kalman_filter.hpp"

namespace kalman {

std::vector<Eigen::Vector2d> applyKalmanFilter(const std::vector<Eigen::Vector2d>& measurements, int total_time) {
    // State transition matrix (A_t)
    const Eigen::Matrix2d state_transition_matrix = (Eigen::Matrix2d() << 1, 1, 0, 1).finished();

    // Process noise covariance matrix (Q_t)
    const Eigen::Matrix2d process_noise_covariance = (Eigen::Matrix2d() << 0.004, 0.002, 0.002, 0.001).finished();

    // Measurement noise covariance matrix (R_t)
    const Eigen::Matrix2d measurement_noise_covariance = (Eigen::Matrix2d() << 0.4, 0.01, 0.04, 0.01).finished();

    // Measurement matrix (C_t)
    const Eigen::Matrix2d measurement_matrix = Eigen::Matrix2d::Identity();

    // Error covariance matrix (Σ_t−1)
    Eigen::Matrix2d error_covariance_matrix = Eigen::Matrix2d::Zero();

    // Initial state estimate (μ_t−1)
    const double initial_displacement = 30.0;
    const double initial_velocity = 20.0;
    Eigen::Vector2d state_estimate(initial_displacement, initial_velocity);

    std::vector<Eigen::Vector2d> estimated_states;

    for (int k = 0; k < total_time; ++k) {
        const Eigen::Vector2d measurement = measurements[k];

        // PREDICTION STEP:
        // 1) Predicted state estimate (μ_t)
        state_estimate = state_transition_matrix * state_estimate;
        // 2) Predicted error covariance (Σ_t)
        error_covariance_matrix = state_transition_matrix * error_covariance_matrix * state_transition_matrix.transpose() + process_noise_covariance;

        // CORRECTION STEP:
        // 1) Kalman gain (K_t)
        const Eigen::Matrix2d kalman_gain = error_covariance_matrix * measurement_matrix.transpose() *
                                             (measurement_matrix * error_covariance_matrix * measurement_matrix.transpose() + measurement_noise_covariance)
                                                 .inverse();

        // 2) Updated state estimate (μ_t)
        state_estimate += kalman_gain * (measurement - measurement_matrix * state_estimate);

        // 3) Updated error covariance (Σ_t)
        error_covariance_matrix = (Eigen::Matrix2d::Identity() - kalman_gain * measurement_matrix) * error_covariance_matrix;

        // Store the updated state estimate
        estimated_states.push_back(state_estimate);
    }

    return estimated_states;
}


}  // namespace kalman
