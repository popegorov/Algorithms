#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int factorial(int n, int k, int cnt) {
    int res = 1;
    for (int i = n - k + 1; i < n - cnt; ++i) {
        res *= i;
    }
    return res;
}

int get_number(int n, int k) {
    vector<int> numbers(k);
    for (int i = 0; i < k; ++i) {
        cin >> numbers[i];
    }
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res += factorial(n, k, i) * (numbers[i] - 1);
        for (int j = i + 1; j < k; ++j) {
            if (numbers[j] > numbers[i]) {
                --numbers[j];
            }
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << get_number(n, k);
}


