
#ifndef CPPPROJECT_VECTOR_HPP
#define CPPPROJECT_VECTOR_HPP

#include <bits/stdc++.h>
#include "Matrix.hpp"

using namespace std;

template<class T>
class Matrix;

template<class T>
class Vector {
public:
    Vector();

    Vector(int length);

    int getLength();

    void show();

    T &operator[](int i);

    double findMin();

    double findMax();

    T findAverage();

    T findSum();

    void setLength(int length);

    T dot_product(Vector other);

    Vector conjugation();

    Vector conjugation_change();

    Vector element_wise_multiplication(Vector &other);

    Vector element_wise_multiplication_change(Vector &other);

    Vector operator+(const Vector &other) const;

    Matrix<T> operator+(Matrix<T> other) const;

    Vector operator-(const Vector &other) const;

    Matrix<T> operator-(Matrix<T> other) const;

    Vector operator*(T other) const;

    Vector operator*(Matrix<T> other) const;


    Vector operator/(T other) const;


private:
    vector <T> vector;
    int length{};
};

#endif //CPPPROJECT_VECTOR_HPP
