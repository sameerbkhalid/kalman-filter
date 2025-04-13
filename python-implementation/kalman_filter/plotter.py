import matplotlib.pyplot as plt
from typing import List

def plot_data(
    time: List[float],
    true_data: List[float],
    measured_data: List[float],
    estimated_data: List[float],
    data_type: str,  # 'displacement' or 'velocity'
):
    """
    A general function to plot true, measured, and estimated data for displacement or velocity.
    Arguments:
        time: List of time steps.
        true_data: True data values.
        measured_data: Measured data values.
        estimated_data: Estimated data values.
        data_type: Type of data to plot ('displacement' or 'velocity').
    """
    # Set titles and labels based on the data type
    if data_type == 'displacement':
        title = "Displacement: True vs Measured vs Estimated"
        true_label = "True Displacement"
        measured_label = "Measured Displacement"
        estimated_label = "Estimated Displacement"
    elif data_type == 'velocity':
        title = "Velocity: True vs Measured vs Estimated"
        true_label = "True Velocity"
        measured_label = "Measured Velocity"
        estimated_label = "Estimated Velocity"
    else:
        raise ValueError("Invalid data_type. Choose 'displacement' or 'velocity'.")
    
    # Plot the data
    plt.figure()
    plt.plot(time, true_data, 'r--', label=true_label)
    plt.plot(time, measured_data, 'b--', label=measured_label)
    plt.plot(time, estimated_data, 'g', label=estimated_label)
    plt.title(title)
    plt.legend()
    plt.grid(True)

    # Automatically generate the save name based on the data type
    save_name = f"results/{data_type}_plot.png"
    plt.savefig(save_name)
    plt.show()
