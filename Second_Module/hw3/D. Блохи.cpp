#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int n, int m) : dist(n, vector<int>(m, -1)), height(n), width(m) {}

    void bfs(size_t s, size_t t) {
        static vector<int> shift_x = {-1, 1, -1, 1, -2, -2, 2, 2};
        static vector<int> shift_y = {2, 2, -2, -2, -1, 1, -1, 1};

        queue<size_t> q;
        q.push(s);
        q.push(t);
        dist[s][t] = 0;

        while (!q.empty()) {
            auto cur_y = q.front();
            q.pop();
            auto cur_x = q.front();
            q.pop();
            for (int i = 0; i < shift_x.size(); ++i) {
                size_t to_x = cur_x + shift_x[i];
                size_t to_y = cur_y + shift_y[i];
                if (to_y < height && to_x < width && dist[to_y][to_x] == -1) {
                    q.push(to_y);
                    q.push(to_x);
                    dist[to_y][to_x] = dist[cur_y][cur_x] + 1;
                }
            }
        }
    }

    int height;
    int width;
    vector<vector<int>> dist;
};

int main() {
    int n, m, s, t, q;
    cin >> n >> m >> s >> t >> q;
    --s;
    --t;
    Graph g(n, m);

    g.bfs(s, t);
    size_t sum = 0;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> y >> x;
        --y;
        --x;
        if (g.dist[y][x] == -1) {
            cout << -1;
            exit(0);
        }
        sum += g.dist[y][x];
    }
    cout << sum;
}
