#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    Graph(int n) : graph(n), visited(n) {}

    void AddEdge(int i, int j) {
        graph[i].push_back(j);
    }

    void dfs(int v) {
        visited[v] = 1;
        for (const auto& to : graph[v]) {
            if (!visited[to]) {
                dfs(to);
            } else if (visited[to] == 1) {
                cout << 1;
                exit(0);
            }
        }
        visited[v] = 2;
    }

    vector<vector<int>> graph;
    vector<int> visited;
};

int main() {
    int n;
    cin >> n;
    Graph g(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int isEdge;
            cin >> isEdge;
            if (isEdge) {
                g.AddEdge(i, j);
            }
        }
    }

    vector<vector<int>> ans(n , vector<int>(n));
    for (int i = 0; i < n; ++i) {
        if (!g.visited[i]) {
            g.dfs(i);
        }
    }

    cout << 0;
}


