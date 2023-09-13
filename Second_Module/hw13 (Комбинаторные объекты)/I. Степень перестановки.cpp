#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int get_power(int n) {
    vector<int> numbers(n);
    int res = 1;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    while(any_of(numbers.begin(), numbers.end(), [](int i){ return i != 0; })) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (numbers[i] != 0) {
                cur = i;
                break;
            }
        }
        int cycle_size = 0;
        while (numbers[cur]) {
            auto prev_cur = cur;
            cur = numbers[cur] - 1;
            numbers[prev_cur] = 0;
            ++cycle_size;
        }
        res *= cycle_size / gcd(res, cycle_size);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << get_power(n);
}


