#include "Matrix.hpp"

using namespace std;

int main() {
    Matrix x = Matrix(3, 4);
    Matrix y = Matrix(3, 4);
    double c = 0.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            x[i][j] = ++c;
            y[i][j] = ++c;
        }
    }
    Matrix a;
    Matrix k = Matrix(10);
    a = x + y;
    a.show();
    x.setRow(2);
    a = x + y;
    a.show();
    complex<double> i = x.findSumAtRow(1);
    return 0;
}
