
#ifndef CPPPROJECT_VECTOR_HPP
#define CPPPROJECT_VECTOR_HPP

#include <bits/stdc++.h>

using namespace std;

class Vector {
public:
    Vector();

    Vector(int length);

    complex<double> &operator[](int i);

    double findMin();

    double findMax();

    complex<double> findAverage();

    complex<double> findSum();

    void setLength(int length);

    Vector operator+(const Vector &other) const;

    Vector operator-(const Vector &other) const;

private:
    vector<complex<double>> vector;
    int length;
};

#endif //CPPPROJECT_VECTOR_HPP
