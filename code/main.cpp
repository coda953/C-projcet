#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "Matrix.hpp"

using namespace std;
using namespace cv;
const char *tarMatrix = "img/SunShangXiang.jpeg";

int main() {
    Mat srcImage = imread(tarMatrix, IMREAD_GRAYSCALE);
    //change to our matrix
    Matrix<uchar> ourMatrix = srcImage;
    //change to opencv mat
    Mat outImage = ourMatrix.to_opencv_8UC1();
    imshow("[img]", outImage);
    waitKey(0);
    return 0;
}