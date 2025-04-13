#include "plotter.hpp"

namespace plt = matplotlibcpp;

void plot_data(
    const std::vector<double>& time,
    const std::vector<double>& true_data,
    const std::vector<double>& measured_data,
    const std::vector<double>& estimated_data,
    const std::string& data_type
) {
    std::string title, true_label, measured_label, estimated_label, save_name;

    if (data_type == "displacement") {
        title = "Displacement: True vs Measured vs Estimated";
        true_label = "True Displacement";
        measured_label = "Measured Displacement";
        estimated_label = "Estimated Displacement";
        save_name = "displacement_plot.png";
    } else if (data_type == "velocity") {
        title = "Velocity: True vs Measured vs Estimated";
        true_label = "True Velocity";
        measured_label = "Measured Velocity";
        estimated_label = "Estimated Velocity";
        save_name = "velocity_plot.png";
    } else {
        throw std::invalid_argument("Invalid data_type. Choose 'displacement' or 'velocity'.");
    }
    
    // Plot the data
    plt::named_plot(true_label, time, true_data, "r--");
    plt::named_plot(measured_label, time, measured_data, "b--");
    plt::named_plot(estimated_label, time, estimated_data, "g");
    plt::title(title);
    plt::legend();

    // Save the plot
    std::string full_save_path = "../results/" + save_name;
    plt::save(full_save_path);
    plt::show();
}
