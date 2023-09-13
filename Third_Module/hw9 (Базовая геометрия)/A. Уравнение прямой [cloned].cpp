#include <iostream>

using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 != x2) {
        double k = (y1 - y2) / (x1 - x2);
        double b = y1 - k * x1;
        cout << -k << ' ' << 1 << ' ' << -b;
    }
    else {
         cout << 1 << ' ' << 0 << ' ' << -x1;
    }
}
