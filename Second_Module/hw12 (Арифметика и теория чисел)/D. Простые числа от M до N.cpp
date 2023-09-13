#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void GetPrimes(long long m, long long n) {
    vector<long long> Primes, minDivisor(n + 1);
    size_t minPrime;
    bool flag = true;

    for (long long i = 2; i <= n; ++i) {
        if (!minDivisor[i]) {
            minDivisor[i] = i;
            Primes.push_back(i);
            if (i >= m && flag) {
                minPrime = Primes.size() - 1;
                flag = false;
            }
        }
        for (long long j = 0; j < Primes.size() && Primes[j] <= i && i * Primes[j] <= n; ++j) {
            minDivisor[i * Primes[j]] = Primes[j];
        }
    }

    for (size_t i = minPrime; i < Primes.size(); ++i) {
        cout << Primes[i] << '\n';
    }
    if (minPrime >= Primes.size()) {
        cout << "Absent";
    }
}

int main() {
    long long m, n;
    cin >> m >> n;
    GetPrimes(m, n);
}


