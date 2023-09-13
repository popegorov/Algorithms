#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long MOD;

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

vector<pair<long long, long long>> Primes(long long a) {
    vector<pair<long long, long long>> primes;
    while (a != 1) {
        long long p = 2;
        bool flag = true;
        while (p * p <= a) {
            if (!(a % p)) {
                if (primes.empty() || primes.back().first != p) {
                    primes.push_back({p, 1});
                } else {
                    ++primes.back().second;
                }
                a /= p;
                flag = false;
                break;
            }
            ++p;
        }
        if (flag) {
            if (primes.empty() || primes.back().first != a) {
                primes.push_back({a, 1});
            } else {
                ++primes.back().second;
            }
            a = 1;
        }
    }
    return primes;
}

int main() {
    long long a;
    cin >> a;
    if(a == 1) {
        cout << 1;
        return 0;
    }
    auto primes = Primes(a);
    long long ans = 1, max_cnt = 0;
    for(const auto& [prime, pow]: primes) {
        max_cnt = max(max_cnt, pow);
        ans *= prime;
    }

    MOD = a;
    long long first_ans = ans;
    while(BinPow(ans, ans)) {
        ans += first_ans;
    }
    cout << ans;

}
