#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int amount_v) : n(amount_v), dist(amount_v, vector<vector<int>>(amount_v, vector<int>(amount_v, -1))), graph(amount_v, vector<vector<bool>>(amount_v, vector<bool>(amount_v))) {}

    void FillCell(size_t x, size_t y, size_t z, char isEdge) {

        graph[z][y][x] = isEdge != '#';
        if (isEdge == 'S') {
            start = z * n * n + y * n + x;
        }
    }

    int bfs() {
        vector<int> shift_x = {-1, 1, 0, 0, 0, 0};
        vector<int> shift_y = {0, 0, -1, 1, 0, 0};
        vector<int> shift_z = {0, 0, 0, 0, -1, 1};

        queue<size_t> q;
        q.push(start);
        dist[start / (n * n)][start % (n * n) / n][start % n] = 0;

        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            auto cur_z = v / (n * n);
            auto cur_y = v % (n * n) / n;
            auto cur_x = v % n;
            for (int i = 0; i < shift_x.size(); ++i) {
                size_t to_x = cur_x + shift_x[i];
                size_t to_y = cur_y + shift_y[i];
                size_t to_z = cur_z + shift_z[i];
                if (to_z < n && to_y < n && to_x < n && graph[to_z][to_y][to_x] && dist[to_z][to_y][to_x] == -1) {
                    q.push(to_z * n * n + to_y * n + to_x);
                    dist[to_z][to_y][to_x] = dist[cur_z][cur_y][cur_x] + 1;
                    if (!to_z) {
                        return dist[to_z][to_y][to_x];
                    }
                }
            }
        }
    }

    int n;
    size_t start;
    vector<vector<vector<bool>>> graph;
    vector<vector<vector<int>>> dist;
};

int main() {
    int amount_v;
    cin >> amount_v;
    Graph g(amount_v);

    for (int z = 0; z < amount_v; ++z) {
        for (int y = 0; y < amount_v; ++y) {
            for (int x = 0; x < amount_v; ++x) {
                char isStone;
                cin >> isStone;
                g.FillCell(x, y, z, isStone);
            }
        }
    }

    cout << g.bfs();
}


