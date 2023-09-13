#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

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
    long long n, k, ans = 1e9;
    cin >> n >> k;

    auto primes = Primes(k);
    for (auto [prime, pow] : primes) {
        long long cur_ans = 0;
        long long cur_prime = prime;
        while(n >= cur_prime) {
            cur_ans += n / cur_prime;
            cur_prime *= prime;
        }
        cur_ans /= pow;
        ans = min(cur_ans, ans);
    }
    cout << ans;
}


