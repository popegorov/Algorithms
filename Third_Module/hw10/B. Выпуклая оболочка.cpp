#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    bool operator ==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point& other) const {
        return y < other.y || y == other.y && x < other.x;
    }

    int CrossProd(const Point& other) const {
        return x * other.y - y * other.x;
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

Point o;

bool HowToSort(const Point& a, const Point& b) {
    Point first = {a.x - o.x, a.y - o.y};
    Point second = {b.x - o.x, b.y - o.y};
    return first.CrossProd(second) > 0 || first.CrossProd(second) == 0 &&
            hypot(first.x, first.y) < hypot(second.x, second.y);
}

vector<Point> MakePolygon(vector<Point>& points) {
    sort(points.begin(), points.end());
    o = *points.begin();
    sort(points.begin() + 1, points.end(), HowToSort);

    vector<Point> result;
    for (auto& cur_point : points) {
        while (result.size() >= 2) {
            auto prev = result[result.size() - 2];
            auto last = result.back();
            Point first = {last.x - prev.x, last.y - prev.y};
            Point second = {cur_point.x - prev.x, cur_point.y - prev.y};
            if (first.CrossProd(second) <= 0) {
                result.pop_back();
            } else {
                break;
            }
        }
        result.push_back(cur_point);
    }

    return result;
}

double CalculatePerimeter(const vector<Point>& points) {
    double perimeter = 0;
    for (int i = 0; i < points.size(); ++i) {
        int j = (i + 1) % points.size();
        perimeter += hypot(points[i].x - points[j].x, points[i].y - points[j].y);
    }

    return perimeter;
}

double CalculateSquare(const vector<Point>& points) {
    double square = 0;
    for (int i = 0; i < points.size(); ++i) {
        int j = (i + 1) % points.size();
        square += points[i].x * points[j].y - points[i].y * points[j].x;
    }

    return abs(square / 2);
}

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
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    auto hull = MakePolygon(points);

    cout << CalculatePerimeter(hull) << endl << CalculateSquare(hull);
}


