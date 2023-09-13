#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Primes(long long a) {
    while (a != 1) {
        long long p = 2;
        bool flag = true;
        while (p * p <= a) {
            if (!(a % p)) {
                cout << p << ' ';
                a /= p;
                flag = false;
                break;
            }
            ++p;
        }
        if (flag) {
            cout << a << ' ';
            a = 1;
        }
    }
}

int main() {
    long long a;
    cin >> a;
    Primes(a);
}


