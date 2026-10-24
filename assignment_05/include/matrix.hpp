
#pragma once

#include <vector>
#include <optional>
#include <cstddef>
#include <stdexcept>

/** Represents a square matrix of double values. */
class Matrix {
public:
    // create nxn matrix init to 0s
    Matrix(std::size_t size) : size_(size) {
        matrix_.resize(size);
        for (auto& row : matrix_) {
            row.resize(size, 0);
        }
    }

    // get val at row and col
    double get(std::size_t row, std::size_t col) const {
        return matrix_.at(row).at(col);
    }

    // set val at row and col
    void set(std::size_t row, std::size_t col, double val) {
        matrix_.at(row).at(col) = val;
    }

    /**
     * Splits this matrix into four quadrants in top-left, top-right,
     * bottom-left, bottom-right order. For odd-sized matrices, the final
     * row and column are omitted.
     */
    std::vector<Matrix> split() const {
        std::size_t n = size_ / 2;
        std::vector<Matrix> res(4, Matrix(n));
        for (std::size_t r = 0; r < n; r++) {
            for (std::size_t c = 0; c < n; c++) {
                res.at(0).set(r,c,get(r,c));
                res.at(1).set(r,c,get(r,c + n));
                res.at(2).set(r,c,get(r + n,c));
                res.at(3).set(r,c,get(r + n,c + n));
            }
        }
        return res;
    }

    /**
     * Adds this matrix to another matrix of the same size.
     *
     * Uses element-wise addition. If the dimensions do not match,
     * throws std::invalid_argument.
     */
    Matrix add(const Matrix& other) const {
        if (size_ != other.size_) {
            throw std::invalid_argument("dimensions don't match");
        }
        auto res = Matrix(size_);
        for (std::size_t r = 0; r < size_; r++) {
            for (std::size_t c = 0; c < size_; c++) {
                auto sum = get(r,c) + other.get(r,c);
                res.set(r,c,sum);
            }
        }
        return res;
    }

    /**
     * Subtracts another matrix from this matrix.
     *
     * Uses element-wise subtraction. If the dimensions do not match,
     * throws std::invalid_argument.
     */
    Matrix subtract(const Matrix& other) const {
        if (size_ != other.size_) {
            throw std::invalid_argument("dimensions don't match");
        }
        auto res = Matrix(size_);
        for (std::size_t r = 0; r < size_; r++) {
            for (std::size_t c = 0; c < size_; c++) {
                auto sum = get(r,c) - other.get(r,c);
                res.set(r,c,sum);
            }
        }
        return res;
    }

    /**
     * Multiplies this matrix by another matrix of the same size.
     *
     * Uses the standard O(n^3) approach. If the dimensions do not match,
     * returns std::nullopt.
     */
    std::optional<Matrix> multiply(const Matrix& other) const {
        if (size_ != other.size_) {
            return std::nullopt;
        }
        auto res = Matrix(size_);
        for (std::size_t r = 0; r < size_; r++) {
            for (std::size_t c = 0; c < size_; c++) {
                for (std::size_t k = 0; k < size_; k++) {
                    auto mult = get(r,k) * other.get(k,c);
                    auto cur = res.get(r,c);
                    res.set(r,c,mult + cur);
                }
            }
        }
        return res;
    }

    /**
     * Multiplies this matrix by another matrix of the same size using the
     * Strassen algorithm.
     *
     * Uses seven recursive products and falls back to the standard O(n^3)
     * approach when the matrix is odd-sized or below the threshold. If the
     * dimensions do not match, returns std::nullopt.
     */
    std::optional<Matrix> strassenMultiply(const Matrix& other, std::size_t threshold = 1) const {
        if (size_ != other.size_) {
            return std::nullopt;
        }
        // base case for 1x1 matrix
        if (size_ == 1) {
            auto res = Matrix(size_);
            res.set(0,0,get(0,0) * other.get(0,0));
            return res;
        }
        // use traditional multiplication for odd or small matrices
        if (size_ == 0 || size_ % 2 != 0 || size_ <= threshold) {
            return multiply(other);
        }

        auto res = Matrix(size_);
        // split both matrices into quadrants
        auto m1 = split();
        auto m2 = other.split();

        auto a11 = m1.at(0);
        auto a12 = m1.at(1);
        auto a21 = m1.at(2);
        auto a22 = m1.at(3);
        auto b11 = m2.at(0);
        auto b12 = m2.at(1);
        auto b21 = m2.at(2);
        auto b22 = m2.at(3);

        // calculate the 7 strassen products
        auto p1 = (a11.add(a22)).strassenMultiply(b11.add(b22), threshold).value();
        auto p2 = (a21.add(a22)).strassenMultiply(b11, threshold).value();
        auto p3 = a11.strassenMultiply(b12.subtract(b22), threshold).value();
        auto p4 = a22.strassenMultiply(b21.subtract(b11), threshold).value();
        auto p5 = (a11.add(a12)).strassenMultiply(b22, threshold).value();
        auto p6 = (a21.subtract(a11)).strassenMultiply(b11.add(b12), threshold).value();
        auto p7 = (a12.subtract(a22)).strassenMultiply(b21.add(b22), threshold).value();

        // combine products to get result quadrants
        auto c11 = p1.add(p4).subtract(p5).add(p7);
        auto c12 = p3.add(p5);
        auto c21 = p2.add(p4);
        auto c22 = p1.subtract(p2).add(p3).add(p6);

        // copy quadrants back into result matrix
        std::size_t n = size_ / 2;
        for (std::size_t r = 0; r < n; r++) {
            for (std::size_t c = 0; c < n; c++) {
                res.set(r, c, c11.get(r, c));
                res.set(r, c + n, c12.get(r, c));
                res.set(r + n, c, c21.get(r, c));
                res.set(r + n, c + n, c22.get(r, c));
            }
        }
        return res;
    }

private:
    std::vector<std::vector<double>> matrix_;
    std::size_t size_;
};
