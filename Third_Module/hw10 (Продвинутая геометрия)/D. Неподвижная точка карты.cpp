#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    double OO_x, OO_y, XO_x, XO_y,  XY_x, XY_y, OY_x, OY_y;
    cin >> OO_x >> OO_y >> XO_x >> XO_y >> XY_x >> XY_y >> OY_x >> OY_y;

    complex<double> oo(0.0, 0.0);
    complex<double> OO(OO_x, OO_y); // a'
    complex<double> xy(x, y);
    complex<double> XY(XY_x, XY_y); // b'

    auto M = -(XY * oo + OO * xy) / (oo - xy + XY - OO);
    cout << setprecision(5) << M.real() << ' ' << M.imag();
}


