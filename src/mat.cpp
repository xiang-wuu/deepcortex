#include "mat.h"

Matrix::Matrix(size_t rows, size_t cols) : data(rows * cols), rows(rows), cols(cols) {}

double &Matrix::operator()(size_t row, size_t col)
{
    return data.at(row * cols + col);
}

const double &Matrix::operator()(size_t row, size_t col) const
{
    return data.at(row * cols + col);
}

Matrix Matrix::transpose() const
{
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

Matrix Matrix::inverse() const
{
    // This is a placeholder for the inverse method.
    // For a 2x2 Matrixrix, the inverse can be calculated as follows:
    if (rows == 2 && cols == 2)
    {
        double det = (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
        if (std::abs(det) < 1e-9)
        {
            throw std::runtime_error("Matrixrix is singular and cannot be inverted");
        }
        Matrix inv(2, 2);
        inv(0, 0) = (*this)(1, 1) / det;
        inv(0, 1) = -(*this)(0, 1) / det;
        inv(1, 0) = -(*this)(1, 0) / det;
        inv(1, 1) = (*this)(0, 0) / det;
        return inv;
    }
    else
    {
        // For larger Matrixrices, you would need to implement a more general inversion method.
        throw std::runtime_error("Matrixrix inversion not implemented for this size");
    }
}

Matrix Matrix::operator+(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrixrix dimensions must Matrixch for addition");
    }
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows * cols; ++i)
    {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    if (rows != other.rows || cols != other.cols)
    {
        throw std::invalid_argument("Matrixrix dimensions must Matrixch for subtraction");
    }
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows * cols; ++i)
    {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    if (cols != other.rows)
    {
        throw std::invalid_argument("Matrixrix dimensions must be compatible for multiplication");
    }
    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < other.cols; ++j)
        {
            for (size_t k = 0; k < cols; ++k)
            {
                result(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }
    return result;
}

void Matrix::print() const
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            std::cout << (*this)(i, j) << ' ';
        }
        std::cout << std::endl;
    }
}

// Example usage: