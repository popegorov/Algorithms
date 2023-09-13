#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph, vector<int>& tree_size, vector<vector<int>>& tree_sizes) {
    visited[v] = 1;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph, tree_size, tree_sizes);
            tree_size[v] += tree_size[neighbour];
            tree_sizes[v].push_back(tree_size[neighbour]);
        }
    }
}

int main() {
    int amount_v;
    cin >> amount_v;

    vector<vector<int>> graph(amount_v);

    for (int i = 0; i < amount_v - 1; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }


    vector<int> visited(amount_v);
    vector<int> tree_size(amount_v, 1);
    vector<vector<int>> tree_sizes(amount_v);
    dfs(0, visited, graph, tree_size, tree_sizes);
    for (int i = 0; i < amount_v; ++i) {
        bool is_correct = true;
        if (graph[i].size() > 1) {
            for (const auto& neighbour: tree_sizes[i]) {
                if (neighbour != static_cast<double>(amount_v - 1) / graph[i].size()) {
                    is_correct = false;
                }
            }

            if (is_correct) {
                cout << i + 1;
                exit(0);
            }
        }
    }
    cout << -1;
}


