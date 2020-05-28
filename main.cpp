#include "Matrix.hpp"
#include "Vector.hpp"
#include <opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Matrix<double> a = Matrix<double>(5, 5);
    a.show();
    Mat mat1 = Mat::ones(Size(3, 2), CV_32FC1);
    Mat mat2 = Mat::ones(Size(5, 5), CV_8UC1);
    cout << mat1 << endl;
    cout << mat1.rows << endl;
    cout << mat1.cols << endl;
    mat1.col(1).row(0) = -0.1;
    cout << mat1;
    a = mat1;
    a.show();
    Matrix<int> b = mat2;
    b.show();
    Mat mat3 = a.to_opencv_32FC1();
    cout << mat3;
}
