#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph, vector<int>& top_sort) {
    visited[v] = 1;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph, top_sort);
        } else if (visited[neighbour] == 1) {
            cout << -1;
            exit(0);
        }
    }
    visited[v] = 2;
    top_sort.push_back(v);
}

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;

    vector<int> visited(amount_v);
    vector<vector<int>> graph(amount_v);

    for (int i = 0; i < amount_e; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        graph[start].push_back(end);
    }
    
    vector<int> top_sort;
    for (int i = 0; i < amount_v; ++i) {
        if (!visited[i]) {
            dfs(i, visited, graph, top_sort);
        }
    }

    reverse(top_sort.begin(), top_sort.end());
    for (const auto& elem : top_sort) {
        cout << elem + 1 << ' ';
    }
}


