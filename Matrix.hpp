#ifndef CPPPROJECT_MATRIX_HPP
#define CPPPROJECT_MATRIX_HPP

#include <bits/stdc++.h>

using namespace std;

class Matrix {
public:
    Matrix();
    vector<complex<double>> &operator[](int i);
    Matrix(int row, int column);
    void show() const;
    void showSize()const ;
    int setRow(int input);
    int setColumn(int input);
    Matrix operator+(const Matrix& other)const ;
    Matrix operator-(const Matrix& other)const ;
    Matrix operator*(const Matrix& other)const ;
private:
    vector<vector<complex<double>>> matrix;
    int row, column;
};

#endif //CPPPROJECT_MATRIX_HPP
