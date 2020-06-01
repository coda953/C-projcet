#include "Matrix.hpp"
#include "Vector.hpp"
#include <opencv.hpp>

using namespace std;
using namespace cv;
#define EXP 0.0001

#include "gtest/gtest.h"


vector<vector<double>> m1 = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
vector<vector<double>> m2 = {{9, 8, 7},
                             {6, 5, 4},
                             {3, 2, 1}};
vector<vector<double>> m3 = {{1,  2,  1},
                             {0,  0,  0},
                             {-1, -2, -1}};
vector<vector<double>> m4 = {{1,  2,  3,  4,},
                             {5,  6,  7,  8},
                             {9,  10, 11, 12},
                             {13, 14, 15, 16}};
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
//test calculate eigenvalue
TEST(Matrix_get_eigenvalue, task3) {
    Matrix<double> a = m1;
    vector<double> ans = a.getEigenvalue();
    double k = 0;
    sort(ans.begin(), ans.end());
    for (double an : ans) {
        k += an;
    }
    EXPECT_NEAR(ans[0], -1.1168, EXP);
    EXPECT_NEAR(ans[1], 0, EXP);
    EXPECT_NEAR(ans[2], 16.1168, EXP);
    EXPECT_NEAR(k, 15, EXP);

}
//test convolution
TEST(Matrix_convolution, task3) {
    Matrix<double> a = m4;
    Matrix<double> b = m3;
    Matrix<double> ans = a.convolution_2D(b);
    EXPECT_FLOAT_EQ(ans[0][0], -16);
    EXPECT_FLOAT_EQ(ans[0][1], -24);
    EXPECT_FLOAT_EQ(ans[0][2], -28);
    EXPECT_FLOAT_EQ(ans[0][3], -23);
    EXPECT_FLOAT_EQ(ans[1][0], -24);
    EXPECT_FLOAT_EQ(ans[1][1], -32);
    EXPECT_FLOAT_EQ(ans[1][2], -32);
    EXPECT_FLOAT_EQ(ans[1][3], -24);
    EXPECT_FLOAT_EQ(ans[2][0], -24);
    EXPECT_FLOAT_EQ(ans[2][1], -32);
    EXPECT_FLOAT_EQ(ans[2][2], -32);
    EXPECT_FLOAT_EQ(ans[2][3], -24);
    EXPECT_FLOAT_EQ(ans[3][0], 28);
    EXPECT_FLOAT_EQ(ans[3][1], 40);
    EXPECT_FLOAT_EQ(ans[3][2], 44);
    EXPECT_FLOAT_EQ(ans[3][3], 35);
}
//test inverse
TEST(Vector_cross_product,task2){
    vector<double> a={1,2};
    vector<double>b={2,3};
    Vector<double> vec1=a;
    Vector<double> vec2=b;
    Vector<double>ans=vec1.cross_product(vec2);
    EXPECT_EQ(ans[0],0);
    EXPECT_EQ(ans[1],0);
    EXPECT_EQ(ans[2],-1);
}
GTEST_API_ int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
