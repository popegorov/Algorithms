#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Graph {
    Graph(int amount_v) : dist(amount_v, INF), size(amount_v), visited(amount_v), from(amount_v), v(-1) {}


    void AddEdge (int start_e, int end_e, int weight) {
        if (weight != 100000) {
            edges.push_back({start_e, end_e, weight});
        }
    };

    void ford_bellman(int start) {
        dist[start] = 0;
        visited[start] = 1;
        for (int _ = 0; _ < size; ++_) {
            bool flag = true;

            for (const auto& [start_e, end_e, weight] : edges) {
                if (dist[start_e] != INF && dist[end_e] > dist[start_e] + weight) {
                    if ( _ == size - 1) {
                        neg_cycle = true;
                        v = end_e;
                        for (int i = 0; i < size; ++i) {
                            v = from[v];
                        }
                        return;
                    } else {
                        dist[end_e] = dist[start_e] + weight;
                        from[end_e] = start_e;
                        flag = false;
                        visited[end_e] = 1;
                    }
                }
            }

            if (flag) {
                return;
            }
        }
    }

    int size, v;
    bool neg_cycle = false;
    vector<array<int, 3>> edges;
    vector<int> dist, visited, from;
};

int main() {
    int n;
    cin >> n;

    Graph g(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            cin >> weight;
            g.AddEdge(i, j, weight);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!g.visited[i]) {
            g.ford_bellman(i);
            if (g.neg_cycle) {
                vector<int> res = {g.v};
                for (int cycle_v = g.from[g.v]; cycle_v != g.v; cycle_v = g.from[cycle_v]) {
                    res.push_back(cycle_v);
                }
                res.push_back(g.v);

                reverse(res.begin(), res.end());

                cout << "YES" << endl << res.size() << endl;
                for (const auto& cur_v : res) {
                    cout << cur_v + 1 << ' ';
                }
                exit(0);
            }
        }
    }

    cout << "NO";
}


