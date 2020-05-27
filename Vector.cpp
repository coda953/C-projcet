//
// Created by 10505 on 2020/5/14.
//

#include "Vector.hpp"

template<class T>
class Matrix;

template<class T>
Vector<T>::Vector() {
    this->length = 0;
    this->vector.resize(length);
}

template<class T>
Vector<T>::Vector(int length) {
    this->length = length;
    this->vector.resize(length);
}

template<class T>
double Vector<T>::findMin() {
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

template<class T>
double Vector<T>::findMax() {
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

template<class T>
T Vector<T>::findAverage() {
    T ans = findSum();
    ans /= this->length;
    return ans;
}

template<class T>
T Vector<T>::findSum() {
    if (this->length == 0) {
        cout << "The Vector is empty,can not get sum" << endl;
        return {0, 0};
    }
    T ans = {0, 0};
    for (int i = 0; i < this->length; ++i) {
        ans += this->vector[i];
    }
    return ans;
}

template<class T>
void Vector<T>::setLength(int length) {
    this->length = length;
    this->vector.resize(length);
}

template<class T>
T &Vector<T>::operator[](int i) {
    return this->vector[i];
}

template<class T>
Vector<T> Vector<T>::operator+(const Vector &other) const {
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

template<class T>
Vector<T> Vector<T>::operator-(const Vector &other) const {
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

template<class T>
int Vector<T>::getLength() {
    return this->length;
}

template<class T>
Matrix<T> Vector<T>::operator+(Matrix<T> other) const {
    if (this->length != other.getColumn()) {
        cout << "The column of the matrix is not equal to the vector length" << endl;
        return Matrix<T>(0, 0);
    }
    Matrix<T> ans = Matrix<T>(other.getRow(), other.getColumn());
    for (int i = 0; i < other.getRow(); ++i) {
        for (int j = 0; j < other.getColumn(); ++j) {
            ans[i][j] = other[i][j] + this->vector[j];
        }
    }
    return ans;
}

template<class T>
Matrix<T> Vector<T>::operator-(Matrix<T> other) const {
    if (this->length != other.getColumn()) {
        cout << "The column of the matrix is not equal to the vector length" << endl;
        return Matrix<T>(0, 0);
    }
    Matrix<T> ans = Matrix<T>(other.getRow(), other.getColumn());
    for (int i = 0; i < other.getRow(); ++i) {
        for (int j = 0; j < other.getColumn(); ++j) {
            ans[i][j] = other[i][j] - this->vector[j];
        }
    }
    return ans;
}

template<class T>
Vector<T> Vector<T>::operator*(T other) const {
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        ans[i] = this->vector[i] * other;
    }
    return ans;
}

template<class T>
Vector<T> operator*(T l, Vector<T> &other) {
    Vector<T> ans = Vector<T>(other.getLength());
    for (int i = 0; i < other.getLength(); ++i) {
        ans[i] = l * other[i];
    }
    return ans;
}

template<class T>
Vector<T> Vector<T>::operator/(T other) const {
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

template<class T>
Vector<T> operator/(T l, Vector<T> &other) {
    if (l.real() == 0 && l.imag() == 0) {
        cout << l << "can not be divisor" << endl;
        return Vector<T>(0);
    }
    Vector<T> ans = Vector<T>(other.getLength());
    for (int i = 0; i < other.getLength(); ++i) {
        ans[i] = l / other[i];
    }
    return ans;
}

template<class T>
Vector<T> Vector<T>::element_wise_multiplication_change(Vector &other) {
    if (this->length != other.length) {
        cout << "element_wise_multiplication_change error!" << endl;
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

template<class T>
Vector<T> Vector<T>::conjugation_change() {
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        T cur(this->vector[i].real(), -this->vector[i].imag());
        ans[i] = cur;
    }
    this->vector = ans.vector;
    return ans;
}

template<class T>
Vector<T> Vector<T>::operator*(Matrix<T> other) const {
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

template<class T>
T Vector<T>::dot_product(Vector other) {
    T ans(0, 0);
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

template<class T>
void Vector<T>::show() {
    cout << "Length:" << this->length << endl;
    cout << "[";
    for (int i = 0; i < this->length; ++i) {
        cout << this->vector[i];
        if (i == this->length - 1) {
            cout << "]";
        } else {
            cout << ",";
        }
    }
}

template<class T>
Vector<T> Vector<T>::conjugation() {
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        T cur(this->vector[i].real(), -this->vector[i].imag());
        ans[i] = cur;
    }
    return ans;
}

template<class T>
Vector<T> Vector<T>::element_wise_multiplication(Vector &other) {
    if (this->length != other.length) {
        cout << "element_wise_multiplication_change error!" << endl;
        cout << "the size of two vector is not equal" << endl;
        return Vector(0);
    }
    Vector ans = Vector(this->length);
    for (int i = 0; i < this->length; ++i) {
        ans[i] = this->vector[i] * other.vector[i];
    }
    return ans;
}





