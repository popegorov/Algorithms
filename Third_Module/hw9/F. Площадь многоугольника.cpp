#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    double prev_x, prev_y;
    cin >> prev_x >> prev_y;
    auto first_x = prev_x;
    auto first_y = prev_y;
    int square = 0;
    for (int i = 1; i < n; ++i) {
        int cur_x, cur_y;
        cin >> cur_x >> cur_y;

        square += prev_x * cur_y - prev_y * cur_x;

        prev_x = cur_x;
        prev_y = cur_y;
        if (i == n - 1) {
            square += cur_x * first_y - cur_y * first_x;
        }
    }
    cout << fixed << abs(static_cast<double>(square) / 2);
}
