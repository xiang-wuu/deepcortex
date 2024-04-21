// Matrixrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<double> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols);
    double& operator()(size_t row, size_t col);
    const double& operator()(size_t row, size_t col) const;
    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    std::vector<double> operator*(const std::vector<double>& vec) const;
    Matrix transpose() const;
    Matrix inverse() const;
    void print() const;
};

#endif // MATRIX_H