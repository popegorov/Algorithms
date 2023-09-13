#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    long long n;
    cin >> n;
    vector<long long> values(n);
    cin >> values[0];
    for (long long i = 1; i < n; ++i) {
        long long value;
        cin >> value;
        values[i] = values[i - 1] + value;
    }

    long long q, x_0, sum = 0;
    cin >> q >> x_0;

    for (long long i = 0; i < q; ++i) {
        long long x = (11173 * x_0 + 1) % MOD;
        long long l = min(x_0 % n, x % n);
        long long r = max(x_0 % n, x % n);
        if (!l) {
            sum = (sum + values[r]) % MOD;
        } else {
            sum = (sum + values[r] - values[l - 1]) % MOD;
        }
        x_0 = (11173 * x + 1) % MOD;
    }
    cout << sum;
}
