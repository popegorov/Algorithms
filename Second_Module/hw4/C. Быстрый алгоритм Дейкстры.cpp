#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    Graph(int n) : graph(n), dist(n, -1) {}


    void AddEdge(int i, int j, int edge_w) {
        if (graph[i][j]) {
            graph[i][j] = min(edge_w, graph[i][j]);
            graph[j][i] = min(edge_w, graph[j][i]);
        } else if (i != j) {
            graph[i][j] = edge_w;
            graph[j][i] = edge_w;
        }
    }

    long long dijkstra(int start, int finish) {
        set<pair<int, int>> q;
        dist[start] = 0;
        q.insert({dist[start], start});

        while (!q.empty()) {
            auto [dist_v, cur_v] = *q.begin();
            q.erase(q.begin());

            for (const auto &[to, weight]: graph[cur_v]) {
                if (dist[to] > dist[cur_v] + weight || dist[to] == -1) {
                    q.erase({dist[to], to});
                    dist[to] = dist[cur_v] + weight;
                    q.insert({dist[to], to});
                }
            }
        }

        return dist[finish];
    }

    vector<unordered_map<int, int>> graph;
    vector<long long> dist;
    vector<int> from;
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int start, end, edge_w;
        cin >> start >> end >> edge_w;
        --start;
        --end;
        g.AddEdge(start, end, edge_w);
    }

    int start, end;
    cin >> start >> end;
    --start;
    --end;

    auto dist = g.dijkstra(start, end);

    if (start == end) {
        cout << 0;
    } else {
        cout << dist;
    }
}
