#pragma once
#include <chrono>

using Duration = std::chrono::duration<double, std::milli>;

/**
 * Stores the measured build and query durations for one experiment.
 */
struct ExperimentResult {
    Duration buildTime;
    Duration kdTime;
    Duration bruteTime;
};

/**
 * Generates a dataset and compares K-D tree and brute-force query timings.
 *
 * @param k Number of dimensions for each point
 * @param numPoints Number of points in the generated dataset
 * @return Measured tree-build, K-D tree-query, and brute-force-query durations
 */
ExperimentResult runExperiment(int k, int numPoints);
