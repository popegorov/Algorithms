#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

const int INF = 1e9;

struct Bus {
    int to;
    int period;
    int time;
};

class Graph {
public:
    Graph(int n) : graph(n), times(n, -1) {}


    void AddEdge(int i, int j, int period, int time) {
        graph[i].push_back({j, period, time});
    }

    long long dijkstra(int start, int finish, long long now) {
        set<pair<int, int>> q;
        times[start] = now;
        q.insert({times[start], start});

        while (!q.empty()) {
            auto [time_v, cur_v] = *q.begin();
            q.erase(q.begin());

            for (const auto &[to, period, time]: graph[cur_v]) {
                int closest = ceil(static_cast<double>(time_v) / period) * period;
                if (times[to] > closest + time || times[to] == -1) {
                    q.erase({times[to], to});
                    times[to] = closest + time;
                    q.insert({times[to], to});
                }
            }
        }

        return times[finish];
    }

    vector<vector<Bus>> graph;
    vector<long long> times;
};

int main() {
    int n, k;
    cin >> n >> k;
    Graph g(n);

    for (int i = 0; i < k; ++i) {
        int start_e, end_e, period, time;
        cin >> start_e >> end_e >> period >> time;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e, period, time);
    }

    int m, cur_p;
    cin >> m >> cur_p;
    --cur_p;
    long long cur_time = 0;
    for (int i = 0; i < m - 1; ++i) {
        int next_p;
        cin >> next_p;
        --next_p;
        cur_time = g.dijkstra(cur_p, next_p, cur_time);
        if (cur_time == -1) {
            cout << -1;
            exit(0);
        } else {
            g.times.assign(n, -1);
            cur_p = next_p;
        }
    }

    cout << cur_time;

}


