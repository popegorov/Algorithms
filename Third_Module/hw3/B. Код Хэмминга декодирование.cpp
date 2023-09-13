#include <cmath>
#include <iostream>
#include <string>

using namespace std;

long long BinPow(long long x, long long pow) {
    if (!pow) {
        return 1;
    } else if (!pow % 2) {
        auto new_x = BinPow(x, pow / 2);
        return new_x * new_x;
    } else {
        return x * BinPow(x, pow - 1);
    }
}

void HammingDecode (const string& code) {
    int p = ceil(log2(code.size() + 1));

    string ans;

    int pos = -1;
    for (int i = 0; i < p; ++i) {
        auto step = BinPow(2, i);
        auto bit = (code[step - 1] % 2);
        for (int j = step; j < code.size(); ++j) {
            if (((j + 1) & step)) {
                bit += (code[j] % 2);
            }
        }
        if (bit % 2) {
            pos += step;
        }
    }

    if (pos == -1) {
        int cur_step = 1;
        for (int i = 1; i < code.size() + 1; ++i) {
            if (cur_step == i) {
                cur_step *= 2;
            } else {
                ans += code[i - 1];
            }
        }
    } else {
        int cur_step = 1;
        for (int i = 1; i < code.size() + 1; ++i) {
            if (cur_step == i) {
                cur_step *= 2;
            } else if (i - 1 == pos && code[pos] == '0') {
                ans += '1';
            } else if (i - 1 == pos) {
                ans += '0';
            } else {
                ans += code[i - 1];
            }
        }
    }

    cout << ans;
}

int main() {
    string code;
    cin >> code;
    HammingDecode(code);
}


