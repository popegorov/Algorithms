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

void get_permutation(size_t n, size_t cnt) {
    vector<int> numbers(n);
    iota(numbers.begin(), numbers.end(), 1);

    while (cnt != 0) {
        auto cur_fact = factorial(n - 1);
        int cur = cnt / cur_fact;
        cout << numbers[cur] << ' ';
        for(int i = cur; i < numbers.size() - 1; ++i) {
            numbers[i] = numbers[i + 1];
        }
        numbers.pop_back();
        cnt %= cur_fact;
        --n;
    }
    for(const auto& elem : numbers) {
        cout << elem << ' ';
    }
}

int main() {
    size_t n, cnt;
    cin >> n >> cnt;
    --cnt;
    get_permutation(n, cnt);
}


