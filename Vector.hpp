
#ifndef CPPPROJECT_VECTOR_HPP
#define CPPPROJECT_VECTOR_HPP

#include <bits/stdc++.h>
#include "Matrix.hpp"

using namespace std;
class Matrix;

class Vector {
public:
    Vector();

    Vector(int length);

    int getLength();
    void show();
    complex<double> &operator[](int i);

    double findMin();

    double findMax();

    complex<double> findAverage();

    complex<double> findSum();

    void setLength(int length);

    complex<double> dot_product(Vector other);

    Vector conjugation();

    Vector element_wise_multiplication(Vector &other);

    Vector operator+(const Vector &other) const;

    Matrix operator+(Matrix other) const;

    Vector operator-(const Vector &other) const;

    Matrix operator-(Matrix other) const;

    Vector operator*(complex<double> other) const;

    Vector operator*(Matrix other) const;

    friend Vector operator*(complex<double> l, Vector &other);

    Vector operator/(complex<double> other) const;

    friend Vector operator/(complex<double> l, Vector &other);

private:
    vector<complex<double>> vector;
    int length;
};

#endif //CPPPROJECT_VECTOR_HPP
