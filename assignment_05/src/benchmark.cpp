#include <iostream>
#include <chrono>
#include "matrix.hpp"

int main() {
    std::cout << "Size\tMethod\t\tTime(ms)\n";
    for (int n : {64, 128, 256, 512}) {
        Matrix a(n), b(n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                a.set(r, c, r + c + 1);
                b.set(r, c, r - c + 1);
            }
        }
        double tradTime = 0;
        for (int i = 0; i < 10; i++) {
            auto start = std::chrono::steady_clock::now();
            auto res = a.multiply(b);
            auto end = std::chrono::steady_clock::now();
            tradTime += std::chrono::duration<double, std::milli>(end - start).count();
        }
        std::cout << n << "\tTraditional\t" << tradTime / 10 << "\n";
        for (std::size_t threshold : {32, 64, 128}) {
            double strassenTime = 0;
            for (int i = 0; i < 10; i++) {
                auto start = std::chrono::steady_clock::now();
                auto res = a.strassenMultiply(b, threshold);
                auto end = std::chrono::steady_clock::now();
                strassenTime += std::chrono::duration<double, std::milli>(end - start).count();
            }
            std::cout << n << "\tThreshold " << threshold << "\t" << strassenTime / 10 << "\n";
        }
    }
    return 0;
}
