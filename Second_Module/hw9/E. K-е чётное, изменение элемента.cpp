#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
    SegmentTree(long long n, const vector<long long>& a) : n(n), values(4 * n), numbers(a) {
        Build(0, 0, n - 1, a);
    }

    long long Sum(long long l, long long r) {
        return Query(0, 0, n - 1, l, r);
    }

    void Modify(long long pos, long long value) {
        Modify(0, 0, n - 1, pos, value);
    }

    void Find(long long k) {
        Find(0, 0, n - 1, k);
    }

private:
    void Build(long long v, long long vl, long long vr, const vector<long long>& a) {
        if (vl == vr) {
            values[v] = 1 - abs(a[vl] % 2);
            return;
        }

        long long vm = vl + (vr - vl) / 2;
        Build(2 * v + 1, vl, vm, a);
        Build(2 * v + 2, vm + 1, vr, a);
        values[v] = values[v * 2 + 1] + values[v * 2 + 2];
    }

    long long Query(long long v, long long vl, long long vr, long long l, long long r) {
        if (vl > r || vr < l) {
            return 0;
        }
        if (l <= vl && vr <= r) {
            return values[v];
        }
        long long vm = vl + (vr - vl) / 2;
        long long ql = Query(v * 2 + 1, vl, vm, l, r);
        long long qr = Query(v * 2 + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void Modify(long long v, long long vl, long long vr, long long pos, long long val) {
        if (pos < vl || pos > vr) {
            return;
        }
        if (pos == vl && vl == vr) {
            values[v] = 1 - abs(val % 2);
            numbers[pos] = val;
            return;
        }
        long long vm = vl + (vr - vl) / 2;
        Modify(v * 2 + 1, vl, vm, pos, val);
        Modify(v * 2 + 2, vm + 1, vr, pos, val);
        values[v] = values[v * 2 + 1] + values[v * 2 + 2];
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
            long long k;
            cin >> k;
            t.Find(k);
        } else {
            long long pos, value;
            cin >> pos >> value;
            t.Modify(pos, value);
        }
    }
}


