#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    Graph(int n) : dist(n, INF) {}

    int fort_bellman() {
        dist[0] = 0;
        for (int _ = 0; _ < dist.size(); ++_) {
            bool flag = true;
            for (int i = 0; i < dist.size(); ++i) {
                for (int j = i + 1; j < dist.size(); ++j) {
                    auto weight = (179 * (i + 1) + 719 * (j + 1)) % 1000 - 500;
                    if (dist[i] != INF && dist[j] > dist[i] + weight) {
                        dist[j] = dist[i] + weight;
                        flag = false;
                    }
                }
            }
            if (flag) {
                return dist[dist.size() - 1];
            }
        }

        return dist[dist.size() - 1];
    }


    vector<int> dist;
    vector<array<int16_t, 3>> edges;
};

int main() {
    int n;
    cin >> n;
    Graph g(n);

    cout << g.fort_bellman();
}


