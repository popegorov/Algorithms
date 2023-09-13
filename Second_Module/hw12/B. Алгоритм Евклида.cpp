#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long a, long long b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    if (a) {
        return a;
    }
    return b;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << GCD(a, b);
}


