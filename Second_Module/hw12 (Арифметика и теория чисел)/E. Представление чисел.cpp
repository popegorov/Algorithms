#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void Get2Numbers(long long m) {
    long long p = 2;
    while(p * p <= m) {
        if (!(m % p)) {
            break;
        }
        ++p;
    }
    if (p * p > m) {
        cout << 1 << ' ' << m - 1;
        return;
    }
    cout << m / p << ' ' << m - m / p;
}

int main() {
    long long a;
    cin >> a;
    Get2Numbers(a);
}


