#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int amount_v) : graph(amount_v), dist(amount_v, -1) {}

    void AddEdge(int start_v, int end_v) {
        if (start_v != end_v) {
            graph[start_v].insert(end_v);
            graph[end_v].insert(start_v);
        }
    }

    vector<int>& bfs(int v) {
        queue<int> q;

        q.push(v);
        dist[v] = 0;

        while (!q.empty()) {
            auto cur_v = q.front();
            q.pop();
            for (const auto& to : graph[cur_v]) {
                if (dist[to] == -1) {
                    q.push(to);
                    dist[to] = dist[cur_v] + 1;
                }
            }
        }

        return dist;
    }

    vector<unordered_set<int>> graph;
    vector<int> dist;
};

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;
    Graph g(amount_v);
    vector<pair<int, int>> edges;

    for (int i = 0; i < amount_e; ++i) {
        int start_v, end_v;
        cin >> start_v >> end_v;
        --start_v;
        --end_v;
        g.AddEdge(start_v, end_v);
        edges.push_back({start_v, end_v});
    }

    int s, t;
    cin >> s >> t;
    --s;
    --t;
    auto dist_s = g.bfs(s);
    auto min_dist = dist_s[t];

    g.dist.assign(amount_v, -1);

    auto dist_t = g.bfs(t);

    int cnt = 0;
    for (const auto& [start_e, end_e] : edges) {
        if ((dist_s[start_e] + dist_t[end_e]) != min_dist - 1 && (dist_s[end_e] + dist_t[start_e]) != min_dist - 1) {
            ++cnt;
        }
    }

    cout << cnt;
}


