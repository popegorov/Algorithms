#include <iostream>

using namespace std;

bool BelongsTo(double x0, double y0, double x1, double y1, double x2, double y2) {
    double v1_x = x0 - x1;
    double v1_y = y0 - y1;
    double v2_x = x2 - x1;
    double v2_y = y2 - y1;
    double v3_x = x0 - x2;
    double v3_y = y0 - y2;

    if (!(v1_x * v2_y - v1_y * v2_x) && (v1_x * v3_x + v1_y * v3_y) <= 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double p1_x, p1_y, p2_x, p2_y, m1_x, m1_y, m2_x, m2_y;
    cin >> p1_x >> p1_y >> p2_x >> p2_y >> m1_x >> m1_y >> m2_x >> m2_y;

    double p1p2_x = p2_x - p1_x;
    double p1p2_y = p2_y - p1_y;

    double p1m2_x = m2_x - p1_x;
    double p1m2_y = m2_y - p1_y;

    double p1m1_x = m1_x - p1_x;
    double p1m1_y = m1_y - p1_y;

    double m1p1_x = -p1m1_x;
    double m1p1_y = -p1m1_y;

    double m1m2_x = m2_x - m1_x;
    double m1m2_y = m2_y - m1_y;

    double m1p2_x = p2_x - m1_x;
    double m1p2_y = p2_y - m1_y;

    if ((p1p2_x * p1m2_y - p1m2_x * p1p2_y) * (p1p2_x * p1m1_y - p1m1_x * p1p2_y) < 0 && (m1m2_x * m1p1_y - m1p1_x * m1m2_y) * (m1m2_x * m1p2_y - m1p2_x * m1m2_y) < 0 ) {
        cout << "YES";
    } else if (BelongsTo(p1_x, p1_y, m1_x, m1_y, m2_x, m2_y) || BelongsTo(p2_x, p2_y, m1_x, m1_y, m2_x, m2_y)) {
        cout << "YES";
    } else if (BelongsTo(m1_x, m1_y, p1_x, p1_y, p2_x, p2_y) || BelongsTo(m2_x, m2_y, p1_x, p1_y, p2_x, p2_y)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}
