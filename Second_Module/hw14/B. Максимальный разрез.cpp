#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

void print_binary(size_t bits_count) {
    for(int i = 0; i < (1<<bits_count); ++i) {
        for(size_t bit = bits_count; bit > 0; --bit) {
            if ((i & (1<<(bit - 1)))) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}

pair<int, int> get_max(int n, vector<vector<int>>& graph) {
    int max_result = 0, max_i = -1;
    for (int i = 0; i < (1 << n); ++i) {
        int cur_result = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                auto a1 = i & (1 << j);
                auto a2 = i & (1 << k);
                if (a1 && !a2 || !a1 && a2) {
                    cur_result += graph[j][k];
                }
            }
        }
        if (cur_result > max_result) {
            max_result = cur_result;
            max_i = i;
        }
    }
    return {max_result, max_i};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    auto ans = get_max(n, graph);
    cout << ans.first << endl;
    for (int i = 0; i < n; ++i) {
        if (ans.second & (1 << i)) {
            cout << 2 << ' ';
        } else {
            cout << 1 << ' ';
        }
    }
}


