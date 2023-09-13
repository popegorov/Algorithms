#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    Graph(int n) : graph(n), result(n, vector<int>(n, -INF)), from_(n, vector<int>(n, -1)), size(n) {}

    void AddEdge(int i, int j, int weight) {
        graph[i].push_back({j, weight});
        result[i][j] = weight;
        from_[i][j] = i;
    }

    vector<int> floyd(vector<int>& path) {
        for (int i = 0; i < size; ++i) {
            result[i][i] = 0;
        }

        for (int via = 0; via < size; ++via) {
            for (int from = 0; from < size; ++from) {
                for (int to = 0; to < size; ++to) {
                    if (result[from][to] < result[from][via] + result[via][to]) {
                        result[from][to] = result[from][via] + result[via][to];
                        result[from][to] = result[from][via] + result[via][to];
                        if (via != to) {
                            from_[from][to] = from_[via][to];
                        }
                    }
                }
            }
        }

        vector<int> res;
        int cur_p = path[path.size() - 1];
        for (int i = path.size() - 2; i >= 0; --i) {
            int next_p = path[i];
            for (int v = cur_p; v != next_p; v = from_[next_p][v]) {
                res.push_back(v);
                if (result[v][v] > 0) {
                    cout << "infinitely kind";
                    exit(0);
                }
            }
            cur_p = next_p;
        }
        res.push_back(path[0]);

        reverse(res.begin(), res.end());
        return res;
    }


    int size;
    vector<vector<pair<int, int>>> graph;
    vector<vector<int>> result, from_;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);


    map<pair<int, int>, int> edges;

    for (int i = 0; i < m; ++i) {
        int start_e, end_e, weight;
        cin >> start_e >> end_e >> weight;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e, weight);
        edges[{start_e, end_e}] = i + 1;
    }

    vector<int> path;
    for (int i = 0; i < k; ++i) {
        int cur_p;
        cin >> cur_p;
        --cur_p;
        path.push_back(cur_p);
    }

    auto res = g.floyd(path);
    cout << res.size() - 1 << endl;

    int prev = res[0];
    for (int i = 1; i < res.size(); ++i) {
        cout << edges[{prev, res[i]}] << ' ';
        prev = res[i];
    }
}


