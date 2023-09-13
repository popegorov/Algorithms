#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int amount_v) : visited_(amount_v), graph_(amount_v), depth_(amount_v), up_depth_(amount_v), children_(amount_v) {}

    void AddEdge(int start, int end) {
        if (start != end) {
            graph_[start].insert(end);
            graph_[end].insert(start);
        }
    }

    void dfs(int v, int parent) {
        visited_[v] = 1;
        if (parent != -1) {
            depth_[v] = up_depth_[v] = depth_[parent] + 1;
        } else {
            depth_[v] = up_depth_[v] = 0;
        }

        for (const auto& neighbour: graph_[v]) {
            if (neighbour == parent) {
                continue;
            } else if (!visited_[neighbour]) {
                ++children_[v];
                dfs(neighbour, v);
                up_depth_[v] = min(up_depth_[v], up_depth_[neighbour]);

                if (parent != -1 && up_depth_[neighbour] >= depth_[v]) {
                    cut_points_.push_back(v);
                }
            } else {
                up_depth_[v] = min(up_depth_[v], depth_[neighbour]);
            }
        }
    }

    vector<int>& GetVisited() {
        return visited_;
    }

    vector<int>& GetCutPoints() {
        return cut_points_;
    }

    vector<int>& GetChildren() {
        return children_;
    }

private:
    vector<unordered_set<int>> graph_;
    vector<int> depth_, up_depth_, cut_points_, children_;
    vector<int> visited_;
};

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;
    Graph g(amount_v);

    for (int ind = 0; ind < amount_e; ++ind) {
        int start_v, end_v;
        cin >> start_v >> end_v;

        --start_v;
        --end_v;

        g.AddEdge(start_v, end_v);
    }


    set<int> cut_points;
    for (int v = 0; v < amount_v; ++v) {
        if (!g.GetVisited()[v]) {
            g.dfs(v, -1);
            if (g.GetChildren()[v] > 1) {
                cut_points.insert(v);
            }
        }
    }

    for (const auto& point : g.GetCutPoints()) {
        cut_points.insert(point);
    }

    cout << cut_points.size() << endl;

    for (const auto& v : cut_points) {
        cout << v + 1 << endl;
    }
}


