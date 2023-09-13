#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int n, int m) : metro_lines(m), dist(n, -1) {}

    void AddStation(int m_l, int cur_st) {
        metro_lines[m_l].insert(cur_st);
    }

    int bfs(int start, int end) {
        queue<int> q;

        for (const auto& metro_line : metro_lines) {
            if (metro_line.contains(start)) {
                for (const auto& station : metro_line) {
                    q.push(station);
                    dist[station] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto cur_st = q.front();
            q.pop();
            for (const auto& metro_line : metro_lines) {
                if (metro_line.contains(cur_st)) {
                    for (const auto& station : metro_line) {
                        if (dist[station] == -1) {
                            q.push(station);
                            dist[station] = dist[cur_st] + 1;
                            if (station == end) {
                                return dist[end];
                            }
                        }
                    }
                }
            }
        }
        return dist[end];
    }

    vector<unordered_set<int>> metro_lines;
    vector<int> dist;
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n, m);
    for (int m_l = 0; m_l < m; ++m_l) {
        int p;
        cin >> p;
        for (int j = 0; j < p; ++j) {
            int cur_st;
            cin >> cur_st;
            --cur_st;
            g.AddStation(m_l, cur_st);
        }
    }

    int start, end;
    cin >> start >> end;
    --start;
    --end;
    cout << g.bfs(start, end);
}


