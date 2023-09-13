#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int Sq(int x) {
    return x * x;
}

struct Apple {
    int x;
    int y;
    int z;
    int r;

    double Dist(const Apple& other) {
        return sqrt(Sq(x - other.x) + Sq(y - other.y));
    }
};

class Graph {
public:
    Graph(int amount_v, vector<Apple>& apples) : visited_(amount_v), graph_(amount_v), apples(apples) {}

    void AddEdge(int i, int j) {
        auto dist = apples[i].Dist(apples[j]);
        if (dist <= apples[i].r + apples[j].r && apples[i].z > apples[j].z) {
            graph_[i].push_back(j);
        } else if (dist <= apples[i].r + apples[j].r) {
            graph_[j].push_back(i);
        }
    }

    void dfs(int v) {
        visited_[v] = 1;
        for (const auto& to : graph_[v]) {
            if (!visited_[to]) {
                dfs(to);
            }
        }
        top_sort.push_back(v);
    }

    vector<int>& GetVisited() {
        return visited_;
    }

    vector<int> top_sort;
    vector<Apple> apples;
    vector<vector<int>> graph_;
    vector<int> visited_;
};

int main() {
    int amount_v;
    cin >> amount_v;

    vector<Apple> apples;
    for (int i = 0; i < amount_v; ++i) {
        int x, y, z, r;
        cin >> x >> y >> z >> r;
        apples.push_back({x, y, z, r});
    }

    Graph g(amount_v, apples);
    for (int i = 0; i < amount_v; ++i) {
        for (int j = i + 1; j < amount_v; ++j) {
            g.AddEdge(i, j);
        }
    }

    g.dfs(0);
    sort(g.top_sort.begin(), g.top_sort.end());
    cout << g.top_sort.size() << endl;

    for (const auto& cur_v : g.top_sort) {
        cout << cur_v + 1 << ' ';
    }
}


