#ifndef PLOTTER_HPP_
#define PLOTTER_HPP_

#include <vector>
#include <string>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

// Function to plot the data for displacement or velocity
void plot_data(
    const std::vector<double>& time,
    const std::vector<double>& true_data,
    const std::vector<double>& measured_data,
    const std::vector<double>& estimated_data,
    const std::string& data_type
);

#endif  // PLOTTER_HPP_
