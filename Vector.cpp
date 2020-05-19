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

Vector Vector::operator*(complex<double> other) const {
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        ans[i] = this->vector[i] * other;
    }
    return ans;
}

Vector operator*(complex<double> l, Vector &other) {
    Vector ans = Vector(other.getLength());
    for (int i = 0; i < other.getLength(); ++i) {
        ans[i] = l * other[i];
    }
    return ans;
}

Vector Vector::operator/(complex<double> other) const {
    if (other.real() == 0 && other.imag() == 0) {
        cout << other << "can not be divisor" << endl;
        return Vector(0);
    }
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        ans[i] = this->vector[i] / other;
    }
    return ans;
}

Vector operator/(complex<double> l, Vector &other) {
    if (l.real() == 0 && l.imag() == 0) {
        cout << l << "can not be divisor" << endl;
        return Vector(0);
    }
    Vector ans = Vector(other.getLength());
    for (int i = 0; i < other.getLength(); ++i) {
        ans[i] = l / other[i];
    }
    return ans;
}

Vector Vector::element_wise_multiplication(Vector &other) {
    if (this->length != other.length) {
        cout << "element_wise_multiplication error!" << endl;
        cout << "the size of two vector is not equal" << endl;
        return Vector(0);
    }
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        ans[i] = this->vector[i] * other.vector[i];
    }
    this->vector = ans.vector;
    return ans;
}

Vector Vector::conjugation() {
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        complex<double> cur(this->vector[i].real(), -this->vector[i].imag());
        ans[i] = cur;
    }
    this->vector = ans.vector;
    return ans;
}

Vector Vector::operator*(Matrix other) const {
    if (this->length != other.getRow()) {
        cout << "Vector * Matrix error!" << endl;
        cout << "Vector length is not equal Matrix row" << endl;
        return Vector(0);
    }
    Vector ans = Vector(other.getColumn());
    for (int i = 0; i < other.getColumn(); ++i) {
        for (int j = 0; j < this->length; ++j) {
            ans[i] += this->vector[j] * other[j][i];
        }
    }
    return ans;
}

complex<double> Vector::dot_product(Vector other) {
    complex<double> ans(0, 0);
    if (this->length != other.length) {
        cout << "dot product error!" << endl;
        cout << "the two vector length is not equal" << endl;
        return ans;
    }
    for (int i = 0; i < this->length; ++i) {
        ans += this->vector[i] * other.vector[i];
    }
    return ans;
}





