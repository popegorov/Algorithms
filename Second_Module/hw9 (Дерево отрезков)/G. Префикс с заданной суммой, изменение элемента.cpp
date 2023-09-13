#include <iostream>
#include <vector>

using namespace std;

const long long INF = -1e12;

struct SegmentTree {
    SegmentTree(long long n, const vector<long long>& a) : n(n), values(4 * n), numbers(a), add(4 * n) {
        Build(0, 0, n - 1, a);
    }

    long long MinPrefSum(long long s) {
        return Query(0, 0, n - 1, s);
    }

    void Modify(long long pos, long long value) {
        Modify(0, 0, n - 1, pos, n - 1, value);
    }

private:
    void Push(long long v, long long vl, long long vr) {
        if (vl != vr) {
            add[v * 2 + 1] += add[v];
            add[v * 2 + 2] += add[v];
        }
        values[v] += add[v];
        add[v] = 0;
    }

    void Build(long long v, long long vl, long long vr, const vector<long long>& a) {
        if (vl == vr) {
            values[v] = a[vl];
            return;
        }

        long long vm = vl + (vr - vl) / 2;
        Build(2 * v + 1, vl, vm, a);
        Build(2 * v + 2, vm + 1, vr, a);
        values[v] = max(values[v * 2 + 1], values[v * 2 + 2]);
    }

    long long Query(long long v, long long vl, long long vr, long long s) {
        Push(v, vl, vr);
        if (values[v] < s) {
            return INF;
        }
        if (vl == vr) {
            return vl + 1;
        }
        long long vm = vl + (vr - vl) / 2;
        if (values[v * 2 + 1] + add[v * 2 + 1] >= s) {
            return Query(v * 2 + 1, vl, vm, s);
        }
        if (values[v * 2 + 2] + add[v * 2 + 2] >= s) {
            return Query(v * 2 + 2, vm + 1, vr, s);
        }
    }

    void Modify(long long v, long long vl, long long vr, long long l, long long r, long long val) {
        Push(v, vl, vr);
        if (r < vl || l > vr) {
            return;
        }
        if (l <= vl && vr <= r) {
            add[v] += val;
            Push(v, vl, vr);
            return;
        }
        long long vm = vl + (vr - vl) / 2;
        Modify(v * 2 + 1, vl, vm, l, r, val);
        Modify(v * 2 + 2, vm + 1, vr, l, r, val);
        values[v] = max(values[v * 2 + 1], values[v * 2 + 2]);
    }

    void Find(long long v, long long vl, long long vr, long long k) {
        if (k > values[v]) {
            cout << "NONE" << endl;
            return;
        }
        if (vl == vr && k == 1) {
            cout << numbers[vl] << endl;
            return;
        }
        auto vm = vl + (vr - vl) / 2;
        if (values[v * 2 + 1] < k) {
            Find(v * 2 + 2, vm + 1, vr, k - values[v * 2 + 1]);
        } else {
            Find(v * 2 + 1, vl, vm, k);
        }
    }

    long long n;
    vector<long long> values;
    vector<long long> numbers;
    vector<long long> add;
};

int main() {
    long long n;
    cin >> n;
    vector<long long> values(n);
    vector<long long> pref_sums(n);

    cin >> values[0];
    pref_sums[0] = values[0];
    for (long long i = 1; i < n; ++i) {
        cin >> values[i];
        pref_sums[i] += pref_sums[i - 1] + values[i];
    }

    SegmentTree t(n,pref_sums);

    long long m;
    cin >> m;

    for (long long i = 0; i < m; ++i) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long s;
            cin >> s;
            if (!s) {
                cout << 0 << endl;
                continue;
            }
            auto res = t.MinPrefSum(s);
            if (res != INF) {
                cout << res << endl;
            } else {
                cout << "NONE" << endl;
            }
        } else {
            long long pos, value;
            cin >> pos >> value;
            t.Modify(pos, value - values[pos]);
            values[pos] = value;
        }
    }
}
