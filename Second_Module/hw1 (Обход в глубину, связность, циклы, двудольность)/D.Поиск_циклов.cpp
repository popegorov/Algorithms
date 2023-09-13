#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int> &visited, vector<int> &from, vector<vector<int>> &graph) {
    visited[v] = 1;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            from[neighbour] = v;
            dfs(neighbour, visited, from, graph);
        } else if (visited[neighbour] == 1 && from[v] != neighbour) {
            vector<int> cycle = {neighbour};
            for (int cycle_v = v; cycle_v != neighbour; cycle_v = from[cycle_v]) {
                cycle.push_back(cycle_v);
            }
            reverse(cycle.begin(), cycle.end());
            cout << "YES" << endl << cycle.size() << endl;
            for (const auto &cycle_v: cycle) {
                cout << cycle_v + 1 << " ";
            }
            exit(0);
        }
    }
    visited[v] = 2;
}

int main() {
    int amount_v;
    cin >> amount_v;

    vector<vector<int>> graph(amount_v);
    vector<int> visited(amount_v);
    vector<int> from(amount_v, -1);
    for (int i = 0; i < amount_v; ++i) {
        for (int j = 0; j < amount_v; ++j) {
            int is_edge;
            cin >> is_edge;
            if (is_edge) {
                graph[i].push_back(j);
            }
        }
    }
    vector<int> cycle;

    for (int i = 0; i < amount_v; ++i) {
        if (!visited[i]) {
            dfs(i, visited, from, graph);
        }
    }

    cout << "NO";
}


