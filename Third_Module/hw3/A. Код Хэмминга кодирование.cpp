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

void HammingCode (const string& code) {
    int p = 1;
    while (p <= log2(code.size() + p)) {
        ++p;
    }

    string ans;

    int cnt = 1;
    for (int i = 1, j = 0; i < code.size() + p + 1; ++i, ++j) {
        if (cnt == i) {
            ans += 'x';
            cnt *= 2;
            --j;
        } else {
            ans += code[j];
        }
    }

    for (int i = 0; i < p; ++i) {
        auto step = BinPow(2, i);
        auto bit = 0;
        for (int j = step; j < ans.size(); ++j) {
            if (((j + 1) & step)) {
                bit += ans[j];
            }
        }
        ans[step - 1] = (bit%2 ? '1' : '0');
    }

    cout << ans;
}

int main() {
    string code;
    cin >> code;
    HammingCode(code);
}


