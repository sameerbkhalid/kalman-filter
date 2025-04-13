
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(KalmanFilterCPP VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Eigen
find_package(Eigen3 3.3 REQUIRED)

# Find Python3 for matplotlib-cpp
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

# Add include directories
include_directories(
    ${EIGEN3_INCLUDE_DIRS}
    ${Python3_INCLUDE_DIRS}
    ${Python3_NumPy_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
    /home/sameer/Documents/matplotlib-cpp
)

# Add source files
set(SOURCES
    src/main.cpp
    src/kalman_filter.cpp
    src/plotter.cpp
)

# Add the executable
add_executable(KalmanFilterCPP 
    src/main.cpp
    src/kalman_filter.cpp
    src/data_generation.cpp
    src/plotter.cpp
)

# Link libraries
target_link_libraries(KalmanFilterCPP
    Eigen3::Eigen
    ${Python3_LIBRARIES}
)
