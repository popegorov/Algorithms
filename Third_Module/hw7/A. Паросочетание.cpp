#include <iostream>
#include <vector>

using namespace std;

struct BipartiteGraph {
    BipartiteGraph(int n, int m) : left_half(n), left_size(n), right_size(m) {}

    void AddEdge(int left_node, int right_node) {
        left_half[left_node].push_back(right_node);
    };

    bool dfs(int now, vector<bool>& visited, vector<int>& pair_from_left) {
        visited[now] = true;

        for (const auto& right_node : left_half[now]) {
            auto cur = pair_from_left[right_node];
            if (cur == -1 || !visited[cur] && dfs(cur, visited, pair_from_left)) {
                pair_from_left[right_node] = now;
                return true;
            }
        }

        return false;
    }

    void Kuhn() {
        vector<int> pair_from_left(right_size, -1);

        for (int left_node = 0; left_node < left_size; ++left_node) {
            vector<bool> visited(left_size);
            dfs(left_node, visited, pair_from_left);
        }

        int matching_size = 0;
        for (const auto& has_left : pair_from_left) {
            if (has_left != -1) {
                ++matching_size;
            }
        }

        cout << matching_size << endl;
        for (int right_node = 0; right_node < right_size; ++right_node) {
            if (pair_from_left[right_node] != -1) {
                cout <<pair_from_left[right_node] + 1 << ' ' << right_node + 1 << endl;
            }
        }
    }

    int left_size, right_size;
    vector<vector<int>> left_half;
};

int main() {
    int n, m;
    cin >> n >> m;

    BipartiteGraph g(n, m);
    for (int left_node = 0; left_node < n; ++left_node) {
        int right_node;
        cin >> right_node;

        while (right_node) {
            --right_node;
            g.AddEdge(left_node, right_node);
            cin >> right_node;
        }
    }

    g.Kuhn();
}


