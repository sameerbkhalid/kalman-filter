
#include "data_generation.hpp"
#include <random>

namespace data_generation {

std::vector<Eigen::Vector2d> generateData(int total_time) {

    // Using constant acceleration model to generate data
    double velocity = 2.0;
    double displacement = 0.0;
    double acceleration = 2.0;
    
    std::vector<Eigen::Vector2d> true_values;

    for (int t = 0; t < total_time; ++t) {
        // Update displacement: s = v * t + 0.5* a * t^2
        displacement += velocity + 0.5 * acceleration;  
        // Update velocity: v_f = v_i + a * t
        velocity += acceleration;
        true_values.emplace_back(displacement, velocity);
    }

    return true_values;}

std::vector<Eigen::Vector2d> addNoise(const std::vector<Eigen::Vector2d>& true_values) {
    std::random_device rd;      // non-deterministic random seed
    std::mt19937 gen(rd());     // pseudo-random generator
    
    // Create normal distributions 
    std::normal_distribution<double> noise_disp(0.0, 100.0);  // Mean 0, std deviation 100
    std::normal_distribution<double> noise_vel(0.0, 10.0);    // Mean 0, std deviation 10

    std::vector<Eigen::Vector2d> measurements;

    // Add gaussian noise to the displacement and velocity measurements
    for (const auto& value : true_values) {
        measurements.emplace_back(value[0] + noise_disp(gen), value[1] + noise_vel(gen));
    }
    return measurements;
}

}  // namespace data_generation