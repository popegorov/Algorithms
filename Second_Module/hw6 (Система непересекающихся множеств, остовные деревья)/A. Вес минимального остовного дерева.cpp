#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9;

//struct MyHash {
//    size_t operator()(const pair<int, int>& a) const {
//        auto h1 = hash<int>{}(a.first);
//        auto h2 = hash<int>{}(a.second);
//        return h1 ^ (h2<<1);
//    }
//};

struct Edge {
    int end;
    int weight;
};

struct Graph {
    Graph(int amount_v) : dist(amount_v, INF), visited(amount_v), graph(amount_v) {}


    void AddEdge (int start_e, int end_e, int weight) {
        graph[start_e].push_back({end_e, weight});
        graph[end_e].push_back({start_e, weight});
    };

    int Prim() {
        int res = 0;
        set<pair<int, int>> unvisited;
        dist[0] = 0;
        unvisited.insert({dist[0], 0});

        while (!unvisited.empty()) {
            int cur_v = unvisited.begin()->second;
            unvisited.erase(unvisited.begin());
            visited[cur_v] = true;
            res += dist[cur_v];

            for (const auto& [to, weight] : graph[cur_v]) {
                if (!visited[to] && dist[to] > weight) {
                    unvisited.erase({dist[to], to});
                    dist[to] = weight;
                    unvisited.insert({dist[to], to});
                }
            }
        }

        return res;
    }

    vector<vector<Edge>> graph;
    vector<int> dist;
    vector<bool> visited;

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

    cout << g.Prim();
}


