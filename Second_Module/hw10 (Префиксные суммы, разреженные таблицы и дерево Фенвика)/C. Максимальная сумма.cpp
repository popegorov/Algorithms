#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, sum = 0, ans, min_sum = 0;
    cin >> n;
    bool flag = true;
    for (long long i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (flag) {
            ans = a;
            flag = false;
        }
        sum += a;
        ans = max(sum - min_sum, ans);
        min_sum = min(min_sum, sum);
    }

    cout << ans;

}


