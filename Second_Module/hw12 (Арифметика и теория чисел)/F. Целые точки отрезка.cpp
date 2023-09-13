#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;



int main() {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << gcd(abs(x1 - x2), abs(y1 - y2)) + 1;
}
