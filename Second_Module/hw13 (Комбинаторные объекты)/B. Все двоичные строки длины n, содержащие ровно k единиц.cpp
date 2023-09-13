#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

void print_binary(int bits_count, int ones_count) {
    string cur;
    for (int i = 0; i < bits_count; ++i) {
        if (i < bits_count - ones_count) {
            cur += '0';
        } else {
            cur += '1';
        }
    }

    do {
        cout << cur << '\n';
    } while(next_permutation(cur.begin(), cur.end()));
}

int main() {
    int n, k;
    cin >> n >> k;
    print_binary(n, k);
}


