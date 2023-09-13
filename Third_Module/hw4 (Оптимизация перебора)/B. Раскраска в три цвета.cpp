#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<char> color_collection = {'R', 'G', 'B'};
vector<bool> original_visited;

struct Graph {
    Graph (int n, const string& colours) : graph(n), visited(n), recolored(n, 'a') {
        for (const auto& color : colours) {
            colors.push_back(color);
        }
    }

    void AddEdge(int start_e, int end_e) {
        graph[start_e].insert(end_e);
        graph[end_e].insert(start_e);
    }

    bool Recursive (int now, char cur_color) {
        visited[now] = true;

        if (cur_color == colors[now]) {
            return false;
        }
        auto first_color = recolored[now];
        recolored[now] = cur_color;

        for (const auto& neighbour : graph[now]) {
            if (visited[neighbour] && recolored[neighbour] == recolored[now]) {
                recolored[now] = first_color;
                return false;
            } else if (!visited[neighbour] && cur_color != colors[neighbour]) {
                auto potential_colors = color_collection;
                potential_colors.erase(cur_color);
                potential_colors.erase(colors[neighbour]);
                if (!Recursive(neighbour, *potential_colors.begin())) {
                    recolored[now] = first_color;
                    return false;
                }
            }
        }
        return true;

    }


    vector<unordered_set<int>> graph;
    vector<char> colors;
    vector<char> recolored;
    vector<bool> visited;
};

int main() {
    int n, m;
    cin >> n >> m;
    string colors;
    cin >> colors;
    original_visited.resize(n);

    Graph g(n, colors);
    for (int i = 0; i < m; ++i) {
        int start_e, end_e;
        cin >> start_e >> end_e;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e);
    }

    for (int i = 0; i < n; ++i) {
        if (g.recolored[i] == 'a') {
            for (const auto& color: color_collection) {
                g.visited = original_visited;
                if (g.Recursive(i, color)) {
                    break;
                }
            }
        }
    }

    if (all_of(g.recolored.begin(), g.recolored.end(), [](char i){return i != 'a';})) {
        for (const auto& color : g.recolored) {
            cout << color;
        }
    } else {
        cout << "Impossible";
    }
}


