#ifndef DATA_GENERATION_HPP_
#define DATA_GENERATION_HPP_

#include <Eigen/Dense>
#include <vector>

namespace data_generation {

// Generates displacement and velocity using a constant acceleration model.
std::vector<Eigen::Vector2d> generateData(int total_time);

// Adds Gaussian noise to displacement and velocity.
std::vector<Eigen::Vector2d> addNoise(const std::vector<Eigen::Vector2d>& true_values);

}  // namespace data_generation

#endif  // DATA_GENERATION_HPP_
