#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    bool operator ==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool OnSegment(const Point& p1, const Point& p2) const {

        int v1_x = x - p1.x;
        int v1_y = y - p1.y;
        int v2_x = p2.x - p1.x;
        int v2_y = p2.y - p1.y;
        int v3_x = x - p2.x;
        int v3_y = y - p2.y;

        if (!(v1_x * v2_y - v1_y * v2_x) && (v1_x * v3_x + v1_y * v3_y) <= 0) {
            return true;
        } else {
            return false;
        }
    }
};

bool InPolygon (int n, Point& p, vector<Point>& points) {
    bool answer = false;

    for (int j = 0; j < n; ++j) {
        int i = (j + 1) % n;

        if ((points[i].y <= p.y && p.y < points[j].y || points[j].y <= p.y && p.y < points[i].y) &&
            (p.x > (points[j].x - points[i].x) * (p.y - points[i].y) / (points[j].y - points[i].y) + points[i].x)) {
            answer = !answer;
        }
    }

    return answer;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    Point p = {x, y};

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    for (const auto& point : points) {
        if (point == p) {
            cout << "YES";
            return 0;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if (p.OnSegment(points[i], points[j])) {
            cout << "YES";
            return 0;
        }
    }

    if (InPolygon(n, p, points)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
