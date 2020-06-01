
#ifndef CPPPROJECT_VECTOR_HPP
#define CPPPROJECT_VECTOR_HPP

#include <bits/stdc++.h>
#include "Matrix.hpp"

using namespace std;

template<class T>
class Matrix;

/**
 * The class of vector
 * @tparam T the type of the element of vector
 */
template<class T>
class Vector {
public:
    /**
     * init a vector with length equals 0
     */
    Vector() {
        this->length = 0;
        this->vector.resize(length);
    }

    /**
     * init a vector by a std::vector
     * @param other the std::vector
     */
    Vector<T>(vector<T> other) {
        this->length = other.size();
        this->vector = other;
    }

/**
 * init a vector length equals user input and all elements equal default value
 * @param length  the length of the vector
 */
    explicit Vector(int length) {
        this->length = length;
        this->vector.resize(length);
    }

/**
 * get the length of the vector
 * @return the length of the vector
 */
    int getLength() {
        return this->length;
    }

/**
 * show the vector
 */
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

/**
 * overload [] to achieve the element of the vector
 * @param i the index of the vector
 * @return the i-th element of the vector
 */
    T &operator[](int i) {
        return this->vector[i];
    }

/**
 * get the minimum element of the vector
 * @return the minimum element of the vector
 */
    double findMin() {
        if (this->length == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->vector[0].real();
        for (int i = 0; i < length; ++i) {
            ans = min(ans, this->vector[i].real());
        }
        return ans;
    }
/**
 * get the maximum element of the vector
 * @return the maximum element of the vector
 */
    double findMax() {
        if (this->length == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->vector[0].real();
        for (int i = 0; i < length; ++i) {
            ans = max(ans, this->vector[i].real());
        }
        return ans;
    }
/**
 * get the average of the all elements of the vector
 * @return  the average of the all elements of the vector
 */
    T findAverage() {
        T ans = findSum();
        ans /= this->length;
        return ans;
    }
/**
 *get the sum of the all elements of the vector
 * @return  the sum of the all elements of the vector
 */
    T findSum() {
        if (this->length == 0) {
            cerr << "The Vector is empty,can not get sum" << endl;
            return {0, 0};
        }
        T ans = {0, 0};
        for (int i = 0; i < this->length; ++i) {
            ans += this->vector[i];
        }
        return ans;
    }
/**
 * set the length of the vector
 * @param _length the new length of the vector, if the size is larger,the new element is default value.
 */
    void setLength(int _length) {
        this->length = _length;
        this->vector.resize(_length);
    }
/**
 * vector dot product with other vector
 * @param other the other vector
 * @return the answer
 */
    T dot_product(Vector other) {
        T ans = 0;
        if (this->length != other.length) {
            cerr << "dot product error!" << endl;
            cerr << "the two vector length is not equal" << endl;
            return ans;
        }
        for (int i = 0; i < this->length; ++i) {
            ans += this->vector[i] * other.vector[i];
        }
        return ans;
    }
/**
 * get the conjugation of the vector
 * @return the conjugation of the vector
 */
    Vector conjugation() {
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            T cur(this->vector[i].real(), -this->vector[i].imag());
            ans[i] = cur;
        }
        return ans;
    }
/**
 * get the conjugation of the vector, and change this vector to ans
 * @return the conjugation of the vector
 */
    Vector conjugation_change() {
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            T cur(this->vector[i].real(), -this->vector[i].imag());
            ans[i] = cur;
        }
        this->vector = ans.vector;
        return ans;
    }
/**
 * get the element wise multiplication of the vector
 * @param other  the other vector to element wise multiplication
 * @return the answer vector
 */
    Vector element_wise_multiplication(Vector &other) {
        if (this->length != other.length) {
            cerr << "element_wise_multiplication_change error!" << endl;
            cerr << "the size of two vector is not equal" << endl;
            return Vector(0);
        }
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            ans[i] = this->vector[i] * other.vector[i];
        }
        return ans;
    }
/**
 * get the element wise multiplication of the vector, and change this vector to answer vector
 * @param other  the other vector to element wise multiplication
 * @return the answer vector
 */
    Vector element_wise_multiplication_change(Vector &other) {
        if (this->length != other.length) {
            cerr << "element_wise_multiplication_change error!" << endl;
            cerr << "the size of two vector is not equal" << endl;
            return Vector(0);
        }
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            ans[i] = this->vector[i] * other.vector[i];
        }
        this->vector = ans.vector;
        return ans;
    }
/**
 * reload operator + to add two vector
 * @param other  the other vector to add
 * @return the answer vector
 */
    Vector operator+(const Vector &other) const {
        if (this->length != other.length) {
            cerr << "The length of two vector is not equal" << endl;
            return Vector(0);
        }
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            ans[i] = this->vector[i] + other.vector[i];
        }
        return ans;
    }
/**
 * reload operator + to add with a matrix,every row of matrix will add the vector
 * @param other the matrix to add
 * @return the answer matrix
 */
    Matrix<T> operator+(Matrix<T> other) const {
        if (this->length != other.getColumn()) {
            cerr << "The column of the matrix is not equal to the vector length" << endl;
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
/**
 * reload operator - to add two vector
 * @param other  the other vector to minus
 * @return the answer vector
 */
    Vector operator-(const Vector &other) const {
        if (this->length != other.length) {
            cerr << "The length of two vector is not equal" << endl;
            return Vector(0);
        }
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            ans[i] = this->vector[i] - other.vector[i];
        }
        return ans;
    }
/**
 * reload operator - to add with a matrix,every row of matrix will minus the vector
 * @param other the matrix to minus
 * @return the answer matrix
 */
    Matrix<T> operator-(Matrix<T> other) const {
        if (this->length != other.getColumn()) {
            cerr << "The column of the matrix is not equal to the vector length" << endl;
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
/**
 * reload operator * to multiple with an element
 * @param other the multiplier
 * @return the answer vector
 */
    Vector operator*(T other) const {
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            ans[i] = this->vector[i] * other;
        }
        return ans;
    }
/**
 * reload operator * to multiple with a matrix,every row of the matrix will multiple with the vector
 * @param other the multiplier matrix
 * @return the answer vector
 */
    Vector operator*(Matrix<T> other) const {
        if (this->length != other.getRow()) {
            cerr << "Vector * Matrix error!" << endl;
            cerr << "Vector length is not equal Matrix row" << endl;
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
/**
 * get the cross product of two vectors
 * @param other the other vector to cross product
 * @return the answer vector
 */
    Vector cross_product(Vector other) {
        Vector ans = Vector(3);
        if (this->length == 2 && other.length == 2) {
            ans[2] = this->vector[0] * other.vector[1] - this->vector[1] * other.vector[0];
            return ans;
        }
        if (this->length == 3 && other.length == 3) {
            ans[0] = this->vector[1] * other.vector[2] - this->vector[2] * other.vector[1];
            ans[1] = this->vector[2] * other.vector[0] - this->vector[0] * other.vector[2];
            ans[2] = this->vector[0] * other.vector[1] - this->vector[1] * other.vector[0];
            return ans;
        }
        cerr << "The dimension of both vectors should either be 2 or 3" << endl;
        return Vector(0);
    }

private:
    vector<T> vector;
    int length{};
};

#endif //CPPPROJECT_VECTOR_HPP
