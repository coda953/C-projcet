
#ifndef CPPPROJECT_VECTOR_HPP
#define CPPPROJECT_VECTOR_HPP

#include "Matrix.hpp"
#include <vector>
#include <iostream>

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
     * 初始化长度为0的向量
     */
    Vector() {
        this->length = 0;
        this->vector.resize(length);
    }

    /**
     * 通过 std::vector 来初始化向量
     * @param other 传入的std::vector
     */
    Vector<T>(vector<T> other) {
        this->length = other.size();
        this->vector = other;
    }

/**
 * 初始化一个特定长度的向量，元素为默认值
 * @param length  向量的长度
 */
    explicit Vector(int length) {
        this->length = length;
        this->vector.resize(length);
    }

/**
 * 获得矩阵的长度
 * @return 矩阵的长度
 */
    int getLength() {
        return this->length;
    }

/**
 * 打印矩阵
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
 * 重载[]来访问向量的元素
 * @param i 下标
 * @return 第i个向量的元素
 */
    T &operator[](int i) {
        return this->vector[i];
    }

/**
 * 获得向量中的最小值
 * @return 向量的最小值
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
 * 获得向量中的最大值
 * @return 向量中的最大值
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
 * 获得向量的平均值
 * @return  向量的平均值
 */
    T findAverage() {
        T ans = findSum();
        ans /= this->length;
        return ans;
    }

/**
 * 获得向量所有元素的和
 * @return  向量所有元素的和
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
 * 设置向量的长度
 * 如果长度增加，多出的元素为默认值
 * 如果长度减少，多余的元素被删除
 * @param _length 向量的新长度
 */
    void setLength(int _length) {
        this->length = _length;
        this->vector.resize(_length);
    }

/**
 * 向量之间的点积
 * @param other 另一个向量
 * @return 向量的点积
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
 * 获得向量的共轭向量
 * @return 向量的共轭向量
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
 * 获得向量的共轭向量，并改变原向量
 * @return 向量的共轭向量
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
 * 获得两个向量的元素点乘
 * @param other  另一个元素点乘的向量
 * @return 结果向量
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
 * 获得两个向量的元素点乘
 * 并将原矩阵转化为结果矩阵
 * @param other  另一个元素点乘的向量
 * @return 结果向量
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
 * 重载+实现两个向量相加
 * @param other  另一个相加的向量
 * @return 结果向量
 */
    Vector operator+(Vector &other) {
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
 * 重载+实现向量与矩阵的加法
 * 向量的长度与矩阵的列数相同
 * 矩阵的每一行都与向量做加法
 * @param other 相加的矩阵
 * @return 向量与矩阵的相加结果
 */
    Matrix<T> operator+(Matrix<T> other) {
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
 * 重载-实现两个向量的减法
 * @param other  另一个相减的向量
 * @return 两个向量的减法
 */
    Vector operator-(Vector &other) {
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
 * 重载-，实现与矩阵的减法
 * 向量的长度要与矩阵的列数相同
 * 矩阵的每一行都与向量相减
 * @param other 相减的矩阵
 * @return 结果矩阵
 */
    Matrix<T> operator-(Matrix<T> other) {
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
 * 重载*实现向量与元素的乘
 * @param other 乘的元素
 * @return 向量与元素乘的结果
 */
    Vector operator*(T other) {
        Vector ans = Vector(this->length);
        for (int i = 0; i < this->length; ++i) {
            ans[i] = this->vector[i] * other;
        }
        return ans;
    }

/**
 * 重载*获得向量与矩阵的点积
 * 其中结果的每一个值为向量与矩阵的行的点积
 * @param other 另一个乘矩阵
 * @return 结果向量
 */
    Vector operator*(Matrix<T> other) {
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
 * 获得两个向量的叉积
 * @param other 另一个向量
 * @return 向量的叉积，长度为3，分别为i,j,k
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
