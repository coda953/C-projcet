#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "Matrix.hpp"

using namespace std;
using namespace cv;
const char *tarMatrix = "img/SunShangXiang.jpeg";
const char *test1 = "img/test1_1.png";
const char *test2 = "img/test1_2.png";

int main() {
    Mat Imagetest1 = imread(test1, IMREAD_GRAYSCALE);
    Mat Imagetest2 = imread(test2, IMREAD_GRAYSCALE);
    //change to our matrix
    Matrix<uchar> m1 = Imagetest1;
    Matrix<uchar> m2 = Imagetest2;
    Matrix<uchar> result = m1 + m2;
    result.transposition_change();
    //change to opencv mat
    Mat outImage = result.to_opencv_8UC1();
    imshow("[img]", outImage);
    waitKey(0);
    return 0;
}