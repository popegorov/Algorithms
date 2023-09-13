#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph) {
    visited[v] = 1;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph);
        }
    }
}

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;

    vector<vector<int>> graph(amount_v);
    vector<int> visited(amount_v);
    vector<int> from(amount_v, -1);

    for (int i = 0; i < amount_e; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        if (start != end) {
            graph[end].push_back(start);
        }
    }

    dfs(0, visited, graph);

    for (int i = 0; i < amount_v; ++i) {
        if (visited[i]) {
            cout << i + 1 << ' ';
        }
    }
}


