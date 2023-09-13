#include <iostream>
#include <vector>

using namespace std;

int max_depth = 0;
int max_v = 0;

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph, int depth) {
    visited[v] = 1;
    if (max_depth < depth) {
        max_depth = depth;
        max_v = v;
    }
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph, depth + 1);
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


    dfs(0, visited, graph, 0);
    visited.assign(amount_v, 0);
    dfs(max_v, visited, graph, 0);

    cout << max_depth;
}


