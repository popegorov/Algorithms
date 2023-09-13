#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    Graph(int n) : graph(n), dist(n, -1), from(n , -1) {}


    void AddEdge(int i, int j, int edge_w) {
        if (graph[i][j]) {
            graph[i][j] = min(edge_w, graph[i][j]);
            graph[j][i] = min(edge_w, graph[j][i]);
        } else if (i != j) {
            graph[i][j] = edge_w;
            graph[j][i] = edge_w;
        }
    }

    void dijkstra(int start) {
        set<pair<int, int>> q;
        dist[start] = 0;
        q.insert({dist[start], start});

        while (!q.empty()) {
            auto [dist_v, cur_v] = *q.begin();
            q.erase(q.begin());

            for (const auto &[to, weight]: graph[cur_v]) {
                if (dist[to] > dist[cur_v] + weight || dist[to] == -1) {
                    q.erase({dist[to], to});
                    dist[to] = dist[cur_v] + weight;
                    from[to] = cur_v;
                    q.insert({dist[to], to});
                }
            }
        }
    }

    vector<unordered_map<int, int>> graph;
    vector<long long> dist;
    vector<int> from;
};

struct City {
    int index;
    long long time;

    bool operator<(const City& other) const {
        return time < other.time;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);

    int capital;
    cin >> capital;
    --capital;

    vector<int> cities;
    for (int i = 0; i < k; ++i) {
        int city;
        cin >> city;
        --city;
        cities.push_back(city);
    }

    for (int i = 0; i < m; ++i) {
        int start, end, edge_w;
        cin >> start >> end >> edge_w;
        --start;
        --end;
        g.AddEdge(start, end, edge_w);
    }

    g.dijkstra(capital);

    vector<City> sorted_cities;
    for (const auto& cur_city : cities) {
        sorted_cities.push_back({cur_city, g.dist[cur_city]});
    }
    sort(sorted_cities.begin(), sorted_cities.end());

    for(const auto& [index, time] : sorted_cities) {
        cout << index + 1 << ' ' << time << endl;
    }
}
