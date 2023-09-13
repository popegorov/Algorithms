#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    Graph(int n) : graph(n), dist(n, -1), from(n, -1) {}


    void AddEdge(int i, int j, int edge_w) {
        if (edge_w != -1) {
            graph[i].push_back({j, edge_w});
        }
    }

    int dijkstra(int start, int finish) {
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
                    from[to] = cur_v;
                    q.insert({dist[to], to});
                }
            }
        }

        return dist[finish];
    }

    vector<vector<pair<int, int>>> graph;
    vector<int> dist;
    vector<int> from;
};

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    --s;
    --f;
    Graph g(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int edge_w;
            cin >> edge_w;
            g.AddEdge(i, j, edge_w);
        }
    }

    g.dijkstra(s, f);

    if (s == f) {
        cout << s + 1;
    } else if (g.from[f] == -1) {
        cout << -1;
    } else {
        vector<int> res = {f};
        for (int cur_v = g.from[f]; cur_v != -1; cur_v = g.from[cur_v]) {
            res.push_back(cur_v);
        }
        reverse(res.begin(), res.end());
        for (const auto &cur_v: res) {
            cout << cur_v + 1 << ' ';
        }
    }
}
