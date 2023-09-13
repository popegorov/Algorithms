#include <iostream>
#include <vector>

using namespace std;

int max_depth = 0;
int max_v = 0;

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph, int& square) {
    visited[v] = 1;
    ++square;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph, square);
        }
    }
}

vector<int> VectorOfNeighbours(vector<vector<bool>>& labyrinth, size_t i, size_t j) {
    vector<int> neighbours;
    for (auto delta_i : {-1, 1}) {
        auto new_i = i + delta_i;
        if (new_i < labyrinth.size() && labyrinth[new_i][j]) {
            neighbours.push_back(new_i * labyrinth.size() + j);
        }
    }

    for (auto delta_j : {-1, 1}) {
        auto new_j = j + delta_j;
        if (new_j < labyrinth.size() && labyrinth[i][new_j]) {
            neighbours.push_back(i * labyrinth.size() + new_j);
        }
    }

    return neighbours;
}

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> labyrinth(n, vector<bool>(n));
    vector<vector<int>> graph(n*n);
    vector<int> visited(n*n);

    for (size_t i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (size_t j = 0; j < n; ++j) {
            labyrinth[i][j] = (row[j] != '*');
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            graph[i * n + j] = VectorOfNeighbours(labyrinth, i, j);
        }
    }

    int start_i, start_j;
    cin >> start_i >> start_j;
    --start_i;
    --start_j;

    int square = 0;
    dfs(start_i * n + start_j, visited, graph, square);

    cout << square;
}


