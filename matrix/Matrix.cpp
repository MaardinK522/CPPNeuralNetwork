//
// Created by kamble on 07-01-2024.
//

#include <sstream>
#include "Matrix.h"
#include "iostream"
#include "random"

Matrix::Matrix() {
    this->rows = 0;
    this->cols = 0;
    this->data = nullptr;
}

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->data = new double *[this->rows];
    for (int a = 0; a < rows; ++a) {
        this->data[a] = new double[this->cols];
        for (int b = 0; b < cols; ++b)
            this->data[a][b] = 1;
    }
}

Matrix::Matrix(int rows, int cols, double **data) {
    this->rows = rows;
    this->cols = cols;
    this->data = new double *[rows];
    for (int a = 0; a < this->rows; ++a) {
        this->data[a] = new double[this->cols];
        for (int b = 0; b < this->cols; ++b)
            this->data[a][b] = data[a][b];
    }
}


void Matrix::printMatrix() const {
    std::cout << "Matrix rows: " << this->rows << " cols: " << this->cols << std::endl;
    for (int a = 0; a < this->rows; ++a) {
        for (int b = 0; b < this->cols; ++b)
            std::cout << this->data[a][b] << " ";
        std::cout << std::endl;
    }
}

Matrix Matrix::copy() const {
    Matrix matrix(this->rows, this->cols, this->data);
    return matrix;
}

Matrix Matrix::operator+(Matrix matrix) const {
    if (matrix.rows != this->rows || this->cols != matrix.cols)
        throw std::runtime_error("Mismatch matrix Size. Unable to perform addition.");
    Matrix result(this->rows, this->cols);
    for (int a = 0; a < this->rows; ++a)
        for (int b = 0; b < this->cols; ++b)
            result.setData(a, b, this->data[a][b] + matrix.data[a][b]);
    return result;
}

Matrix Matrix::operator-(Matrix matrix) const {
    if (matrix.rows != this->rows || this->cols != matrix.cols)
        throw std::runtime_error("Mismatch matrix Size. Unable to perform subtraction.");
    Matrix result(this->rows, this->cols);
    for (int a = 0; a < this->rows; ++a)
        for (int b = 0; b < this->cols; ++b)
            result.setData(a, b, this->data[a][b] - matrix.data[a][b]);
    return result;
}

Matrix Matrix::operator*(double scale) const {
    Matrix result(this->rows, this->cols);
    for (int a = 0; a < this->rows; ++a)
        for (int b = 0; b < this->cols; ++b)
            result.setData(a, b, this->data[a][b] * scale);
    return result;
}

Matrix Matrix::operator*(Matrix matrix) const {
    if (matrix.rows != this->rows || this->cols != matrix.cols)
        throw std::runtime_error("Mismatch matrix Size. Unable to perform element wise multiplication.");
    Matrix result(this->rows, this->cols);
    for (int a = 0; a < this->rows; ++a)
        for (int b = 0; b < this->cols; ++b)
            result.setData(a, b, this->data[a][b] + matrix.data[a][b]);
    return result;
}

Matrix Matrix::operator+=(Matrix matrix) {
    if (matrix.rows != this->rows || this->cols != matrix.cols)
        throw std::runtime_error("Mismatch matrix Size. Unable to perform addition.");
    for (int a = 0; a < this->rows; ++a)
        for (int b = 0; b < this->cols; ++b)
            this->setData(a, b, this->data[a][b] + matrix.data[a][b]);
    return *this;
}

void Matrix::randomize() const {
    // Initializing random generator.
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::normal_distribution<double> distribution(0.0, 0.1);

    // Storing random number to each index.
    for (int a = 0; a < rows; ++a)
        for (int b = 0; b < cols; ++b)
            this->data[a][b] = 0.5 * distribution(gen);
}

Matrix matrixMultiplication(Matrix matrix1, Matrix matrix2) {
    if (matrix1.getColumnCount() != matrix2.getRowCount()) {
        std::stringstream error;
        error << matrix1.getColumnCount() << " x " << matrix2.getRowCount()
              << " size mismatch for matrix multiplication.";
        throw std::runtime_error(error.str());
    }
    Matrix result(matrix1.getRowCount(), matrix2.getColumnCount());
    for (int a = 0; a < result.getRowCount(); ++a)
        for (int b = 0; b < result.getColumnCount(); ++b) {
            double sum = 0;
            for (int k = 0; k < matrix1.getColumnCount(); ++k)
                sum += matrix1.getData(a, k) * matrix2.getData(k, b);
            result.setData(a, b, sum);
        }
    return result;
}

Matrix transpose(Matrix matrix) {
    Matrix result(matrix.getColumnCount(), matrix.getRowCount());
    for (int a = 0; a < result.getRowCount(); ++a)
        for (int b = 0; b < result.getColumnCount(); ++b)
            result.setData(a, b, matrix.getData(b, a));
    return result;
}

void Matrix::setData(int row, int col, double value) const {
    this->data[row][col] = value;
}

double Matrix::getData(int row, int col) const {
    return this->data[row][col];
}

int Matrix::getColumnCount() const {
    return this->cols;
}

int Matrix::getRowCount() const {
    return this->rows;
}


double *Matrix::getColumn(int columnIndex) const {
    auto *column = new double[this->cols];
    for (int a = 0; a < this->cols; ++a) {
        column[a] = this->getData(a, columnIndex);
    }
    return column;
}

void Matrix::mapMatrix(const MapAble &equation) const {
    for (int a = 0; a < this->getRowCount(); ++a)
        for (int b = 0; b < this->getColumnCount(); ++b)
            this->setData(a, b, equation(this->getData(b, a)));
}
