
#ifndef CPPPROJECT_VECTOR_HPP
#define CPPPROJECT_VECTOR_HPP

#include <bits/stdc++.h>
#include "Matrix.hpp"

using namespace std;

class Vector {
public:
    Vector();

    Vector(int length);

    int getLength();

    complex<double> &operator[](int i);

    double findMin();

    double findMax();

    complex<double> findAverage();

    complex<double> findSum();

    void setLength(int length);

    Vector operator+(const Vector &other) const;

    Matrix operator+(Matrix other) const;

    Vector operator-(const Vector &other) const;

    Matrix operator-(Matrix other) const;

private:
    vector<complex<double>> vector;
    int length;
};

#endif //CPPPROJECT_VECTOR_HPP
