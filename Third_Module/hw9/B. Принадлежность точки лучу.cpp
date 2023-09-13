#include <iostream>

using namespace std;

int main() {
    double x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

    double v1_x = x0 - x1;
    double v1_y = y0 - y1;
    double v2_x = x2 - x1;
    double v2_y = y2 - y1;

    if (!(v1_x * v2_y - v1_y * v2_x) && (v1_x * v2_x + v1_y * v2_y) >= 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
