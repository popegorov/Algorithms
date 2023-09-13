#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    Graph(int n) : graph(n), result(n, vector<double>(n)), size(n) {}

    void AddEdge(int i, int j, double weight) {
        graph[i].push_back({j, 1 - weight / 100});
        graph[j].push_back({i, 1 - weight / 100});
        result[i][j] = 1 - weight / 100;
        result[j][i] = 1 - weight / 100;
    }

    double floyd(int start, int finish) {
        for (int i = 0; i < size; ++i) {
            result[i][i] = 0;
        }

        for (int via = 0; via < size; ++via) {
            for (int from = 0; from < size; ++from) {
                for (int to = 0; to < size; ++to) {
                    if (result[from][to] < result[from][via] * result[via][to]) {
                        result[from][to] = result[from][via] * result[via][to];
                    }
                }
            }
        }

        return 1 - result[start][finish];
    }

    int size;
    vector<vector<pair<int, int>>> graph;
    vector<vector<double>> result;
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);

    int start, end;
    cin >> start >> end;
    --start;
    --end;

    for (int i = 0; i < m; ++i) {
        int start_e, end_e, weight;
        cin >> start_e >> end_e >> weight;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e, weight);
    }

    cout << g.floyd(start, end);
}


