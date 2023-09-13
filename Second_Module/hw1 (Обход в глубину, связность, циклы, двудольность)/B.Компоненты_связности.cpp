#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<int>& visited, vector<vector<int>>& graph, int amount_cc) {
    visited[v] = amount_cc;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            visited[v] = amount_cc;
            dfs(neighbour, visited, graph, amount_cc);
        }
    }
}

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;

    vector<vector<int>> graph(amount_v);
    vector<int> visited(amount_v);
    for (int i = 0; i < amount_e; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        if (start != end) {
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
    }

    int amount_cc = 0;

    for (int i = 0; i < amount_v; ++i) {
        if (!visited[i]) {
            ++amount_cc;
            dfs(i, visited, graph, amount_cc);
        }
    }

    cout << amount_cc << endl;

    vector<vector<int>> ans(amount_cc);
    for (int i = 0; i < amount_v; ++i) {
        ans[visited[i] - 1].push_back(i);
    }

    for (const auto &cur_comp: ans) {
        cout << cur_comp.size() << endl;
        for (const auto &v: cur_comp) {
            cout << v + 1 << ' ';
        }
        cout << endl;
    }
}


