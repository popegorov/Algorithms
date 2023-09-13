#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Graph {
    Graph(int amount_v) : dist(amount_v, INF) {}


    void AddEdge (int start_e, int start_t, int end_e, int end_t) {
        edges.push_back({start_e, start_t, end_e, end_t});
    };

    int ford_bellman(int start, int finish) {
        dist[start] = 0;
        for (int _ = 0; _ < 2 * edges.size(); ++_) {
            bool flag = true;

            for (const auto& [start_e, start_t, end_e, end_t] : edges) {
                if (dist[start_e] != INF && dist[end_e] > end_t && dist[start_e] <= start_t) {
                    dist[end_e] = end_t;
                    flag = false;
                }
            }

            if (flag) {
                return dist[finish];
            }
        }

        return dist[finish];
    }

    vector<array<int, 4>> edges;
    vector<int> dist;
};

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    --a;
    --b;

    Graph g(n);

    for (int i = 0; i < k; ++i) {
        int start_e, start_t, end_e, end_t;
        cin >> start_e >> start_t >> end_e >> end_t;
        --start_e;
        --end_e;
        g.AddEdge(start_e, start_t, end_e, end_t);
    }

    cout << g.ford_bellman(a, b);
}


