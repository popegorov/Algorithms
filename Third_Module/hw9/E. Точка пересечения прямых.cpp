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

    double p_k = (p1_y - p2_y) / (p1_x - p2_x);
    double p_b = p1_y - p1_x * p_k;

    double m_k = (m1_y - m2_y) / (m1_x - m2_x);
    double m_b = m1_y - m1_x * m_k;

    if (m_k == p_k && m_b == p_b) {
        cout << 2;
    } else if (m_k == p_k) {
        cout << 0;
    } else {
        double x = (m_b - p_b) / (p_k - m_k);
        double y = p_k * x + p_b;

        cout << 1 << ' ' << x << ' ' << y;
    }

}


