#include <iostream>
#include <vector>

using namespace std;

const long long INF = -1e9;

struct SegmentTree {
    SegmentTree(long long n, const vector<long long>& a) : n(n), values(4 * n) {
        for (int i = 0; i < 4 * n; ++i) {
            values[i] = {INF, i};
        }
        Build(0, 0, n - 1, a);
    }

    long long MaxIndex(long long l, long long r) {
        return Query(0, 0, n - 1, l, r).index;
    }

    void Modify(long long pos, long long value) {
        Modify(0, 0, n - 1, pos, value);
    }

private:

    struct Value {
        long long val;
        long long index;

        bool operator<(const Value& other) const {
            return (val < other.val || val == other.val && index < other.index);
        }
    };

    void Build(long long v, long long vl, long long vr, const vector<long long>& a) {
        if (vl == vr) {
            values[v] = {a[vl], vl};
            return;
        }

        long long vm = vl + (vr - vl) / 2;
        Build(2 * v + 1, vl, vm, a);
        Build(2 * v + 2, vm + 1, vr, a);
        values[v] = max(values[v * 2 + 1], values[v * 2 + 2]);
    }

    Value Query(long long v, long long vl, long long vr, long long l, long long r) {
        if (vl > r || vr < l) {
            return {INF, INF};
        }
        if (l <= vl && vr <= r) {
            return values[v];
        }
        long long vm = vl + (vr - vl) / 2;
        auto ql = Query(v * 2 + 1, vl, vm, l, r);
        auto qr = Query(v * 2 + 2, vm + 1, vr, l, r);
        return max(ql, qr);
    }

    void Modify(long long v, long long vl, long long vr, long long pos, long long val) {
        if (pos < vl || pos > vr) {
            return;
        }
        if (pos == vl && vl == vr) {
            values[v].val = val;
            return;
        }
        long long vm = vl + (vr - vl) / 2;
        Modify(v * 2 + 1, vl, vm, pos, val);
        Modify(v * 2 + 2, vm + 1, vr, pos, val);
        values[v] = max(values[v * 2 + 1], values[v * 2 + 2]);
    }

    long long n;
    vector<Value> values;
};

int main() {
    long long n;
    cin >> n;
    vector<long long> values(n);

    for (long long i = 0; i < n; ++i) {
        cin >> values[i];
    }

    SegmentTree t(n,values);

    long long m;
    cin >> m;

    for (long long i = 0; i < m; ++i) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long l, r;
            cin >> l >> r;
            cout << t.MaxIndex(l, r) << endl;
        } else {
            long long pos, value;
            cin >> pos >> value;
            t.Modify(pos, value);
        }
    }
}


