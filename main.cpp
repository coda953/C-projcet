#include "Matrix.hpp"
#include "Vector.hpp"
#include <opencv.hpp>
#include <opencv_modules.hpp>

using namespace std;
using namespace cv;

int main() {
    Matrix<int> a = Matrix<int>(5, 5);
    a.show();
//    Mat mat1=Mat::ones(Size(3,2),CV_32FC1);
//    Mat mat2=Mat::zeros(Size(5,5),CV_8UC1);
//    cout<<mat1<<endl;
//    cout<<mat1.rows<<endl;
//    cout<<mat1.cols<<endl;
//    mat1.col(1).row(0)=-0.1;
//    cout<<mat1;

    return 0;
}
