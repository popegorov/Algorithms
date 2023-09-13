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
    int start_x;
    int start_y;
    int weight;

    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

struct Graph {
    Graph(int n, int m) : height(n), width(m), dsu(n * m) {}

    void AddEdge(int d, int i, int j) {
        edges.push_back({j, i, 2});
        edges.push_back({j, i, 1});
        if (d == 3) {
            dsu.Merge(width * i + j, width * i + j + 1);
            dsu.Merge(width * i + j, width * (i + 1) + j);
        } else if (d == 2) {
            dsu.Merge(width * i + j, width * i + j + 1);
        } else if (d == 1) {
            dsu.Merge(width * i + j, width * (i + 1) + j);
        }

    }

    int Kruskal() {

        sort(edges.begin(), edges.end());
        int res = 0;

        for (const auto &[start_x, start_y, weight]: edges) {
            if (weight == 1 && start_y != height - 1 && !dsu.AreConnected(start_y * width + start_x, (start_y + 1) * width + start_x)) {
                dsu.Merge(start_y * width + start_x, (start_y + 1) * width + start_x);
                res += weight;
                min_tree.push_back({start_x, start_y, weight});
            } else if (weight == 2 && start_x != width - 1 && !dsu.AreConnected(start_y * width + start_x, start_y * width + start_x + 1)) {
                dsu.Merge(start_y * width + start_x, start_y * width + start_x + 1);
                res += weight;
                min_tree.push_back({start_x, start_y, weight});
            }
        }

        return res;
    }

    DSU dsu;
    vector<Edge> edges;
    vector<Edge> min_tree;
    int height;
    int width;
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int d;
            cin >> d;
            g.AddEdge(d, i, j);
        }
    }

    auto res = g.Kruskal();
    cout << g.min_tree.size() << ' ' << res << endl;

    for (const auto& [start_x, start_y, weight] : g.min_tree) {
        cout << start_y + 1 << ' ' << start_x + 1 << ' ' << weight << endl;
    }
}
