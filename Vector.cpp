//
// Created by 10505 on 2020/5/14.
//

#include "Vector.hpp"

Vector::Vector(int length) {
    this->length = length;
    this->vector.resize(length);
}

Vector::Vector() {
    this->length = 0;
    this->vector.resize(length);
}

double Vector::findMin() {
    if (this->length == 0) {
        cout << "The vector is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->vector[0].real();
    for (int i = 0; i < length; ++i) {
        ans = min(ans, this->vector[i].real());
    }
    return ans;
}

double Vector::findMax() {
    if (this->length == 0) {
        cout << "The vector is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->vector[0].real();
    for (int i = 0; i < length; ++i) {
        ans = max(ans, this->vector[i].real());
    }
    return ans;
}

complex<double> Vector::findAverage() {
    complex<double> ans = findSum();
    ans /= this->length;
    return ans;
}

complex<double> Vector::findSum() {
    if (this->length == 0) {
        cout << "The Vector is empty,can not get sum" << endl;
        return {0, 0};
    }
    complex<double> ans = {0, 0};
    for (int i = 0; i < this->length; ++i) {
        ans += this->vector[i];
    }
    return ans;
}

void Vector::setLength(int length) {
    this->length = length;
    this->vector.resize(length);
}

complex<double> &Vector::operator[](int i) {
    return this->vector[i];
}

Vector Vector::operator+(const Vector &other) const {
    if (this->length != other.length) {
        cout << "The length of two vector is not equal" << endl;
        return Vector(0);
    }
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        ans[i] = this->vector[i] + other.vector[i];
    }
    return ans;
}

Vector Vector::operator-(const Vector &other) const {
    if (this->length != other.length) {
        cout << "The length of two vector is not equal" << endl;
        return Vector(0);
    }
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        ans[i] = this->vector[i] - other.vector[i];
    }
    return ans;
}

int Vector::getLength() {
    return this->length;
}

Matrix Vector::operator+(Matrix other) const {
    if (this->length != other.getColumn()) {
        cout << "The column of the matrix is not equal to the vector length" << endl;
        return Matrix(0, 0);
    }
    Matrix ans = Matrix(other.getRow(), other.getColumn());
    for (int i = 0; i < other.getRow(); ++i) {
        for (int j = 0; j < other.getColumn(); ++j) {
            ans[i][j] = other[i][j] + this->vector[j];
        }
    }
    return ans;
}

Matrix Vector::operator-(Matrix other) const {
    if (this->length != other.getColumn()) {
        cout << "The column of the matrix is not equal to the vector length" << endl;
        return Matrix(0, 0);
    }
    Matrix ans = Matrix(other.getRow(), other.getColumn());
    for (int i = 0; i < other.getRow(); ++i) {
        for (int j = 0; j < other.getColumn(); ++j) {
            ans[i][j] = other[i][j] - this->vector[j];
        }
    }
    return ans;
}




