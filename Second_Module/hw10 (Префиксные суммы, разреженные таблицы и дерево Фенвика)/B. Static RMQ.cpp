#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

class SparseTable {
    vector<vector<int>> st;

public:
    SparseTable(vector<int> &a) {
        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + (1 << level) <= a.size(); i++)
                st[level].push_back(min(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int getMin(int l, int r) {
        int level = floor(log2(r - l + 1)), levelWidth = 1 << level;
        return min(st[level][l], st[level][r - levelWidth + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<int> values(n);
    for (long long i = 0; i < n; ++i) {
        cin >> values[i];
    }
    SparseTable st(values);

    long long q, sum = 0;
    cin >> q;

    for (long long i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        sum += st.getMin(l, r);
    }
    cout << sum;
}


