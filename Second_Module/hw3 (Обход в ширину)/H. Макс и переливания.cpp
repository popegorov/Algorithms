#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int a, int b, int c, int v) : a(a), b(b), c(c), v(v),  dist(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, -1))) {}

    void CheckSituation(int new_a, int new_b, int new_c, int cur_a, int cur_b, int cur_c, queue<int>& q) {
        if (dist[new_a][new_b][new_c] == -1) {
            dist[new_a][new_b][new_c] = dist[cur_a][cur_b][cur_c] + 1;
            q.push(new_a);
            q.push(new_b);
            q.push(new_c);
            if (new_a == v || new_b == v || new_c == v) {
                cout << dist[new_a][new_b][new_c];
                exit(0);
            }
        }
    }

    void bfs() {
        queue<int> q;
        q.push(0);
        q.push(0);
        q.push(0);
        dist[0][0][0] = 0;

        while (!q.empty()) {
            auto cur_a = q.front();
            q.pop();
            auto cur_b = q.front();
            q.pop();
            auto cur_c = q.front();
            q.pop();

            CheckSituation(0, cur_b, cur_c, cur_a, cur_b, cur_c, q);
            CheckSituation(cur_a, 0, cur_c, cur_a, cur_b, cur_c, q);
            CheckSituation(cur_a, cur_b, 0, cur_a, cur_b, cur_c, q);
            CheckSituation(a, cur_b, cur_c, cur_a, cur_b, cur_c, q);
            CheckSituation(cur_a, b, cur_c, cur_a, cur_b, cur_c, q);
            CheckSituation(cur_a, cur_b, c, cur_a, cur_b, cur_c, q);

            int amount_l = min(cur_a, b - cur_b);
            CheckSituation(cur_a - amount_l, cur_b + amount_l, cur_c, cur_a, cur_b, cur_c, q);
            amount_l = min(cur_b, a - cur_a);
            CheckSituation(cur_a + amount_l, cur_b - amount_l, cur_c, cur_a, cur_b, cur_c, q);

            amount_l = min(cur_c, b - cur_b);
            CheckSituation(cur_a, cur_b + amount_l, cur_c - amount_l, cur_a, cur_b, cur_c, q);
            amount_l = min(cur_b, c - cur_c);
            CheckSituation(cur_a, cur_b - amount_l, cur_c + amount_l, cur_a, cur_b, cur_c, q);

            amount_l = min(cur_a, c - cur_c);
            CheckSituation(cur_a - amount_l, cur_b, cur_c + amount_l, cur_a, cur_b, cur_c, q);
            amount_l = min(cur_c, a - cur_a);
            CheckSituation(cur_a + amount_l, cur_b, cur_c - amount_l, cur_a, cur_b, cur_c, q);
        }

        cout << -1;
    }

    int a, b, c, v;
    vector<vector<vector<int>>> dist;
};

int main() {
    int a, b, c, v;
    cin >> a >> b >> c >> v;
    Graph g(a, b, c, v);

    g.bfs();
}


