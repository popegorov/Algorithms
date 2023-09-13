#include <iostream>
#include <vector>

using namespace std;

struct BIT2D {
    BIT2D(long long h, long long w) : phones(h, vector<long long>(w)), height(h), width(w) {}

    void Modify(long long x, long long y, long long val) {
        for (long long cur_y = y; cur_y < height; cur_y |= (cur_y + 1)) {
            for (long long cur_x = x; cur_x < width; cur_x |= (cur_x + 1)) {
                phones[cur_y][cur_x] += val;
            }
        }
    }

    long long Sum(long long xl, long long yl, long long xr, long long yr) {
        long long res = Query(xr, yr);
        if (yl) {
            res -= Query(xr, yl - 1);
        }
        if (xl) {
            res -= Query(xl - 1, yr);
        }
        if (xl && yl) {
            res += Query(xl - 1, yl - 1);
        }
        return res;
    }


private:
    vector<vector<long long>> phones;
    long long height;
    long long width;

    long long Query(long long xr, long long yr) {
        long long res = 0;

        for (long long y = yr; y >= 0; y = (y & (y + 1)) - 1) {
            for (long long x = xr; x >= 0; x = (x & (x + 1)) - 1) {
                res += phones[y][x];
            }
        }

        return res;
    }
};

int main() {
    long long type, s;
    cin >> type >> s;
    BIT2D fen(s, s);
    while (type != 3) {
        cin >> type;
        if (type == 1) {
            long long x, y, val;
            cin >> x >> y >> val;
            fen.Modify(x, y, val);
        } else if (type == 2) {
            long long l, b, r, t;
            cin >> l >> b >> r >> t;
            cout << fen.Sum(l, b, r, t) << endl;
        }
    }
}


