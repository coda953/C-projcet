#ifndef CPPPROJECT_MATRIX_HPP
#define CPPPROJECT_MATRIX_HPP

#include <bits/stdc++.h>
#include "Vector.hpp"
#include <opencv.hpp>

using namespace std;
using namespace cv;

template<class T>
class Vector;

template<class T>
class Matrix {
public:
    Matrix() {
        this->row = 0;
        this->column = 0;
        this->matrix.resize(0);
    }

    vector<T> &operator[](int i) {
        if (i >= row) {
            cerr << "the input row is lager than row";
        }
        return this->matrix[i];
    }

    Matrix(int row, int column) {
        this->row = row;
        this->column = column;
        this->matrix.resize(row);
        for (int i = 0; i < row; ++i) {
            this->matrix[i].resize(column);
        }
    }

    Matrix(int length) {
        this->row = 1;
        this->column = length;
        this->matrix.resize(this->row);
        this->matrix[0].resize(this->column);
    }

    Matrix(Matrix const &other) {
        this->row = other.row;
        this->column = other.column;
        this->matrix = other.matrix;
    }

    Matrix(Vector<T> other) {
        Matrix ans = Matrix(1, other.getLength());
        for (int i = 0; i < other.getLength(); ++i) {
            ans[0][i] = other[i];
        }
        this->row = ans.row;
        this->column = ans.column;
        this->matrix = ans.matrix;
    }

    T findMin() {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0].real();
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans = min(ans, this->matrix[i][j]);
            }
        }
        return ans;
    }

    T findMinAtRow(int row) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0].real();
        for (int i = 0; i < this->column; ++i) {
            ans = min(ans, this->matrix[row][this->column].real());
        }
        return ans;
    }

    T findMinAtColumn(int column) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0].real();
        for (int i = 0; i < row; ++i) {
            ans = min(ans, this->matrix[i][column]);
        }
        return ans;
    }

    T findMax() {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0].real();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans = max(ans, this->matrix[i][j]);
            }
        }
        return ans;
    }

    T findMaxAtRow(int row) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0].real();
        for (int i = 0; i < this->column; ++i) {
            ans = max(ans, this->matrix[row][this->column].real());
        }
        return ans;
    }

    T findMaxAtColumn(int column) {
        if (this->row == 0 || this->column == 0) {
            cerr << "The vector is empty,can not get sum" << endl;
            return 0;
        }
        double ans = this->matrix[0][0].real();
        for (int i = 0; i < row; ++i) {
            ans = max(ans, this->matrix[i][column]);
        }
        return ans;
    }

    T findAverage() {
        T ans = findSum();
        ans /= (row * this->column);
        return ans;
    }

    T findAverageAtRow(int row) {
        T ans = findSumAtRow(row);
        ans /= this->column;
        return ans;
    }

    T findAverageAtColumn(int column) {
        T ans = findSumAtColumn(column);
        ans /= this->row;
        return ans;
    }

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

    T findSumAtColumn(int column) {
        if (this->column < column) {
            cerr << "Input column is bigger than the vector size" << endl;
            return 0;
        }
        T ans = 0;
        for (int i = 0; i < this->row; ++i) {
            ans += this->matrix[column][i];
        }
        return ans;
    }

    T cal_traces() {
        T ans = 0;
        int cur = min(this->row, this->column);
        for (int i = 0; i < cur; ++i) {
            ans += this->matrix[i][i];
        }
        return ans;
    }

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

    void showSize() {
        cout << "Row:" << this->row << "  Column:" << this->column << endl;
    }

    int setRow(int row) {
        this->row = row;
        this->matrix.resize(row);
        return 1;
    }

    int getRow() {
        return this->row;
    }

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

    int getColumn() {
        return this->column;

    }

    Matrix transposition() {
        Matrix ans = Matrix(this->column, this->row);
        for (int i = 0; i < this->row; ++i) {
            for (int j = 0; j < this->column; ++j) {
                ans[j][i] = this->matrix[i][j];
            }
        }
        return ans;
    }

    Matrix transposition_change() {
        Matrix ans = this->transposition();
        this->row = ans.row;
        this->column = ans.column;
        this->matrix = ans.matrix;
        return ans;
    }

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

    Matrix conjugation_change() {
        Matrix ans = this->conjugation();
        this->matrix = ans.matrix;
        return ans;
    }

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

    Matrix reshape_change(int row, int column) {
        Matrix ans = this->reshape(row, column);
        this->row = row;
        this->column = column;
        this->matrix = ans.matrix;
        return ans;
    }

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

    Matrix operator+(const Matrix &other) const {
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
                ans[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }
        return ans;
    }

    Matrix operator+(Vector<T> other) const {
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

    Matrix operator-(const Matrix &other) const {
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

    Matrix operator-(Vector<T> other) const {
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

    Matrix operator*(const Matrix &other) const {
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

    Vector<T> operator*(Vector<T> other) const {
        if (this->column != other.getLength()) {
            cerr << "Matrix * Vector error!" << endl;
            cerr << "The left Matrix column is not equal right length" << endl;
            return Vector<T>(0);
        }
        Vector<T> ans = Vector<T>(other.getLength());
        for (int i = 0; i < other.getLength(); ++i) {
            for (int j = 0; j < other.getLength(); ++j) {
                ans[i] += this->matrix[i][j] * other[j];
            }
        }
        return ans;
    }

    Matrix(Mat other);

    Mat to_opencv_32FC1();

    Mat to_opencv_8UC1();

private:
    vector<vector<T>> matrix;
    int row{}, column{};
};

template<class T>
Mat Matrix<T>::to_opencv_8UC1() {
    Mat ans = Mat::zeros(Size(this->column, this->row), CV_8UC1);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            ans.at<float>(i, j) = this->matrix[i][j];
        }
    }
    return ans;
}

template<class T>
Mat Matrix<T>::to_opencv_32FC1() {
    Mat ans = Mat::zeros(Size(this->column, this->row), CV_32FC1);
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
