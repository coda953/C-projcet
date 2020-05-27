#ifndef CPPPROJECT_MATRIX_HPP
#define CPPPROJECT_MATRIX_HPP

#include <bits/stdc++.h>
#include "Vector.hpp"
#i
using namespace std;

template<class T>
class Vector;

template<class T>
class Matrix {
public:
    Matrix();

    vector<T> &operator[](int i);

    Matrix(int row, int column);

    Matrix(int length);

    Matrix(Matrix const &other);

    Matrix(Vector<T> other);

    T findMin();

    T findMinAtRow(int row);

    T findMinAtColumn(int column);

    T findMax();

    T findMaxAtRow(int row);

    T findMaxAtColumn(int column);

    T findAverage();

    T findAverageAtRow(int row);

    T findAverageAtColumn(int column);

    T findSum();

    T findSumAtRow(int row);

    T findSumAtColumn(int column);

    T cal_traces();

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

    Vector<T> slicing(int from, int to);

    Matrix operator+(const Matrix &other) const;

    Matrix operator+(Vector<T> other) const;

    Matrix operator-(const Matrix &other) const;

    Matrix operator-(Vector<T> other) const;

    Matrix operator*(const Matrix &other) const;

    Vector<T> operator*(Vector<T> other) const;

private:
    vector<vector<T>>>
    matrix;
    int row{}, column{};
};

#endif //CPPPROJECT_MATRIX_HPP
