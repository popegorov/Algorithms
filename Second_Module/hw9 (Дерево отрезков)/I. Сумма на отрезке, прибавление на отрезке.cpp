#include <iostream>
#include <vector>

using namespace std;

const long long INF = -1e12;

struct SegmentTree {
    SegmentTree(long long n, const vector<long long>& a) : n(n), values(4 * n), add(4 * n) {
        Build(0, 0, n - 1, a);
    }

    long long Sum(long long l, long long r) {
        return Query(0, 0, n - 1, l, r);
    }

    void Modify(long long l, long long r, long long value) {
        Modify(0, 0, n - 1, l, r, value);
    }

private:
    void Push(long long v, long long vl, long long vr) {
        if (vl != vr) {
            add[v * 2 + 1] += add[v];
            add[v * 2 + 2] += add[v];
        }
        values[v] += add[v] * (vr - vl + 1);
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
        values[v] = values[v * 2 + 1] + values[v * 2 + 2];
    }

    long long Query(long long v, long long vl, long long vr, long long l, long long r) {
        Push(v, vl, vr);
        if (r < vl || vr < l)
            return 0;
        if (l <= vl && vr <= r)
            return values[v];
        long long vm = vl + (vr - vl) / 2;
        long long ql = Query(2 * v + 1, vl, vm, l, r);
        long long qr = Query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
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
        values[v] = values[v * 2 + 1] + values[v * 2 + 2];
    }

    long long n;
    vector<long long> values;
    vector<long long> add;
};

int main() {
    long long n;
    cin >> n;
    vector<long long> values(n);

    for (long long i = 0; i < n; ++i) {
        cin >> values[i];
    }

    SegmentTree t(n, values);

    long long m;
    cin >> m;

    for (long long i = 0; i < m; ++i) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long l, r;
            cin >> l >> r;
            cout << t.Sum(l, r) << endl;
        } else {
            long long l, r, value;
            cin >> l >> r >> value;
            t.Modify(l, r, value);
        }
    }
}


