#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

size_t factorial(size_t n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

size_t Quantity(int n, int k) {
    size_t res = 1;
    if (k > n / 2) {
        for (int i = k + 1; i < n + 1; ++i) {
            res *= i;
        }
        return res / factorial(n - k);
    } else {
        for (int i = n - k + 1; i < n + 1; ++i) {
            res *= i;
        }
        return res / factorial(k);
    }
}

void print_combinations(int n, int k) {
    auto quantity = Quantity(n, k);
    vector<int> cur(k);
    iota(cur.begin(), cur.end(), 1);
    for (size_t i = 0; i < quantity - 1; ++i) {
        for (const auto& elem : cur) {
            cout << elem << ' ';
        }
        cout << '\n';
        int s = k - 1;
        while (cur[s] == n - k + s + 1) {
            --s;
        }
        ++cur[s];
        for (int j = s + 1; j < k; ++j) {
            cur[j] = cur[j - 1] + 1;
        }
    }
    for (const auto& elem : cur) {
        cout << elem << ' ';
    }
    cout << '\n';
}

int main() {
    size_t n, k;
    cin >> n >> k;
    print_combinations(n, k);
}


