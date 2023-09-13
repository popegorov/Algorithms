#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

struct BipartiteGraph {
    BipartiteGraph(size_t n, size_t m) : left_half(n), left_size(n), right_size(m) {}

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

        map<int, int> matching;
        for (int i = 0; i < right_size; ++i) {
            if (pair_from_left[i] != -1) {
                matching.insert({pair_from_left[i], i});
            }
        }

        if (matching.size() == left_size) {
            cout << "YES" << endl;
            for (const auto& [letter, cube] : matching) {
                cout << cube + 1 << ' ';
            }
        } else {
            cout << "NO";
        }
    }

    size_t left_size, right_size;
    vector<vector<int>> left_half;
};

int main() {
    int n;
    cin >> n;
    string name;
    cin >> name;

    if (name.size() > n) {
        cout << "NO";
        return 0;
    }

    vector<unordered_set<char>> cubes(n);
    for (int cube_index = 0; cube_index < n; ++cube_index) {
        string cur_cube;
        cin >> cur_cube;

        for(auto sym : cur_cube) {
            cubes[cube_index].insert(sym);
        }
    }
    BipartiteGraph g(name.size(), n);

    for (int letter_index = 0; letter_index < name.size(); ++letter_index) {
        auto cur_letter = name[letter_index];
        for (int cube_index = 0; cube_index < cubes.size(); ++cube_index) {
            if (cubes[cube_index].contains(cur_letter)) {
                g.AddEdge(letter_index, cube_index);
            }
        }
    }

    g.Kuhn();
}


