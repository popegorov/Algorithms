#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int amount_v) : visited_(amount_v), graph_(amount_v) {}

    void AddEdge(int start, int end) {
        if (!graph_[start].contains(end) && start != end) {
            graph_[start].insert(end);
            graph_[end].insert(start);
        }
    }

    void dfs(int v) {
        visited_[v] = true;
        for (auto &neighbour: graph_[v]) {
            if (!visited_[neighbour]) {
                visited_[neighbour] = true;
                dfs(neighbour);
            }
        }
    }

    vector<bool> GetVisited() const {
        return visited_;
    }

private:
    vector<set<int>> graph_;
    vector<bool> visited_;
};

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;

    Graph g(amount_v);
    for (int i = 0; i < amount_e; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        g.AddEdge(start, end);
    }

    g.dfs(0);

    vector<int> ans;

    for (int i = 0; i < amount_v; ++i) {
        if (g.GetVisited()[i]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (const auto &v: ans) {
        cout << v << ' ';
    }
}


