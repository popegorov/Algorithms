#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int amount_v) : visited_(amount_v), graph_(amount_v) {}

    void AddEdge(int start, int end) {
        if (start != end) {
            graph_[start].push_back(end);
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
private:
    vector<vector<int>> graph_;
    vector<int> visited_;
};

int main() {
    int amount_v;
    cin >> amount_v;

    vector<int> times;
    for (int i = 0; i < amount_v; ++i) {
        int t;
        cin >> t;
        times.push_back(t);
    }

    Graph g(amount_v);
    for (int i = 0; i < amount_v; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int cur_d;
            cin >> cur_d;
            --cur_d;
            g.AddEdge(i, cur_d);
        }
    }

    g.dfs(0);
    long long sum = 0;
    for (const auto& cur_v : g.top_sort) {
        sum += times[cur_v];
    }
    cout << sum << ' ' << g.top_sort.size() << endl;

    for (const auto& cur_v : g.top_sort) {
        cout << cur_v + 1 << ' ';
    }
}
