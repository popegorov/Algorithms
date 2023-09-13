#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int amount_v) : visited_(amount_v), graph_(amount_v), reverse_graph_(amount_v){}

    void dfs(int v, vector<int>& top_sort) {
        visited_[v] = 1;
        for (auto &neighbour: graph_[v]) {
            if (!visited_[neighbour]) {
                dfs(neighbour, top_sort);
            }
        }
        top_sort.push_back(v);
    }

    void reverse_dfs(int v, int color) {
        visited_[v] = color;
        for (auto& neighbour : reverse_graph_[v]) {
            if (!visited_[neighbour]) {
                reverse_dfs(neighbour, color);
            }
        }
    }

    void AddEdge(int start, int end) {
        if (start != end) {
            graph_[start].push_back(end);
            reverse_graph_[end].push_back(start);
        }
    }

	vector<int> visited_;
private:
    vector<vector<int>> graph_;
    vector<vector<int>> reverse_graph_;
    
};

int main() {
    int amount_v, amount_e;
    cin >> amount_v >> amount_e;
    Graph g(amount_v);

    for (size_t i = 0; i < amount_e; ++i) {
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        g.AddEdge(start, end);
    }

    vector<int> top_sort;
    for (int i = 0; i < amount_v; ++i) {
        if (!g.visited_[i]) {
            g.dfs(i, top_sort);
        }
    }
    reverse(top_sort.begin(), top_sort.end());

    g.visited_.assign(amount_v, 0);
    int amount_cc = 0;
    for (size_t i = 0; i < amount_v; ++i) {
        if (!g.visited_[top_sort[i]]) {
            ++amount_cc;
            g.reverse_dfs(top_sort[i], amount_cc);
        }
    }

    cout << amount_cc << endl;
    for (const auto& color : g.visited_) {
        cout << color << ' ';
    }
}


