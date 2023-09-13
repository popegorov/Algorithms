#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9;

long long BinPow(long long x, long long n) {
    if (!n) {
        return 1;
    }
    if (n % 2) {
        return x * BinPow(x, n - 1) % MOD;
    }
    long long x2 = BinPow(x, n / 2) % MOD;
    return x2 * x2 % MOD;
}

int main() {
    long long x, n, p;
    cin >> x >> n >> p;
    MOD = p;
    cout << BinPow(x, n);
}



