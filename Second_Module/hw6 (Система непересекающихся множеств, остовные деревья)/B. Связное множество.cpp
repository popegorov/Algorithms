#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9;

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
    double weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int Pow(int x) {
    return x * x;
}

struct Graph {
    Graph(int amount_v) : coordinates(amount_v) {}

    double MeasureDist(int v, int to) {
        return sqrt(Pow(coordinates[v].first - coordinates[to].first) + Pow(coordinates[v].second - coordinates[to].second));
    }

    void AddEdge (int v, int x, int y) {
        coordinates[v] = {x, y};
        for (int i = 0; i < v; ++i) {
            auto distance = MeasureDist(i, v);
            edges.push_back({i, v, distance});
        }
    };

    double Kruskal(int m) {
        DSU dsu(coordinates.size());

        for (int i = 0; i < m; ++i) {
            int start, end;
            cin >> start >> end;
            --start;
            --end;
            dsu.Merge(start, end);
        }

        sort(edges.begin(), edges.end());
        double res = 0;

        for (const auto& [start, end, weight] : edges) {
            if (!dsu.AreConnected(start, end)) {
                dsu.Merge(start, end);
                res += weight;
            }
        }

        return res;
    }


    vector<Edge> edges;
    vector<pair<int, int>> coordinates;

};

int main() {
    int n;
    cin >> n;

    Graph g(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g.AddEdge(i, x, y);
    }

    int m;
    cin >> m;
    cout << setprecision(7) << g.Kruskal(m);

}
