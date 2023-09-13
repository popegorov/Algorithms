#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int amount_v) : dist(amount_v, -1), graph(amount_v) {}

    void AddEdge(int start, int end, bool isEdge) {
        if (start != end && isEdge) {
            graph[start].push_back(end);
        }
    }

    void bfs (int start) {
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (const auto& to : graph[v]) {
                if (dist[to] == -1) {
                    q.push(to);
                    dist[to] = dist[v] + 1;
                }
            }
        }
    }

    vector<vector<int>> graph;
    vector<int> dist;
};

int main() {
    int amount_v;
    cin >> amount_v;
    Graph g(amount_v);

    for (int i = 0; i < amount_v; ++i) {
        for (int j = 0; j < amount_v; ++j) {
            bool isEdge;
            cin >> isEdge;
            g.AddEdge(i, j, isEdge);
        }
    }

    int start, end;
    cin >> start >> end;
    --start;
    --end;

    g.bfs(start);

    cout << g.dist[end];
}
