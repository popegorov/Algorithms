#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

int Sq(int x) {
    return x * x;
}

class Graph {
public:
    Graph(int amount_v) : visited_(amount_v), graph_(amount_v), new_graph_(amount_v) {}

    void AddEdge(int start, int end) {
        if (start != end) {
            graph_[start].push_back(end);
            graph_[end].push_back(start);
            new_graph_[start].insert(end);
            new_graph_[end].insert(start);
        }
    }

    void dfs1(int v, vector<int>& top_sort) {
        visited_[v] = 1;
        for (const auto& neighbour: graph_[v]) {
            if (!visited_[neighbour]) {
                new_graph_[v].erase(neighbour);
                dfs1(neighbour, top_sort);
            }
        }
        top_sort.push_back(v);
    }

    void dfs2(int v, int comp) {
        visited_[v] = comp;
        for (const auto& neighbour : new_graph_[v]) {
            if (!visited_[neighbour]) {
                dfs2(neighbour, comp);
            }
        }
    }


    vector<int> GetVisited() const {
        return visited_;
    }

    vector<int>& SetVisited() {
        return visited_;
    }

private:
    vector<vector<int>> graph_;
    vector<unordered_set<int>> new_graph_;
    vector<int> visited_;
};

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;

    unordered_set<int> kr_edges;
    map<pair<int, int>, int> edges;
    Graph g(amount_v);
    for (size_t i = 0; i < amount_e; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        int min_ = min(start, end);
        int max_ = max(start, end);
        if (edges[{min_, max_}]) {
            kr_edges.insert(edges[{min_, max_}]);
        } else {
            g.AddEdge(start, end);
            edges[{min_, max_}] = i + 1;
        }
    }

    vector<int> top_sort;
    for (size_t i = 0; i < amount_v; ++i) {
        if (!g.SetVisited()[i]) {
            g.dfs1(i, top_sort);
        }
    }
    reverse(top_sort.begin(), top_sort.end());

    int amount_cc = 0;
    g.SetVisited().assign(amount_v, 0);
    for (auto& cur_v: top_sort) {
        if (!g.SetVisited()[cur_v]) {
            ++amount_cc;
            g.dfs2(cur_v, amount_cc);
        }
    }

    vector<int> bridges;
    for (auto [edge, cnt] : edges) {
        auto start = edge.first;
        auto end = edge.second;
        if (g.SetVisited()[start] != g.SetVisited()[end]) {
            bridges.push_back(cnt);
        }
    }

    sort(bridges.begin(), bridges.end());

    vector<int> new_bridges;
    for (const auto& bridge : bridges) {
        if (!kr_edges.contains(bridge)) {
            new_bridges.push_back(bridge);
        }
    }

    cout << new_bridges.size() << endl;

    for (const auto& bridge : new_bridges) {
        cout << bridge << ' ';
    }
}
