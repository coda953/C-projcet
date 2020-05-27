#include "Matrix.hpp"
#include "Vector.hpp"

template<class T>
class Vector;

template<class T>
Matrix<T>::Matrix() {
    this->row = 0;
    this->column = 0;
    this->matrix.resize(0);
}

template<class T>
Matrix<T>::Matrix(int row, int column) {
    this->row = row;
    this->column = column;
    this->matrix.resize(row);
    for (int i = 0; i < row; ++i) {
        this->matrix[i].resize(column);
    }
}

template<class T>
void Matrix<T>::show() const {
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

template<class T>
int Matrix<T>::setRow(int row) {
    this->row = row;
    this->matrix.resize(row);
    return 1;
}

template<class T>
int Matrix<T>::setColumn(int column) {
    if (this->row == 0) {
        return 0;
    }
    this->column = column;
    for (int i = 0; i < row; ++i) {
        this->matrix[i].resize(column);
    }
    return 1;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix &other) const {
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

template<class T>
void Matrix<T>::showSize() const {
    cout << "Row:" << this->row << "  Column:" << this->column << endl;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix &other) const {
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

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix &other) const {
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

template<class T>
Matrix<T>::Matrix(int length) {
    this->row = 1;
    this->column = length;
    this->matrix.resize(this->row);
    this->matrix[0].resize(this->column);
}

template<class T>
T Matrix<T>::findMax() {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
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

template<class T>
T Matrix<T>::findAverage() {
    T ans = findSum();
    ans /= (row * this->column);
    return ans;
}

template<class T>
T Matrix<T>::findSum() {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
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

template<class T>
T Matrix<T>::findSumAtRow(int row) {
    if (this->row < row) {
        cout << "Input row is bigger than the vector size" << endl;
        return 0;
    }
    T ans = 0;
    for (int i = 0; i < column; ++i) {
        ans += this->matrix[row][i];
    }
    return ans;
}

template<class T>
T Matrix<T>::findSumAtColumn(int column) {
    if (this->column < column) {
        cout << "Input column is bigger than the vector size" << endl;
        return 0;
    }
    T ans = 0;
    for (int i = 0; i < this->row; ++i) {
        ans += this->matrix[column][i];
    }
    return ans;
}

template<class T>
T Matrix<T>::findAverageAtRow(int row) {
    T ans = findSumAtRow(row);
    ans /= this->column;
    return ans;
}

template<class T>
T Matrix<T>::findAverageAtColumn(int column) {
    T ans = findSumAtColumn(column);
    ans /= this->row;
    return ans;
}

template<class T>
T Matrix<T>::findMaxAtRow(int row) {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < this->column; ++i) {
        ans = max(ans, this->matrix[row][this->column].real());
    }
    return ans;
}

template<class T>
T Matrix<T>::findMaxAtColumn(int column) {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < row; ++i) {
        ans = max(ans, this->matrix[i][column]);
    }
    return ans;
}

template<class T>
T Matrix<T>::findMin() {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
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

template<class T>
T Matrix<T>::findMinAtRow(int row) {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < this->column; ++i) {
        ans = min(ans, this->matrix[row][this->column].real());
    }
    return ans;
}

template<class T>
T Matrix<T>::findMinAtColumn(int column) {
    if (this->row == 0 || this->column == 0) {
        cout << "The vector is empty,can not get sum" << endl;
        return 0;
    }
    double ans = this->matrix[0][0].real();
    for (int i = 0; i < row; ++i) {
        ans = min(ans, this->matrix[i][column]);
    }
    return ans;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Vector<T> other) const {
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

template<class T>
Matrix<T> Matrix<T>::operator-(Vector<T> other) const {
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

template<class T>
int Matrix<T>::getRow() {
    return this->row;
}

template<class T>
int Matrix<T>::getColumn() {
    return this->column;
}

template<class T>
Matrix<T> Matrix<T>::transposition_change() {
    Matrix ans = this->transposition();
    this->row = ans.row;
    this->column = ans.column;
    this->matrix = ans.matrix;
    return ans;
}

template<class T>
Matrix<T> Matrix<T>::conjugation_change() {
    Matrix ans = this->conjugation();
    this->matrix = ans.matrix;
    return ans;
}

template<class T>
Matrix<T> Matrix<T>::element_wise_multiplication(Matrix &other) {
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

template<class T>
Vector<T> Matrix<T>::operator*(Vector<T> other) const {
    if (this->column != other.getLength()) {
        cout << "Matrix * Vector error!" << endl;
        cout << "The left Matrix column is not equal right length" << endl;
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

template<class T>
Matrix<T> Matrix<T>::transposition() {
    Matrix ans = Matrix(this->column, this->row);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            ans[j][i] = this->matrix[i][j];
        }
    }
    return ans;
}

template<class T>
Matrix<T> Matrix<T>::conjugation() {
    Matrix ans = Matrix(this->row, this->column);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            T cur(this->matrix[i][j].real(), -this->matrix[i][j].imag());
            ans[i][j] = cur;
        }
    }
    return ans;
}

template<class T>
Matrix<T> Matrix<T>::reshape(int row, int column) {
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

template<class T>
Matrix<T> Matrix<T>::reshape_change(int row, int column) {
    Matrix ans = this->reshape(row, column);
    this->row = row;
    this->column = column;
    this->matrix = ans.matrix;
    return ans;
}

template<class T>
Matrix<T>::Matrix(Matrix const &other) {
    this->row = other.row;
    this->column = other.column;
    this->matrix = other.matrix;
}

template<class T>
Vector<T> Matrix<T>::slicing(int from, int to) {
    Matrix cur = this->reshape(1, this->row * this->column);
    if (to > cur.column) {
        cout << "slicing error" << endl;
        cout << "slicing bound is large than matrix size" << endl;
        return Vector<T>(0);
    }
    if (from < 0) {
        cout << "slicing error" << endl;
        cout << "slicing left bound is little than 0" << endl;
        return Vector<T>(0);
    }
    Vector<T> ans = Vector<T>(to - from);
    for (int i = 0; i < ans.getLength(); ++i) {
        ans[i] = cur.matrix[0][from + i];
    }
    return ans;
}

template<class T>
Matrix<T>::Matrix(Vector<T> other) {
    Matrix ans = Matrix(1, other.getLength());
    for (int i = 0; i < other.getLength(); ++i) {
        ans[0][i] = other[i];
    }
    this->row = ans.row;
    this->column = ans.column;
    this->matrix = ans.matrix;
}

template<class T>
Matrix<T> Matrix<T>::element_wise_multiplication_change(Matrix &other) {
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
    this->row = ans.row;
    this->column = ans.column;
    this->matrix = ans.matrix;
    return ans;
}

template<class T>
T Matrix<T>::cal_traces() {
    T ans(0, 0);
    int cur = min(this->row, this->column);
    for (int i = 0; i < cur; ++i) {
        ans += this->matrix[i][i];
    }
    return ans;
}

template<class T>
vector<T> &Matrix<T>::operator[](int i) {
    if (i >= row) {
        cout << "the input row is lager than row";
    }
    return this->matrix[i];
}





