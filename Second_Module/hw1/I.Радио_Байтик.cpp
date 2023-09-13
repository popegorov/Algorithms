#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int Sq(int x) {
    return x * x;
}

class Graph {
public:
    Graph(int amount_v) : visited_(amount_v), graph_(amount_v) {}

    Graph(vector<pair<int, int>>& vv, double r) : visited_(vv.size()), graph_(vv.size()){
        for (size_t i = 0; i < vv.size(); ++i) {
            for (size_t j = i + 1; j < vv.size(); ++j) {
                auto x_1 = vv[i].first;
                auto y_1 = vv[i].second;
                auto x_2 = vv[j].first;
                auto y_2 = vv[j].second;
                auto dist = sqrt(Sq(x_1 - x_2) + Sq(y_1 - y_2));

                if (dist / 2 < r) {
                    graph_[i].push_back(j);
                    graph_[j].push_back(i);
                }
            }
        }
    }

    void dfs(int v, int color, bool& two_colors) {
        visited_[v] = color;
        for (auto &neighbour: graph_[v]) {
            if (!visited_[neighbour]) {
                dfs(neighbour, 3 - color, two_colors);
            } else if (visited_[neighbour] == visited_[v]) {
                two_colors =  false;
            }
        }
    }

    vector<int> GetVisited() const {
        return visited_;
    }

private:
    vector<vector<int>> graph_;
    vector<int> visited_;
};

bool good(vector<pair<int, int>>& vv, double r) {
    Graph g(vv, r);
    bool ans = true;
    for (size_t i = 0; i < vv.size(); ++i) {
        if (!g.GetVisited()[i]) {
            g.dfs(i, 1, ans);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vv;
    for (size_t i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        vv.push_back({x, y});
    }

    double left = 0;
    double right = 1e5;
    while (left + 1e-9 < right) {
        double middle = (left + right) / 2;
        if (good(vv, middle)) {
            left = middle;
        } else {
            right = middle;
        }
    }
    cout << left << endl;

    Graph g(vv, left);
    for (int i = 0; i < n; ++i) {
        if (!g.GetVisited()[i]) {
            bool ans = true;
            g.dfs(i, 1, ans);
        }
    }

    for (const auto& color : g.GetVisited()) {
        cout << color << ' ';
    }
}


