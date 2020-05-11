#include "Matrix.hpp"

Matrix::Matrix(int row, int column) {
    this->row = row;
    this->column = column;
    this->matrix.resize(row);
    for (int i = 0; i < row; ++i) {
        this->matrix[i].resize(column);
    }
}

Matrix::Matrix() {
}

vector<complex<double>> &Matrix::operator[](int i) {
    if (i >= row) {
        cout << "the input row is lager than row";
    }
    return this->matrix[i];
}

void Matrix::show() const {
    cout << "Row:" << this->row << endl;
    cout << "Column:" << this->column << endl;
    cout << "[";
    for (int i = 0; i < row; ++i) {
        cout << "[";
        for (int j = 0; j < column; ++j) {
            if (this->matrix[i][j].imag()) {
                cout << this->matrix[i][j];
            } else {
                cout << this->matrix[i][j].real();
            }
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

int Matrix::setRow(int input) {
    this->row = input;
    this->matrix.resize(input);
    return 1;
}

int Matrix::setColumn(int input) {
    if (this->row == 0) {
        return 0;
    }
    this->column = input;
    for (int i = 0; i < row; ++i) {
        this->matrix[i].resize(input);
    }
    return 1;
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (this->row != other.row || this->column != other.column) {
        cout << "the size of these two matrix is not equal" << endl;
        cout << "left size is:";
        this->showSize();
        cout << "right size is:";
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

void Matrix::showSize() const {
    cout << "Row:" << this->row << "  Column:" << this->column << endl;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (this->row != other.row || this->column != other.column) {
        cout << "the size of these two matrix is not equal" << endl;
        cout << "left size is:";
        this->showSize();
        cout << "right size is:";
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

Matrix Matrix::operator*(const Matrix &other) const {
    return Matrix();
}


