#ifndef CPPPROJECT_MATRIX_HPP
#define CPPPROJECT_MATRIX_HPP

#include <bits/stdc++.h>

using namespace std;

class Matrix {
public:
    Matrix();

    vector<complex<double>> &operator[](int i);

    Matrix(int row, int column);

    Matrix(int length);

    double findMin();

    double findMinAtRow(int row);

    double findMinAtColumn(int column);

    double findMax();

    double findMaxAtRow(int row);

    double findMaxAtColumn(int column);

    complex<double> findAverage();

    complex<double> findAverageAtRow(int row);

    complex<double> findAverageAtColumn(int column);

    complex<double> findSum();

    complex<double> findSumAtRow(int row);

    complex<double> findSumAtColumn(int column);

    void show() const;

    void showSize() const;

    int setRow(int row);

    int setColumn(int column);

    Matrix operator+(const Matrix &other) const;

    Matrix operator-(const Matrix &other) const;

    Matrix operator*(const Matrix &other) const;

private:
    vector<vector<complex<double>>> matrix;
    int row, column;
};

#endif //CPPPROJECT_MATRIX_HPP
