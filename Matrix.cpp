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
        cout << "the size of these two vector is not equal" << endl;
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
        cout << "the size of these two vector is not equal" << endl;
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
    if (this->column != other.row) {
        cout << "multiple error!" << endl;
        cout << "the left matrix column is not equal right matrix row" << endl;
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

Matrix::Matrix(int length) {
    this->row = 1;
    this->column = length;
    this->matrix.resize(this->row);
    this->matrix[0].resize(column);
}

double Matrix::findMax() {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
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
        cout << "The vector is empty,can not get sum" << endl;
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
        cout << "Input row is bigger than the vector size" << endl;
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
        cout << "Input column is bigger than the vector size" << endl;
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
        cout << "The vector is empty,can not get sum" << endl;
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
        cout << "The vector is empty,can not get sum" << endl;
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
        cout << "The vector is empty,can not get sum" << endl;
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
        cout << "The vector is empty,can not get sum" << endl;
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
        cout << "The vector is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < row; ++i) {
        ans = min(ans, this->matrix[i][column].real());
    }
    return ans;
}

Matrix Matrix::operator+(Vector other) const {
    if (this->column != other.getLength()) {
        cout << "The column of the matrix is not equal to the vector length" << endl;
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

Matrix Matrix::operator-(Vector other) const {
    if (this->column != other.getLength()) {
        cout << "The column of the matrix is not equal to the vector length" << endl;
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

int Matrix::getRow() {
    return this->row;
}

int Matrix::getColumn() {
    return this->column;
}

Matrix Matrix::transposition() {
    Matrix ans = Matrix(this->column, this->row);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            ans[j][i] = this->matrix[i][j];
        }
    }
    this->row = ans.row;
    this->column = ans.column;
    this->matrix = ans.matrix;
    return ans;
}

Matrix Matrix::conjugation() {
    Matrix ans = Matrix(this->row, this->column);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            complex<double> cur(this->matrix[i][j].real(), -this->matrix[i][j].imag());
            ans[i][j] = cur;
        }
    }
    this->matrix = ans.matrix;
    return ans;
}

Matrix Matrix::element_wise_multiplication(Matrix &other) {
    if (this->row != other.row || this->column != other.column) {
        cout << "the size of these two vector is not equal" << endl;
        cout << "left size is:";
        this->showSize();
        cout << "right size is:";
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

Vector Matrix::operator*(Vector other) const {
    if (this->column != other.getLength()) {
        cout << "Matrix * Vector error!" << endl;
        cout << "The left Matrix column is not equal right length" << endl;
        return Vector(0);
    }
    Vector ans = Vector(other.getLength());
    for (int i = 0; i < other.getLength(); ++i) {
        for (int j = 0; j < other.getLength(); ++j) {
            ans[i] += this->matrix[i][j] * other[j];
        }
    }
    return ans;
}


