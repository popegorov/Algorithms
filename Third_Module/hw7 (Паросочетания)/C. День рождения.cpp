#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

struct BipartiteGraph {
    BipartiteGraph(int n, int m) : left_half(n), left_size(n), right_size(m), pair_from_left(m, -1) {
        for (auto& cur_man : left_half) {
            for (int cur_woman = 0; cur_woman < m; ++cur_woman) {
                cur_man.insert(cur_woman);
            }
        }
    }

    void AddEdge(int left_node, int right_node) {
        left_half[left_node].erase(right_node);
    };

    bool dfs(int now, vector<bool>& visited) {
        visited[now] = true;

        for (const auto& right_node : left_half[now]) {
            auto cur = pair_from_left[right_node];
            if (cur == -1 || !visited[cur] && dfs(cur, visited)) {
                pair_from_left[right_node] = now;
                return true;
            }
        }

        return false;
    }

    void new_dfs (int now, vector<unordered_set<int>>& graph, vector<bool>& visited) {
        visited[now] = true;
        for (const auto& neighbor : graph[now]) {
            if (!visited[neighbor]) {
                new_dfs(neighbor, graph, visited);
            }
        }
    }

    void Kuhn() {
        for (int left_node = 0; left_node < left_size; ++left_node) {
            vector<bool> visited(left_size);
            dfs(left_node, visited);
        }
    }

    void MIS() {
        Kuhn();

        vector<unordered_set<int>> directed_graph(left_size + right_size);
        vector<bool> has_incoming_edges(left_size);

        for (int i = 0; i < left_size; ++i) {
            for (auto right_node : left_half[i]) {
                if (pair_from_left[right_node] != i) {
                    directed_graph[i].insert(left_size + right_node);
                } else {
                    directed_graph[left_size + right_node].insert(i);
                    has_incoming_edges[i] = true;
                }
            }
        }

        vector<bool> visited(left_size + right_size);
        for (int i = 0; i < left_size; ++i) {
            if (!has_incoming_edges[i]) {
                new_dfs(i, directed_graph, visited);
            }
        }

        int left_cnt = 0, right_cnt = 0;
        unordered_set<int> man_to_invite, woman_to_invite;
        for (int i = 0; i < left_size; ++i) {
            if (visited[i]) {
                ++left_cnt;
                man_to_invite.insert(i);
            }
        }

        for (int i = left_size; i < left_size + right_size; ++i) {
            if (!visited[i]) {
                ++right_cnt;
                woman_to_invite.insert(i);
            }
        }

        cout << left_cnt + right_cnt << endl;
        cout << left_cnt << ' ' << right_cnt << endl;
        for (const auto& man : man_to_invite) {
            cout << man + 1 << ' ';
        }
        cout << endl;
        for (const auto& woman : woman_to_invite) {
            cout << woman + 1 - left_size << ' ';
        }
        cout << endl;

    }

    int left_size, right_size;
    vector<unordered_set<int>> left_half;
    vector<int> pair_from_left;
};

int main() {
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int man_q, woman_q;
        cin >> man_q >> woman_q;

        BipartiteGraph g(man_q, woman_q);
        for (int cur_man = 0; cur_man < man_q; ++cur_man) {
            int cur_woman;
            cin >> cur_woman;
            while (cur_woman) {
                --cur_woman;
                g.AddEdge(cur_man, cur_woman);
                cin >> cur_woman;
            }
        }

        g.MIS();
    }
}


