#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int n, int m) : height(n), width(m), dist(n, vector<int>(m,  -1)), field(n, vector<int>(m)) {}

    void FillCell(size_t x, size_t y, int isEdge) {

        field[y][x] = isEdge;
    }

    int bfs() {
        vector<int> shift_x = {-1, 1, 0, 0};
        vector<int> shift_y = {0, 0, -1, 1};
        queue<int> q;
        q.push(0);
        q.push(0);
        dist[0][0] = 0;

        while (!q.empty()) {
            auto cur_y = q.front();
            q.pop();
            auto cur_x = q.front();
            q.pop();

            for (int i = 0; i < shift_x.size(); ++i) {
                int to_x = cur_x + shift_x[i];
                int to_y = cur_y + shift_y[i];

                while (to_y >= 0 && to_y < height && to_x >= 0 && to_x < width && !field[to_y][to_x]) {
                    to_x += shift_x[i];
                    to_y += shift_y[i];
                }

                if (!(to_y >= 0 && to_y < height && to_x >= 0 && to_x < width) || field[to_y][to_x] == 1) {
                    to_x -= shift_x[i];
                    to_y -= shift_y[i];
                    if (dist[to_y][to_x] == -1) {
                        q.push(to_y);
                        q.push(to_x);
                        dist[to_y][to_x] = dist[cur_y][cur_x] + 1;
                    }
                } else if (field[to_y][to_x] == 2) {
                    return dist[cur_y][cur_x] + 1;
                }
            }
        }
    }

    int height, width;
    vector<pair<int, int>> finish;
    vector<vector<int>> field;
    vector<vector<int>> dist;
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, m);

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            int isWall;
            cin >> isWall;
            g.FillCell(x, y, isWall);
        }
    }

    cout << g.bfs();
}


