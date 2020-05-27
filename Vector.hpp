
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
    Vector() {
        this->length = 0;
        this->vector.resize(length);
    }

    Vector(int length) {
        this->length = length;
        this->vector.resize(length);
    }

    int getLength() {
        return this->length;

    }

    void show() {
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

    T &operator[](int i) {
        return this->vector[i];

    }

    double findMin() {
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

    double findMax() {
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

    T findAverage() {
        T ans = findSum();
        ans /= this->length;
        return ans;
    }

    T findSum() {
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

    void setLength(int length) {
        this->length = length;
        this->vector.resize(length);
    }

    T dot_product(Vector other) {
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

    Vector conjugation() {
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            T cur(this->vector[i].real(), -this->vector[i].imag());
            ans[i] = cur;
        }
        return ans;
    }

    Vector conjugation_change() {
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            T cur(this->vector[i].real(), -this->vector[i].imag());
            ans[i] = cur;
        }
        this->vector = ans.vector;
        return ans;
    }

    Vector element_wise_multiplication(Vector &other) {
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

    Vector element_wise_multiplication_change(Vector &other) {
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

    Vector operator+(const Vector &other) const {
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

    Matrix<T> operator+(Matrix<T> other) const {
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

    Vector operator-(const Vector &other) const {
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

    Matrix<T> operator-(Matrix<T> other) const {
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

    Vector operator*(T other) const {
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            ans[i] = this->vector[i] * other;
        }
        return ans;
    }

    Vector operator*(Matrix<T> other) const {
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


private:
    vector<T> vector;
    int length{};
};

#endif //CPPPROJECT_VECTOR_HPP
