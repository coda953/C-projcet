#include "Matrix.hpp"
#include "Vector.hpp"
using namespace std;

int main() {
    Matrix x = Matrix(3, 3);
    Matrix y = Matrix(3, 3);
    complex<double> c(1, 0);
    complex<double> d(9, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            x[i][j] = c;
            y[i][j] = d;
            c += 1;
            d -= 1;
        }
    }
    Matrix o = x * y;
    o.show();
    Matrix a;
    Matrix k = Matrix(10);
    a = x + y;
    a.show();
//    x.setRow(2);
//    a = x + y;
//    a.show();
    complex<double> i = x.findSumAtRow(1);
    Vector t = Vector(3);
    t[0] = 1;
    t[1] = 2;
    t[2] = 3;
    t = 2 * t;
    t.show();
    Matrix b = a.conjugation();
    a.show();
    b.show();
    return 0;
}
