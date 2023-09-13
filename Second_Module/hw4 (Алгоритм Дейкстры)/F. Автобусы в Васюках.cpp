#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Bus {
    int to;
    int start;
    int end;
};

class Graph {
public:
    Graph(int n) : graph(n), times(n, -1), from(n , -1) {}


    void AddEdge(int i, int j, int time_s, int time_e) {
        graph[i].push_back({j, time_s, time_e});
    }

    void dijkstra(int start) {
        set<pair<int, int>> q;
        times[start] = 0;
        q.insert({times[start], start});

        while (!q.empty()) {
            auto [time_v, cur_v] = *q.begin();
            q.erase(q.begin());

            for (const auto &[to, begin, end]: graph[cur_v]) {
                if ((times[to] > end || times[to] == -1) && time_v <= begin) {
                    q.erase({times[to], to});
                    times[to] = end;
                    q.insert({times[to], to});
                }
            }
        }
    }

    vector<vector<Bus>> graph;
    vector<long long> times;
    vector<int> from;
};

int main() {
    int n;
    cin >> n;
    Graph g(n);

    int d, v;
    cin >> d >> v;
    --d;
    --v;

    int r;
    cin >> r;

    for (int i = 0; i < r; ++i) {
        int start_e, start_t, end_e, end_t;
        cin >> start_e >> start_t >> end_e >> end_t;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e, start_t, end_t);
    }

    g.dijkstra(d);

    cout << g.times[v];
}


