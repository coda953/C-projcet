#ifndef CPPPROJECT_MATRIX_HPP
#define CPPPROJECT_MATRIX_HPP

#include "Vector.hpp"
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

template<class T>
class Vector;

/**
 * the class of Matrix
 * @authors Zhu Junda Zheng Ruiqi Wang Yifan
 * @version 1.0
 * @tparam T the data type
 */
template<class T>
class Matrix {
public:
    /**
     * 初始化行列为0的矩阵
     */
    Matrix() {
        this->row = 0;
        this->column = 0;
        this->matrix.resize(0);
    }

/**
 * 重载[]访问矩阵中的元素
 * @param i  矩阵的行数
 * @return  矩阵该行的vector
 */
    vector<T> &operator[](int i) {
        if (i >= row) {
            cerr << "the input row is lager than row";
        }
        return this->matrix[i];
    }

/**
 * 初始化具体大小的矩阵
 * @param row 矩阵的行数
 * @param column 矩阵的列数
 */
    Matrix(int row, int column) {
        this->row = row;
        this->column = column;
        this->matrix.resize(row);
        for (int i = 0; i < row; ++i) {
            this->matrix[i].resize(column);
        }
    }

/**
 * 初始化矩阵，其行为1，列数为column
 * 形如向量
 * @param length 矩阵的长度（列数）
 */
    Matrix(int length) {
        this->row = 1;
        this->column = length;
        this->matrix.resize(this->row);
        this->matrix[0].resize(this->column);
    }

/**
 * 用另一个矩阵来初始化矩阵
 * @param other 传入矩阵
 */
    Matrix(Matrix const &other) {
        this->row = other.row;
        this->column = other.column;
        this->matrix = other.matrix;
    }

/**
 * 用vector来初始化矩阵
 * 矩阵的行数为1，列数为vector的长度
 * @param other 传入向量
 */
    Matrix(Vector<T> other) {
        Matrix ans = Matrix(1, other.getLength());
        for (int i = 0; i < other.getLength(); ++i) {
            ans[0][i] = other[i];
        }
        this->row = ans.row;
        this->column = ans.column;
        this->matrix = ans.matrix;
    }

/**
 * 获得矩阵中最小的元素
 * @return  矩阵中最小的元素
 */
    T findMin() {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0];
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans = min(ans, this->matrix[i][j]);
            }
        }
        return ans;
    }

/**
 * 获得矩阵中特定行的最小元素
 * @param row 行数
 * @return 该行最小的元素
 */
    T findMinAtRow(int row) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[row][0];
        for (int i = 0; i < this->column; ++i) {
            ans = min(ans, this->matrix[row][i]);
        }
        return ans;
    }

/**
 * 获得矩阵中特定列的最小元素
 * @param column 列数
 * @return 该列最小的元素
 */
    T findMinAtColumn(int column) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][column];
        for (int i = 0; i < row; ++i) {
            ans = min(ans, this->matrix[i][column]);
        }
        return ans;
    }

/**
 * 获得矩阵中最大的元素
 * @return 矩阵中最大的元素
 */
    T findMax() {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans = max(ans, this->matrix[i][j]);
            }
        }
        return ans;
    }

/**
 * 获得矩阵中特定行的最大元素
 * @param row 行数
 * @return 矩阵中特定行的最大元素
 */
    T findMaxAtRow(int row) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[row][0];
        for (int i = 0; i < this->column; ++i) {
            ans = max(ans, this->matrix[row][i]);
        }
        return ans;
    }

/**
 * 获得矩阵中特定列的最大元素
 * @param column 列数
 * @return 矩阵中特定列的最大元素
 */
    T findMaxAtColumn(int column) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][column];
        for (int i = 0; i < row; ++i) {
            ans = max(ans, this->matrix[i][column]);
        }
        return ans;
    }

/**
 * 获得矩阵的所有元素的平均值
 * @return 矩阵的所有元素的平均值
 */
    T findAverage() {
        T ans = findSum();
        ans /= (row * this->column);
        return ans;
    }

/**
 * 获得矩阵特定行的元素平均值
 * @param row 行数
 * @return 矩阵特定行的元素平均值
 */
    T findAverageAtRow(int row) {
        T ans = findSumAtRow(row);
        ans /= this->column;
        return ans;
    }

/**
 * 获得矩阵特定列的元素平均值
 * @param column 列数
 * @return 矩阵特定列的元素平均值
 */
    T findAverageAtColumn(int column) {
        T ans = findSumAtColumn(column);
        ans /= this->row;
        return ans;
    }

/**
 * 获得矩阵所有元素的和
 * @return 矩阵所有元素的和
 */
    T findSum() {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        T ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                ans += this->matrix[i][j];
            }
        }
        return ans;
    }

/**
 * 获得矩阵特定行的和
 * @param row 行数
 * @return 矩阵特定行的和
 */
    T findSumAtRow(int row) {
        if (this->row < row) {
            cerr << "Input row is bigger than the vector size" << endl;
            return 0;
        }
        T ans = 0;
        for (int i = 0; i < column; ++i) {
            ans += this->matrix[row][i];
        }
        return ans;
    }

/**
 * 获得矩阵特定列的和
 * @param column 列数
 * @return 矩阵特定列的和
 */
    T findSumAtColumn(int column) {
        if (this->column < column) {
            cerr << "Input column is bigger than the vector size" << endl;
            return 0;
        }
        T ans = 0;
        for (int i = 0; i < this->row; ++i) {
            ans += this->matrix[i][column];
        }
        return ans;
    }

/**
 * 计算矩阵的迹
 * 即矩阵的对角线之和
 * @return 矩阵的迹
 */
    T cal_traces() {
        T ans = 0;
        int cur = min(this->row, this->column);
        for (int i = 0; i < cur; ++i) {
            ans += this->matrix[i][i];
        }
        return ans;
    }

/**
 * 显示矩阵
 */
    void show() {
        cout << "Row:" << this->row << endl;
        cout << "Column:" << this->column << endl;
        cout << "[";
        for (int i = 0; i < row; ++i) {
            cout << "[";
            for (int j = 0; j < column; ++j) {
                cout << this->matrix[i][j];
                if (j != column - 1) {
                    cout << ",";
                }
            }
            cout << "]";
            if (i != row - 1) {
                cout << endl;
            }
        }
        cout << "]" << endl;
    }

/**
 * 显示矩阵的size
 */
    void showSize() {
        cout << "Row:" << this->row << "  Column:" << this->column << endl;
    }

/**
 * 设置矩阵的行数
 * 如果行数增加，多出的元素为默认值
 * 如果行数减少，多余的元素被删除
 * @param row 矩阵的新行数
 */
    void setRow(int row) {
        this->row = row;
        this->matrix.resize(row);
    }

/**
 * 获取矩阵的行数
 * @return 矩阵的行数
 */
    int getRow() {
        return this->row;
    }

/**
 * 设置矩阵的列数
 * 如果列数增加，多出的元素为默认值
 * 如果列数减少，多余的元素被删除
 * @param column 矩阵的新列数
 * @return 设置失败返回0，成功返回1
 */
    int setColumn(int column) {
        if (this->row == 0) {
            return 0;
        }
        this->column = column;
        for (int i = 0; i < row; ++i) {
            this->matrix[i].resize(column);
        }
        return 1;
    }

/**
 * 获取矩阵的列数
 */
    int getColumn() {
        return this->column;

    }

/**
 * 计算一个方阵的特征值
 * @return 矩阵的特征值
 */
    vector<T> getEigenvalue() {
        if (this->row != this->column) {
            cerr << "The matrix is not a square matrix" << endl;
            vector<T> k;
            return k;
        }
        class temp {
        public:
            double K1[1000];
            double Ret[1000];

            void Matrix_Hessenberg(double *A1, int n, double *ret) {
                int i, j, k, MaxNumber;
                double temp, *A;
                A = new double[n * n];
                for (i = 0; i < n; i++) {
                    k = i * n;
                    for (j = 0; j < n; j++) {
                        A[k + j] = A1[k + j];
                    }
                }
                for (k = 1; k < n - 1; k++) {
                    i = k - 1;
                    MaxNumber = k;
                    temp = abs(A[k * n + i]);
                    for (j = k + 1; j < n; j++) {
                        if (abs(A[j * n + i]) > temp) {
                            temp = abs(A[j * n + i]);
                            MaxNumber = j;
                        }
                    }
                    ret[0] = A[MaxNumber * n + i];
                    i = MaxNumber;
                    if (ret[0] != 0) {
                        if (i != k) {
                            for (j = k - 1; j < n; j++) {
                                temp = A[i * n + j];
                                A[i * n + j] = A[k * n + j];
                                A[k * n + j] = temp;
                            }
                            for (j = 0; j < n; j++) {
                                temp = A[j * n + i];
                                A[j * n + i] = A[j * n + k];
                                A[j * n + k] = temp;
                            }
                        }
                        for (i = k + 1; i < n; i++) {
                            temp = A[i * n + k - 1] / ret[0];
                            A[i * n + k - 1] = 0;
                            for (j = k; j < n; j++) {
                                A[i * n + j] -= temp * A[k * n + j];
                            }
                            for (j = 0; j < n; j++) {
                                A[j * n + k] += temp * A[j * n + i];
                            }
                        }
                    }

                }
                for (i = 0; i < n; i++) {
                    k = i * n;
                    for (j = 0; j < n; j++) {
                        ret[k + j] = A[k + j];
                    }
                }
                delete[]A;
            }

            bool Matrix_EigenValue(int n, int LoopNumber, double Error1) {
                int i, j, k, t, m, Loop1;
                double b, c, d, g, xy, p, q, r, x, s, e, f, z, y, temp, *A;
                A = new double[n * n];
                Matrix_Hessenberg(K1, n, A);
                m = n;
                Loop1 = LoopNumber;
                while (m != 0) {
                    t = m - 1;
                    while (t > 0) {
                        temp = abs(A[(t - 1) * n + t - 1]);
                        temp += abs(A[t * n + t]);
                        temp = temp * Error1;
                        if (abs(A[t * n + t - 1]) > temp) {
                            t--;
                        } else {
                            break;
                        }
                    }
                    if (t == m - 1) {
                        Ret[(m - 1) * 2] = A[(m - 1) * n + m - 1];
                        Ret[(m - 1) * 2 + 1] = 0;
                        m -= 1;
                        Loop1 = LoopNumber;
                    } else if (t == m - 2) {
                        b = -A[(m - 1) * n + m - 1] - A[(m - 2) * n + m - 2];
                        c = A[(m - 1) * n + m - 1] * A[(m - 2) * n + m - 2] -
                            A[(m - 1) * n + m - 2] * A[(m - 2) * n + m - 1];
                        d = b * b - 4 * c;
                        y = sqrt(abs(d));
                        if (d > 0) {
                            xy = 1;
                            if (b < 0) {
                                xy = -1;
                            }
                            Ret[(m - 1) * 2] = -(b + xy * y) / 2;
                            Ret[(m - 1) * 2 + 1] = 0;
                            Ret[(m - 2) * 2] = c / Ret[(m - 1) * 2];
                            Ret[(m - 2) * 2 + 1] = 0;
                        } else {
                            Ret[(m - 1) * 2] = -b / 2;
                            Ret[(m - 2) * 2] = -b / 2;
                            Ret[(m - 1) * 2 + 1] = y / 2;
                            Ret[(m - 2) * 2 + 1] = -y / 2;
                        }
                        m -= 2;
                        Loop1 = LoopNumber;
                    } else {
                        if (Loop1 < 1) {
                            return false;
                        }
                        Loop1--;
                        j = t + 2;
                        while (j < m) {
                            A[j * n + j - 2] = 0;
                            j++;
                        }
                        j = t + 3;
                        while (j < m) {
                            A[j * n + j - 3] = 0;
                            j++;
                        }
                        k = t;
                        while (k < m - 1) {
                            if (k != t) {
                                p = A[k * n + k - 1];
                                q = A[(k + 1) * n + k - 1];
                                if (k != m - 2) {
                                    r = A[(k + 2) * n + k - 1];
                                } else {
                                    r = 0;
                                }
                            } else {
                                b = A[(m - 1) * n + m - 1];
                                c = A[(m - 2) * n + m - 2];
                                x = b + c;
                                y = b * c - A[(m - 2) * n + m - 1] * A[(m - 1) * n + m - 2];
                                p = A[t * n + t] * (A[t * n + t] - x) + A[t * n + t + 1] * A[(t + 1) * n + t] + y;
                                q = A[(t + 1) * n + t] * (A[t * n + t] + A[(t + 1) * n + t + 1] - x);
                                r = A[(t + 1) * n + t] * A[(t + 2) * n + t + 1];
                            }
                            if (p != 0 || q != 0 || r != 0) {
                                if (p < 0) {
                                    xy = -1;
                                } else {
                                    xy = 1;
                                }
                                s = xy * sqrt(p * p + q * q + r * r);
                                if (k != t) {
                                    A[k * n + k - 1] = -s;
                                }
                                e = -q / s;
                                f = -r / s;
                                x = -p / s;
                                y = -x - f * r / (p + s);
                                g = e * r / (p + s);
                                z = -x - e * q / (p + s);
                                for (j = k; j < m; j++) {
                                    b = A[k * n + j];
                                    c = A[(k + 1) * n + j];
                                    p = x * b + e * c;
                                    q = e * b + y * c;
                                    r = f * b + g * c;
                                    if (k != m - 2) {
                                        b = A[(k + 2) * n + j];
                                        p += f * b;
                                        q += g * b;
                                        r += z * b;
                                        A[(k + 2) * n + j] = r;
                                    }
                                    A[(k + 1) * n + j] = q;
                                    A[k * n + j] = p;
                                }
                                j = k + 3;
                                if (j > m - 2) {
                                    j = m - 1;
                                }
                                for (i = t; i < j + 1; i++) {
                                    b = A[i * n + k];
                                    c = A[i * n + k + 1];
                                    p = x * b + e * c;
                                    q = e * b + y * c;
                                    r = f * b + g * c;
                                    if (k != m - 2) {
                                        b = A[i * n + k + 2];
                                        p += f * b;
                                        q += g * b;
                                        r += z * b;
                                        A[i * n + k + 2] = r;
                                    }
                                    A[i * n + k + 1] = q;
                                    A[i * n + k] = p;
                                }
                            }
                            k++;
                        }
                    }
                }
                delete[]A;
                return true;
            }
        };
        temp ans;
        int count = 0;
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans.K1[count++] = this->matrix[i][j];
            }
        }
        vector<T> result;
        ans.Matrix_EigenValue(this->row, 1000, 0.00001);
        for (int i = 0; i < this->row; ++i) {
            result.push_back(ans.Ret[i * 2]);
        }

        return result;
    }

/**
 * 矩阵转置
 * @return 矩阵转置后的矩阵
 */
    Matrix transposition() {
        Matrix ans = Matrix(this->column, this->row);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans[j][i] = this->matrix[i][j];
            }
        }
        return ans;
    }

/**
 * 矩阵转置，并改变原矩阵
 * @return 矩阵转置后的矩阵
 */
    Matrix transposition_change() {
        Matrix ans = this->transposition();
        this->row = ans.row;
        this->column = ans.column;
        this->matrix = ans.matrix;
        return ans;
    }

/**
 * 矩阵共轭
 * @return 原矩阵的共轭矩阵
 */
    Matrix conjugation() {
        Matrix ans = Matrix(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                T cur(this->matrix[i][j].real(), -this->matrix[i][j].imag());
                ans[i][j] = cur;
            }
        }
        return ans;
    }

/**
 * 矩阵共轭，并改变原矩阵
 * @return 原矩阵的共轭矩阵
 */
    Matrix conjugation_change() {
        Matrix ans = this->conjugation();
        this->matrix = ans.matrix;
        return ans;
    }

/**
 * 矩阵元素点乘
 * @param other 点乘的矩阵
 * @return 矩阵元素点乘的结果
 */
    Matrix element_wise_multiplication(Matrix &other) {
        if (this->row != other.row || this->column != other.column) {
            cerr << "the size of these two vector is not equal" << endl;
            cerr << "left size is:";
            this->showSize();
            cerr << "right size is:";
            other.showSize();
            return Matrix(0, 0);
        }
        Matrix ans = Matrix(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans[i][j] = this->matrix[i][j] * other.matrix[i][j];
            }
        }
        return ans;
    }

/**
 * 矩阵元素点乘，并将结果赋值给原矩阵
 * @param other 点乘的矩阵
 * @return 矩阵元素点乘的结果
 */
    Matrix element_wise_multiplication_change(Matrix &other) {
        if (this->row != other.row || this->column != other.column) {
            cerr << "the size of these two vector is not equal" << endl;
            cerr << "left size is:";
            this->showSize();
            cerr << "right size is:";
            other.showSize();
            return Matrix(0, 0);
        }
        Matrix ans = Matrix(this->row, this->column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans[i][j] = this->matrix[i][j] * other.matrix[i][j];
            }
        }
        this->row = ans.row;
        this->column = ans.column;
        this->matrix = ans.matrix;
        return ans;
    }

/**
 * 矩阵整形为特定行列的矩阵
 * 若原矩阵元素大于新矩阵，则多余元素丢失
 * 若原矩阵元素小于等于新矩阵，则多余元素补为默认值
 * @param row 新矩阵的行数
 * @param column 新矩阵的列数
 * @return 新矩阵
 */
    Matrix reshape(int row, int column) {
        Matrix ans = Matrix(row, column);
        int other = row * column;
        int cur = this->row * this->column;
        int count = 0;
        while (count < min(other, cur)) {
            int curRow = count / this->column;
            int curColumn = count % this->column;
            int ansRow = count / column;
            int ansColumn = count % column;
            ans[ansRow][ansColumn] = this->matrix[curRow][curColumn];
            count++;
        }
        return ans;
    }

/**
 * 矩阵整形为特定行列的矩阵，同时改变原矩阵
 * 若原矩阵元素大于新矩阵，则多余元素丢失
 * 若原矩阵元素小于等于新矩阵，则多余元素补为默认值
 * @param row 新矩阵的行数
 * @param column 新矩阵的列数
 * @return 新矩阵
 */
    Matrix reshape_change(int row, int column) {
        Matrix ans = this->reshape(row, column);
        this->row = row;
        this->column = column;
        this->matrix = ans.matrix;
        return ans;
    }

/**
 * 矩阵切片，获取[from，to)范围内的元素
 * @param from 起坐标
 * @param to 终止坐标
 * @return 切片后的向量
 */
    Vector<T> slicing(int from, int to) {
        Matrix cur = this->reshape(1, this->row * this->column);
        if (to > cur.column) {
            cerr << "slicing error" << endl;
            cerr << "slicing bound is large than matrix size" << endl;
            return Vector<T>(0);
        }
        if (from < 0) {
            cerr << "slicing error" << endl;
            cerr << "slicing left bound is little than 0" << endl;
            return Vector<T>(0);
        }
        Vector<T> ans = Vector<T>(to - from);
        for (int i = 0; i < ans.getLength(); ++i) {
            ans[i] = cur.matrix[0][from + i];
        }
        return ans;
    }

/**
 * 重载矩阵加法
 * @param other 相加的矩阵
 * @return 矩阵计算结果
 */
    Matrix operator+(Matrix &other) {
        if (this->row != other.row || this->column != other.column) {
            cerr << "the size of these two vector is not equal" << endl;
            cerr << "left size is:";
            showSize();
            cerr << "right size is:";
            other.showSize();
            return Matrix(0, 0);
        }
        Matrix ans = Matrix(row, column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                ans[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return ans;
    }

/**
 * 重载矩阵与向量相加
 * 矩阵列数要与向量长度相等
 * 矩阵每一行都与向量相加
 * @param other 相加的向量
 * @return 矩阵计算结果
 */
    Matrix operator+(Vector<T> other) {
        if (this->column != other.getLength()) {
            cerr << "The column of the matrix is not equal to the vector length" << endl;
            return Matrix(0, 0);
        }
        Matrix ans = Matrix(this->row, this->column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                ans[i][j] = this->matrix[i][j] + other[j];
            }
        }
        return ans;
    }

/**
 * 重载矩阵减法
 * @param other 相减的矩阵
 * @return 矩阵计算结果
 */
    Matrix operator-(Matrix &other) {
        if (this->row != other.row || this->column != other.column) {
            cerr << "the size of these two vector is not equal" << endl;
            cerr << "left size is:";
            this->showSize();
            cerr << "right size is:";
            other.showSize();
            return Matrix(0, 0);
        }
        Matrix ans = Matrix(row, column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                ans[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }
        return ans;
    }

/**
 * 重载矩阵与向量相减
 * 矩阵列数要与向量长度相等
 * 矩阵每一行都与向量相减
 * @param other 相减的向量
 * @return 矩阵计算结果
 */
    Matrix operator-(Vector<T> other) {
        if (this->column != other.getLength()) {
            cerr << "The column of the matrix is not equal to the vector length" << endl;
            return Matrix(0, 0);
        }
        Matrix ans = Matrix(this->row, this->column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                ans[i][j] = this->matrix[i][j] - other[j];
            }
        }
        return ans;
    }

/**
 * 重载矩阵乘法，矩阵点乘
 * @param other 相乘的矩阵
 * @return 矩阵运算结果
 */
    Matrix operator*(Matrix &other) {
        if (this->column != other.row) {
            cerr << "multiple error!" << endl;
            cerr << "the left matrix column is not equal right matrix row" << endl;
        }
        Matrix ans = Matrix(this->row, other.column);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < other.column; ++j) {
                for (int k = 0; k < this->column; ++k) {
                    ans[i][j] += this->matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return ans;
    }

/**
 * 重载矩阵向量乘法
 * 矩阵列数要与向量长度相等
 * 矩阵每一行与向量点乘
 * @param other 相点乘的向量
 * @return 长度为行数的向量，每个元素为对应行数点乘的结果
 */
    Vector<T> operator*(Vector<T> other) {
        if (this->column != other.getLength()) {
            cerr << "Matrix * Vector error!" << endl;
            cerr << "The left Matrix column is not equal right length" << endl;
            return Vector<T>(0);
        }
        Vector<T> ans = Vector<T>(this->row);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < other.getLength(); ++j) {
                ans[i] += this->matrix[i][j] * other[j];
            }
        }
        return ans;
    }

/**
 * 求矩阵逆
 * @return 矩阵逆
 */
    Matrix inverse() {
        class temp {
        public:

//-----------------------------------------------------
// show matrix : cout<< in c++ , printf() in c
            void printf(float a[100][100], int n, int show) {
                int i, j;
                if (show == 1)
                    for (i = 0; i < n; i++) {
                        for (j = 0; j < n; j++)
                            cout << " " << a[i][j] << " \t";
                        cout << "\n";
                    }
                else if (show == 2) {
                    cout << "\n\n The Inverse Of Matrix Is : \n\n";
                    for (i = 0; i < n; i++) {
                        for (j = 0; j < n; j++)
                            cout << " " << a[i][j] << " \t";
                        cout << "\n";
                    }
                }
            }

//---------------------------------------------------
//	calculate minor of matrix OR build new matrix : k-had = minor
            void minor(float b[100][100], float a[100][100], int i, int n) {
                int j, l, h = 0, k = 0;
                for (l = 1; l < n; l++)
                    for (j = 0; j < n; j++) {
                        if (j == i)
                            continue;
                        b[h][k] = a[l][j];
                        k++;
                        if (k == (n - 1)) {
                            h++;
                            k = 0;
                        }
                    }
            }// end function

//---------------------------------------------------
//	calculate determinte of matrix
            float det(float a[100][100], int n) {
                int i;
                float b[100][100], sum = 0;
                if (n == 1)
                    return a[0][0];
                else if (n == 2)
                    return (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
                else
                    for (i = 0; i < n; i++) {
                        minor(b, a, i, n);    // read function
                        sum = (float) (sum + a[0][i] * pow(-1, i) *
                                             det(b, (n - 1)));    // read function	// sum = determinte matrix
                    }
                return sum;
            }// end function

//---------------------------------------------------
//	calculate transpose of matrix
            void transpose(float c[100][100], float d[100][100], int n, float det) {
                int i, j;
                float b[100][100];
                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        b[i][j] = c[j][i];
                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        d[i][j] = b[i][j] / det;    // array d[][] = inverse matrix
            }// end function

//---------------------------------------------------
//	calculate cofactor of matrix
            void cofactor(float a[100][100], float d[100][100], int n, float determinte) {
                float b[100][100], c[100][100];
                int l, h, m, k, i, j;
                for (h = 0; h < n; h++)
                    for (l = 0; l < n; l++) {
                        m = 0;
                        k = 0;
                        for (i = 0; i < n; i++)
                            for (j = 0; j < n; j++)
                                if (i != h && j != l) {
                                    b[m][k] = a[i][j];
                                    if (k < (n - 2))
                                        k++;
                                    else {
                                        k = 0;
                                        m++;
                                    }
                                }
                        c[h][l] = (float) pow(-1, (h + l)) * det(b, (n - 1));    // c = cofactor Matrix
                    }
                transpose(c, d, n, determinte);    // read function
            }// end function

//---------------------------------------------------
//	calculate inverse of matrix
            void inverse(float a[100][100], float d[100][100], int n, float det) {
                if (det == 0)
                    cout << "\nInverse of Entered Matrix is not possible\n";
                else if (n == 1)
                    d[0][0] = 1;
                else
                    cofactor(a, d, n, det);    // read function
            }// end function

        };
        if (this->row != this->column ){
            cerr << "cannot calculate the inverse of the rectangle matrix" <<endl;
            return Matrix<double>(this->row, this->column);
        }
        int n = this->row;
        temp ans, ans1;
        float a[100][100], d[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = this->matrix[i][j];
            }
        }
        float deter = (float) ans.det(a, n);
        ans1.inverse(a, d, n, deter);
        Matrix<double> answer = Matrix<double>(this->row, this->column);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                answer[i][j] = d[i][j];
            }
        }
        return answer;
    }

/**
 * 计算矩阵的行列式
 * @return 矩阵的行列式
 */
    T cal_det() {
        if (this->row != this->column) {
            cerr << "The matrix is not square matrix";
            return 0;
        }
        class temp {
        public:
            double det(int n, double *mm) {
                if (n == 1)
                    return mm[0];
                double *subMat = new double[(n - 1) * (n - 1)];//创建n-1阶的代数余子式阵subMat
                int mov = 0;//判断行是否移动
                double sum = 0.0;//sum为行列式的值
                for (int Matrow = 0; Matrow < n; Matrow++) // Mat的行数把矩阵Mat(nn)赋值到subMat(n-1)
                {
                    for (int subMatrow = 0; subMatrow < n - 1; subMatrow++)//把Mat阵第一列各元素的代数余子式存到subMat
                    {
                        mov = Matrow > subMatrow ? 0 : 1; //subMat中小于Matrow的行，同行赋值，等于的错过，大于的加一
                        for (int j = 0; j < n - 1; j++)  //从Mat的第二列赋值到第n列
                        {
                            subMat[subMatrow * (n - 1) + j] = mm[(subMatrow + mov) * n + j + 1];
                        }
                    }
                    int flag = (Matrow % 2 == 0 ? 1 : -1);//因为列数为0，所以行数是偶数时候，代数余子式为1.
                    sum += flag * mm[Matrow * n] * det(n - 1, subMat);//Mat第一列各元素与其代数余子式积的和即为行列式
                }
                delete[]subMat;
                return sum;
            }
        };
        double *cur = new double[this->row * this->row];
        int count = 0;
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->row; ++j) {
                cur[count++] = this->matrix[i][j];
            }
        }
        temp ans;
        return ans.det(this->row, cur);
    }

/**
 * 通过二维向量数组声明矩阵
 * @param other 二维数组
 */
    Matrix(vector<vector<T>> other);

/**
 * 通过矩阵声明矩阵
 * @param other 另一个矩阵
 */
    Matrix(Mat other);

/**
 * 将矩阵转化为opencv的cv::Mat中32FC1的形式
 * @return 矩阵转化后的Mat
 */
    Mat to_opencv_32FC1();

/**
 * 将矩阵转化为opencv的cv::Mat中8UC1的形式
 * @return 矩阵转化后的Mat
 */
    Mat to_opencv_8UC1();

/**
 * 矩阵卷积
 * @param kernel 矩阵卷积和
 * @return 矩阵卷积结果
 */
    Matrix convolution_2D(Matrix &kernel) {
        // find center position of kernel (half of kernel size)
        int kCenterX = kernel.column / 2;
        int kCenterY = kernel.row / 2;
        Matrix ans = Matrix(this->row, this->column);
        for (int i = 0; i < this->row; ++i) // rows
        {
            for (int j = 0; j < this->column; ++j) // columns
            {
                for (int m = 0; m < kernel.row; ++m) // kernel rows
                {
                    int mm = kernel.row - 1 - m; // row index

                    for (int n = 0; n < kernel.column; ++n) // kernel columns
                    {
                        int nn = kernel.column - 1 - n; // column index

                        // index of input signal, used for checking boundary
                        int ii = i + (m - kCenterY);
                        int jj = j + (n - kCenterX);

                        // ignore input samples which are out of bound
                        if (ii >= 0 && ii < this->row && jj >= 0 && jj < this->column)
                            ans[i][j] += this->matrix[ii][jj] * kernel[m][n];
                    }
                }
            }
        }
        return ans;

    }

private:
    vector<vector<T>> matrix;
    int row{}, column{};
};


template<class T>
Matrix<T>::Matrix(vector<vector<T>> other) {
    this->row = other.size();
    this->column = other[0].size();
    this->matrix = other;
}

template<class T>
Mat Matrix<T>::to_opencv_8UC1() {
    Mat ans = Mat::zeros(this->row, this->column, CV_8UC1);
    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->column; ++j) {
            ans.at<uchar>(i, j) = this->matrix[i][j];
        }
    }
    return ans;
}

template<class T>
Mat Matrix<T>::to_opencv_32FC1() {
    Mat ans = Mat::zeros(this->row, this->column, CV_32FC1);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            ans.at<float>(i, j) = this->matrix[i][j];
        }
    }
    return ans;
}

template<class T>
Matrix<T>::Matrix(Mat other) {
    Matrix ans = Matrix(other.rows, other.cols);
    if (other.type() == CV_32FC1) {
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                ans[i][j] = other.at<float>(i, j);
            }
        }
    } else if (other.type() == CV_8UC1) {
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                ans[i][j] = other.at<uchar>(i, j);
            }
        }
    }
    this->row = ans.row;
    this->column = ans.column;
    this->matrix = ans.matrix;
}

#endif //CPPPROJECT_MATRIX_HPP
