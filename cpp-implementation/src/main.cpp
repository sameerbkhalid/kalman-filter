#include <matplotlibcpp.h>
#include <Eigen/Dense>
#include <vector>
#include "kalman_filter.hpp"
#include "data_generation.hpp"
#include "plotter.hpp"

namespace plt = matplotlibcpp;

int main() {
    const int total_time = 50;

    // Generate true values and noisy measurements
    const auto true_values = data_generation::generateData(total_time);
    const auto measurements = data_generation::addNoise(true_values);
    const auto estimations = kalman::applyKalmanFilter(measurements, total_time);

    // Prepare data for displacement plot
    std::vector<double> time, true_disp, measured_disp, estimated_disp;
    for (int i = 0; i < total_time; ++i) {
        time.push_back(static_cast<double>(i));
        true_disp.push_back(true_values[i][0]);
        measured_disp.push_back(measurements[i][0]);
        estimated_disp.push_back(estimations[i][0]);
    }

    // Plot displacement using the general plot function
    plot_data(time, true_disp, measured_disp, estimated_disp, "displacement");

    // Prepare data for velocity plot
    std::vector<double> true_vel, measured_vel, estimated_vel;
    for (int i = 0; i < total_time; ++i) {
        true_vel.push_back(true_values[i][1]);
        measured_vel.push_back(measurements[i][1]);
        estimated_vel.push_back(estimations[i][1]);
    }

    // Plot velocity using the same general plot function
    plot_data(time, true_vel, measured_vel, estimated_vel, "velocity");

    return 0;
}
