#include "Benchmark.hpp"
#include "KDTree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

/**
 * Runs benchmark experiments across several dimensions and dataset sizes.
 *
 * Writes timing results to a CSV file and prints them to the console.
 *
 * @return 0 when all experiments finish successfully
 */
int main() {
    // test printing
    std::vector<Point> testPoints = {{2, 3}, {5, 4}, {9, 6}};
    KDTree testTree(testPoints);
    testTree.print();
    // test different dimensions and dataset sizes
    std::vector<int> dimensions = {2, 3, 5, 10, 20};
    std::vector<int> numPoints = {10, 100, 1000, 10000};
    // save experiment results to csv
    std::ofstream file("results/experiment_results.csv");
    file << "k,numPoints,buildMs,kdQueryMs,bruteMs\n";
    std::cout << std::fixed << std::setprecision(4);
    file << std::fixed << std::setprecision(4);
    for (int k : dimensions) {
        for (int n : numPoints) {
            ExperimentResult result = runExperiment(k, n);
            double build = result.buildTime.count();
            double kd = result.kdTime.count();
            double brute = result.bruteTime.count();
            // print results
            std::cout << "k=" << k
                      << " n=" << n
                      << " build=" << build << "ms"
                      << " kd=" << kd << "ms"
                      << " brute=" << brute << "ms"
                      << std::endl;
            // write results to csv
            file << k << ","
                 << n << ","
                 << build << ","
                 << kd << ","
                 << brute << "\n";
        }
    }
    file.close();
    return 0;
}
