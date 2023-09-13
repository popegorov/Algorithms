#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 16714589;

class SparseTable {
    vector<vector<long long>> st;

public:
    SparseTable(vector<long long> &a) {
        st.push_back(a);
        for (long long level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (long long i = 0; i + (1 << level) <= a.size(); i++)
                st[level].push_back(min(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    long long getMin(long long l, long long r) {
        long long level = floor(log2(r - l + 1)), levelWidth = 1 << level;
        return min(st[level][l - 1], st[level][r - levelWidth]);
    }
};

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    vector<long long> values = {a};
    for (long long i = 1; i < n; ++i) {
        a = (23 * a + 21563) % MOD;
        values.push_back(a);
    }
    SparseTable st(values);

    long long u, v, prev_u, prev_v;
    cin >> u >> v;
    long long ans = st.getMin(min(u, v), max(u, v));
    for (long long i = 1; i < m; ++i) {
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
        ans = st.getMin(min(u, v), max(u, v));
    }
    cout << u << ' ' << v << ' ' << ans;
}


