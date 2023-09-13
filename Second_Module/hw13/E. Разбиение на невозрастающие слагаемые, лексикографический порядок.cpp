#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

void print_sum(int sum, vector<int>& prefix) {
    if (sum == 0) {
        for (const auto& elem : prefix) {
            cout << elem << ' ';
        }
        cout << '\n';
    } else {
        for (int i = 1; i < sum + 1; ++i) {
            if (prefix.empty() || prefix.back() >= i) {
                prefix.push_back(i);
                print_sum(sum - i, prefix);
                prefix.pop_back();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> prefix;
    print_sum(n, prefix);
}


