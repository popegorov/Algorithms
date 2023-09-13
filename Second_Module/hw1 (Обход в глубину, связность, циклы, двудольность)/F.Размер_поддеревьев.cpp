#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph, vector<int>& tree_size) {
    visited[v] = 1;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph, tree_size);
            tree_size[v] += tree_size[neighbour];
        }
    }
}

int main() {
    int amount_v;
    cin >> amount_v;

    vector<vector<int>> graph(amount_v);
    vector<int> visited(amount_v);
    vector<int> tree_size(amount_v, 1);

    for (int i = 0; i < amount_v - 1; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        if (start != end) {
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
    }

    dfs(0, visited, graph, tree_size);

    for (const auto& cur_size : tree_size) {
        cout << cur_size << " ";
    }
}


