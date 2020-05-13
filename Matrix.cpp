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

int Matrix::setRow(int row) {
    this->row = row;
    this->matrix.resize(row);
    return 1;
}

int Matrix::setColumn(int column) {
    if (this->row == 0) {
        return 0;
    }
    this->column = column;
    for (int i = 0; i < row; ++i) {
        this->matrix[i].resize(column);
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

//TODO 重载*
Matrix Matrix::operator*(const Matrix &other) const {
    return Matrix();
}

Matrix::Matrix(int length) {
    this->row = 1;
    this->column = length;
    this->matrix[0].resize(column);
}

double Matrix::findMax() {
    if (this->row == 0 || this->column == 0) {
        cout << "The matrix is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            ans = max(ans, this->matrix[i][j].real());
        }
    }
    return ans;
}

complex<double> Matrix::findAverage() {
    complex<double> ans = findSum();
    ans /= (row * column);
    return ans;
}

complex<double> Matrix::findSum() {
    if (this->row == 0 || this->column == 0) {
        cout << "The matrix is empty,can not get sum" << endl;
        return {0, 0};
    }
    complex<double> ans = {0, 0};
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            ans += this->matrix[i][j];
        }
    }
    return ans;
}

complex<double> Matrix::findSumAtRow(int row) {
    if (this->row < row) {
        cout << "Input row is bigger than the matrix size" << endl;
        return {0, 0};
    }
    complex<double> ans = {0, 0};
    for (int i = 0; i < column; ++i) {
        ans += this->matrix[row][i];
    }
    return ans;
}

complex<double> Matrix::findSumAtColumn(int column) {
    if (this->column < column) {
        cout << "Input column is bigger than the matrix size" << endl;
        return {0, 0};
    }
    complex<double> ans = {0, 0};
    for (int i = 0; i < this->row; ++i) {
        ans += this->matrix[column][i];
    }
    return ans;
}

complex<double> Matrix::findAverageAtRow(int row) {
    complex<double> ans = findSumAtRow(row);
    ans /= this->column;
    return ans;
}

complex<double> Matrix::findAverageAtColumn(int column) {
    complex<double> ans = findSumAtColumn(column);
    ans /= this->row;
    return ans;
}

double Matrix::findMaxAtRow(int row) {
    if (this->row == 0 || this->column == 0) {
        cout << "The matrix is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < this->column; ++i) {
        ans = max(ans, this->matrix[row][column].real());
    }
    return ans;
}

double Matrix::findMaxAtColumn(int column) {
    if (this->row == 0 || this->column == 0) {
        cout << "The matrix is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < row; ++i) {
        ans = max(ans, this->matrix[i][column].real());
    }
    return ans;
}

double Matrix::findMin() {
    if (this->row == 0 || this->column == 0) {
        cout << "The matrix is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            ans = min(ans, this->matrix[i][j].real());
        }
    }
    return ans;
}

double Matrix::findMinAtRow(int row) {
    if (this->row == 0 || this->column == 0) {
        cout << "The matrix is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < this->column; ++i) {
        ans = min(ans, this->matrix[row][column].real());
    }
    return ans;
}

double Matrix::findMinAtColumn(int column) {
    if (this->row == 0 || this->column == 0) {
        cout << "The matrix is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < row; ++i) {
        ans = min(ans, this->matrix[i][column].real());
    }
    return ans;
}


