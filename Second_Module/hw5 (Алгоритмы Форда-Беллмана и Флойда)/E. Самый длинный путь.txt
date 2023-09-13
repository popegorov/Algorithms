#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

const long long INF = 1e12;

class Graph {
public:
    Graph(int n) : graph(n), result(n, vector<long long>(n, INF)), size(n) {}

    void AddEdge(int i, int j, int weight) {
        graph[i].push_back({j, weight});
        result[i][j] = weight;
    }

    void floyd() {
        for (int i = 0; i < size; ++i) {
            result[i][i] = 0;
        }

        for (int via = 0; via < size; ++via) {
            for (int from = 0; from < size; ++from) {
                for (int to = 0; to < size; ++to) {
                    if (result[from][to] > result[from][via] + result[via][to]) {
                        result[from][to] = result[from][via] + result[via][to];
                    }
                }
            }
        }
    }

    int size;
    vector<vector<pair<int, int>>> graph;
    vector<vector<long long>> result;
};

int main() {
    int n;
    cin >> n;
    Graph g(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            cin >> weight;
            g.AddEdge(i, j, weight);
        }
    }

    g.floyd();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = max(g.result[i][j], ans);
        }
    }

    cout << ans;
}


