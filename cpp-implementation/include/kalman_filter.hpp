#ifndef KALMAN_FILTER_HPP_
#define KALMAN_FILTER_HPP_

#include <Eigen/Dense>
#include <vector>

namespace kalman {

// Applies a 2D Kalman filter to the noisy measurements.
std::vector<Eigen::Vector2d> applyKalmanFilter(const std::vector<Eigen::Vector2d>& measurements, int total_time);

}  // namespace kalman

#endif  // KALMAN_FILTER_HPP_
