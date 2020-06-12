#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main() {
    Mat srcImage = imread("img/usage.png");
    imshow("[img]", srcImage);
    waitKey(0);
    return 0;
}