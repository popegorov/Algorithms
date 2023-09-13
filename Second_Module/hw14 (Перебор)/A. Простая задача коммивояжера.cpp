#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

void FindWay(vector<bool> &visited, vector<vector<int>> &graph, int last, int sum, int &ans) {
    if (all_of(visited.begin(), visited.end(), [](bool i) { return i; }) && graph[last][0]) {
        ans = min(ans, sum + graph[last][0]);
        return;
    }
    for (int i = 0; i < visited.size(); ++i) {
        if (!visited[i] && graph[i][last]) {
            visited[i] = true;
            FindWay(visited, graph, i, sum + graph[i][last], ans);
            visited[i] = false;
        }
    }
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
    int ans = 1e9;
    vector<bool> visited(n);
    visited[0] = true;
    FindWay(visited, graph, 0, 0, ans);
    if (n == 1) {
        cout << 0;
    } else if (ans == 1e9) {
        cout << -1;
    } else {
        cout << ans;
    }
}


