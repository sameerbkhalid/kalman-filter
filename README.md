# Kalman Filter Implementation (C++ & Python)

This project contains a basic Kalman Filter implementation in both **C++** and **Python**. The C++ version uses the **Eigen** library for matrix operations, while the Python version uses **NumPy**. Both implementations use **Matplotlib** to visualize the estimated and measured states.

---

## 📖 What is a Kalman Filter?

The **Kalman Filter** is an optimal recursive algorithm used to estimate the state of a dynamic system from a series of noisy measurements. It's widely applied in control systems, robotics, navigation, and time-series analysis.

In this project, we implement a **1D constant velocity model** where the goal is to estimate both **position** and **velocity** based on noisy position measurements. The filter assumes Gaussian noise for both process and measurement uncertainties.

---

## 🔄 Workflow

1. Generate synthetic noisy position data.
2. Apply the Kalman Filter to estimate position and velocity.
3. Visualize the results and save plots.

The workflow is consistent across both implementations.

---

## ⚙️ Prerequisites

### C++ Version

Ensure the following tools and libraries are installed:

- **C++17 compatible compiler** (e.g., `g++ >= 7`)
- **CMake** (version ≥ 3.10)

To install on Ubuntu:

```bash
sudo apt update
sudo apt install build-essential cmake
```

- **Eigen** – Header-only library for linear algebra

To install Eigen:

```bash
sudo apt install libeigen3-dev
```

- **matplotlib-cpp** – C++ wrapper for Python’s matplotlib (requires Python with matplotlib)

Clone and set up matplotlib-cpp:

```bash
cd cpp-implementation
git clone https://github.com/lava/matplotlib-cpp.git
```

Make sure Python and matplotlib are installed:

```bash
pip install matplotlib
```

### Python Version

- Python 3.x
- Install dependencies with:

```bash
cd python-implementation
pip install -r requirements.txt
```

---

## 🚀 How to Run

### C++ Version

```bash
cd cpp-implementation
mkdir build && cd build
cmake ..
make
./kalman_filter
```

### Python Version

```bash
cd python-implementation
python main.py
```

---

## 📊 Output

Both implementations generate:
- `displacement_plot.png`: True vs Measured vs Estimated displacement
- `velocity_plot.png`: True vs Measured vs Estimated velocity

Plots are saved inside their respective `results/` folders.

---

## 📄 License

This project is licensed under the MIT License. You are free to use, modify, and distribute this code for educational and personal use. For more information, see the [LICENSE](LICENSE) file.
