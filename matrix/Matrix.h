//
// Created by kamble on 07-01-2024.
//

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H


#include "../network/MapAble.h"

class Matrix {
private:
    int rows, cols;
    double **data;
public:

    Matrix(int row, int cols);

    Matrix(int rows, int cols, double **data);

    Matrix operator+(Matrix matrix) const;

    Matrix operator-(Matrix matrix) const;

    Matrix operator*(double scale) const;

    Matrix operator*(Matrix matrix) const;

    Matrix operator+=(Matrix matrix);

    void randomize() const;

    void setData(int row, int col, double value) const;

    double getData(int row, int col) const;

    void printMatrix() const;

    Matrix copy() const;

    int getRowCount() const;

    int getColumnCount() const;

    Matrix();

    double *getColumn(int columnIndex) const;

    void mapMatrix(const MapAble &equation) const;
};

Matrix matrixMultiplication(Matrix matrix1, Matrix matrix2);

Matrix transpose(Matrix matrix);

#endif //UNTITLED_MATRIX_H
