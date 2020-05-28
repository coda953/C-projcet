#include "Matrix.hpp"
#include "Vector.hpp"
#include <opencv.hpp>

using namespace std;
using namespace cv;

#include "gtest/gtest.h"

vector<vector<double>> m1 = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
vector<vector<double>> m2 = {{9, 8, 7},
                             {6, 5, 4},
                             {3, 2, 1}};
TEST(test1, ok) {
    EXPECT_EQ(1, 2 - 1);
}
//init a Matrix by vector<vector<double>>
TEST(Matrix_init_vector, test) {
    Matrix<double> a = m1;
    Matrix<double> b = m2;
    EXPECT_EQ(a.getRow(), 3);
    EXPECT_EQ(a.getColumn(), 3);
    EXPECT_EQ(b.getRow(), 3);
    EXPECT_EQ(b.getColumn(), 3);
    int count = 1;
    for (int i = 0; i < a.getRow(); ++i) {
        for (int j = 0; j < a.getColumn(); ++j) {
            EXPECT_EQ(a[i][j], count);
            count++;
        }
    }
    for (int i = 0; i < a.getRow(); ++i) {
        for (int j = 0; j < a.getColumn(); ++j) {
            count--;
            EXPECT_EQ(b[i][j], count);
        }
    }
}
//matrix + matrix
TEST(Matrix_add_matrix, overload_plus) {
    Matrix<int> a = Matrix<int>(3, 3);
    Matrix<int> b = Matrix<int>(3, 3);
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = count;
            b[i][j] = 100 - count;
            count++;
        }
    }
    Matrix<int> c;
    c = a + b;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(c[i][j], 100);
        }
    }
}
//find min max in the matrix
TEST(Matrix_find_max_and_min, task4) {
    Matrix<double> a = m1;
    Matrix<double> b = m2;
    EXPECT_EQ(a.findMax(), 9);
    EXPECT_EQ(b.findMax(), 9);
    EXPECT_EQ(a.findMin(), 1);
    EXPECT_EQ(b.findMin(), 1);
    EXPECT_EQ(a.findMaxAtRow(0), 3);
    EXPECT_EQ(a.findMaxAtRow(1), 6);
    EXPECT_EQ(a.findMaxAtRow(2), 9);
    EXPECT_EQ(a.findMinAtRow(0), 1);
    EXPECT_EQ(a.findMinAtRow(1), 4);
    EXPECT_EQ(a.findMinAtRow(2), 7);
    EXPECT_EQ(a.findMaxAtColumn(0), 7);
    EXPECT_EQ(a.findMaxAtColumn(1), 8);
    EXPECT_EQ(a.findMaxAtColumn(2), 9);
    EXPECT_EQ(a.findMinAtColumn(0), 1);
    EXPECT_EQ(a.findMinAtColumn(1), 2);
    EXPECT_EQ(a.findMinAtColumn(2), 3);
    EXPECT_EQ(b.findMaxAtRow(0), 9);
    EXPECT_EQ(b.findMaxAtRow(1), 6);
    EXPECT_EQ(b.findMaxAtRow(2), 3);
    EXPECT_EQ(b.findMaxAtColumn(0), 9);
    EXPECT_EQ(b.findMaxAtColumn(1), 8);
    EXPECT_EQ(b.findMaxAtColumn(2), 7);

}
//find average in the matrix
TEST(Matrix_find_average, task4) {
    Matrix<double> a = m1;
    EXPECT_EQ(a.findAverage(), 5);
    EXPECT_EQ(a.findAverageAtRow(0), 2);
    EXPECT_EQ(a.findAverageAtRow(1), 5);
    EXPECT_EQ(a.findAverageAtRow(2), 8);
    EXPECT_EQ(a.findAverageAtColumn(0), 4);
    EXPECT_EQ(a.findAverageAtColumn(1), 5);
    EXPECT_FLOAT_EQ(a.findAverageAtColumn(2), 6);
}
//find sum in the matrix
TEST(Matrix_find_sum, task4) {
    Matrix<double> a = m1;
    EXPECT_EQ(a.findSum(), 45);
    EXPECT_EQ(a.findSumAtRow(0), 6);
    EXPECT_EQ(a.findSumAtRow(1), 15);
    EXPECT_EQ(a.findSumAtRow(2), 24);
    EXPECT_EQ(a.findSumAtColumn(0), 12);
    EXPECT_EQ(a.findSumAtColumn(1), 15);
    EXPECT_FLOAT_EQ(a.findSumAtColumn(2), 18);
}

GTEST_API_ int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
//int main() {
//    Matrix<double> a = Matrix<double>(5, 5);
//    a.show();
//    Mat mat1 = Mat::ones(Size(3, 2), CV_32FC1);
//    Mat mat2 = Mat::ones(Size(5, 5), CV_8UC1);
//    cout << mat1 << endl;
//    cout << mat1.rows << endl;
//    cout << mat1.cols << endl;
//    mat1.col(1).row(0) = -0.1;
//    cout << mat1;
//    a = mat1;
//    a.show();
//    Matrix<int> b = mat2;
//    b.show();
//    Mat mat3 = a.to_opencv_32FC1();
//    cout << mat3;
//}
