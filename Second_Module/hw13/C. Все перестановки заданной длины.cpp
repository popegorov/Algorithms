#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

void print_permutations(size_t n) {
    string cur;
    for (int i = 1; i < n + 1; ++i) {
        cur += static_cast<char>('0' + i);
    }

    do {
        cout << cur << '\n';
    } while(next_permutation(cur.begin(), cur.end()));
}

int main() {
    int n;
    cin >> n;
    print_permutations(n);
}


