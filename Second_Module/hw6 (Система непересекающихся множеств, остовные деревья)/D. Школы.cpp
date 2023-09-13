#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    DSU(int amount_v) {
        for (int i = 0; i < amount_v; ++i) {
            parent.push_back(i);
        }
    }

    int Find(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = Find(parent[v]);
    }

    void Merge(int a, int b) {
        int ra = Find(a), rb = Find(b);
        if (ra == rb) {
            return;
        } else if (rand() % 2 == 1) {
            parent[ra] = rb;
        } else {
            parent[rb] = ra;
        }
    }

    bool AreConnected(int a, int b) {
        return Find(a) == Find(b);
    }

    vector<int> parent;
};

struct Edge {
    int start;
    int end;
    int weight;

    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }

    bool operator!=(const Edge& other) const {
        return start != other.start || end != other.end || weight != other.weight;
    }
};

struct Graph {
    Graph(int n) : dsu(n) {}

    void AddEdge(int start_e, int end_e, int weight) {
        edges.push_back({start_e, end_e, weight});
    }

    int Kruskal() {

        sort(edges.begin(), edges.end());
        int res = 0;

        for (const auto &[start_e, end_e, weight]: edges) {
            if (!dsu.AreConnected(start_e, end_e)) {
                dsu.Merge(start_e, end_e);
                res += weight;
                min_tree.push_back({start_e, end_e, weight});
            }
        }

        return res;
    }

    DSU dsu;
    vector<Edge> edges;
    vector<Edge> min_tree;
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int start_e, end_e, weight;
        cin >> start_e >> end_e >> weight;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e, weight);
    }

    auto res = g.Kruskal();
    auto min_tree = g.min_tree;
    auto edges = g.edges;
    int ans = 1e9;

    for (const auto& cur_edge : g.min_tree) {
        Graph new_g(n);
        for (const auto& [start, end, weight] : edges) {
            Edge edge = {start, end, weight};
            if (edge != cur_edge) {
                new_g.AddEdge(start, end, weight);
            }
        }
        auto cur_ans = new_g.Kruskal();
        bool connected = true;
        for (int i = 1; i < n; ++i) {
            if (!new_g.dsu.AreConnected(0, i)) {
                connected = false;
            }
        }
        if (connected) {
            ans = min(ans, cur_ans);
        }
    }

    cout << res << ' ' << ans;
}


