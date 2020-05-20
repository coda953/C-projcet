#ifndef CPPPROJECT_MATRIX_HPP
#define CPPPROJECT_MATRIX_HPP

#include <bits/stdc++.h>
#include "Vector.hpp"

using namespace std;

class Vector;

class Matrix {
public:
    Matrix();

    vector<complex<double>> &operator[](int i);

    Matrix(int row, int column);

    Matrix(int length);

    Matrix(Matrix const &other);

    Matrix(Vector other);

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

    complex<double> cal_traces();

    void show() const;

    void showSize() const;

    int setRow(int row);

    int getRow();

    int setColumn(int column);

    int getColumn();

    Matrix transposition();

    Matrix transposition_change();

    Matrix conjugation();

    Matrix conjugation_change();

    Matrix element_wise_multiplication(Matrix &other);

    Matrix element_wise_multiplication_change(Matrix &other);

    Matrix reshape(int row, int column);

    Matrix reshape_change(int row, int column);

    Vector slicing(int from, int to);

    Matrix operator+(const Matrix &other) const;

    Matrix operator+(Vector other) const;

    Matrix operator-(const Matrix &other) const;

    Matrix operator-(Vector other) const;

    Matrix operator*(const Matrix &other) const;

    Vector operator*(Vector other) const;

private:
    vector<vector<complex<double>>> matrix;
    int row, column;
};

#endif //CPPPROJECT_MATRIX_HPP
