#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    size_t row;
    size_t col;
    size_t height;
};

bool Less(const Point& a, const Point& b) {
    return (a.height < b.height);
}

void dfs(int v, vector<int> &visited, vector<vector<int>> &graph) {
    visited[v] = 1;
    for (auto &neighbour: graph[v]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, graph);
        }
    }
}

vector<int> VectorOfNeighbours(vector<vector<size_t>>& field, size_t i, size_t j) {
    vector<int> neighbours;
    for (auto delta_i : {-1, 1}) {
        auto new_i = i + delta_i;
        if (new_i < field.size() && field[new_i][j] >= field[i][j]) {
            neighbours.push_back(new_i * field[0].size() + j);
        }
    }

    for (auto delta_j : {-1, 1}) {
        auto new_j = j + delta_j;
        if (new_j < field[0].size() && field[i][new_j] >= field[i][j]) {
            neighbours.push_back(i * field[0].size() + new_j);
        }
    }

    return neighbours;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<size_t>> field(n, vector<size_t>(m));
    vector<Point> sorted_field;
    vector<vector<int>> graph(n*m);
    vector<int> visited(n*m);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            size_t val;
            cin >> val;
            field[i][j] = val;
            sorted_field.push_back({i, j, val});
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            graph[i * m + j] = VectorOfNeighbours(field, i, j);
        }
    }

    sort(sorted_field.begin(), sorted_field.end(), Less);

    int cur_i = 0;
    int cnt = 0;
    while(any_of(visited.begin(), visited.end(), [](int i){return !i;})) {
        auto cur_v = sorted_field[cur_i].row * m + sorted_field[cur_i].col;
        if (!visited[cur_v]) {
            dfs(cur_v, visited, graph);
            ++cnt;
        }
        ++cur_i;
    }

    cout << cnt;
}


