#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    int n, m, r;

    cin >> n >> m >> r;

    vector<Point> candles(n);
    for (int i = 0; i < n; ++i) {
        cin >> candles[i].x >> candles[i].y;
    }

    vector<string> coordinates(n);
    for (int j = 0; j < m; ++j) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int i = 0; i < n; ++i) {
            int value = a * candles[i].x + b * candles[i].y + c;
            if (value > 0) {
                coordinates[i].push_back('1');
            } else {
                coordinates[i].push_back('0');
            }
        }
    }

    sort(coordinates.begin(), coordinates.end());

    for (int i = 1; i < n; ++i) {
        if (coordinates[i] == coordinates[i - 1]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}


