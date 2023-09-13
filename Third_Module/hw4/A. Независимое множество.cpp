#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <unordered_set>
#include <vector>

using namespace std;

struct Graph {
    Graph (int n) : graph(n) {}

    void AddEdge(int start_e, int end_e) {
        graph[start_e].insert(end_e);
        graph[end_e].insert(start_e);
    }

    void Prepare(int s) {
        auto cnt = 0;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() <= graph.size() - s) {
                ++cnt;
            }
        }
        if (cnt < s) {
            cout << "NO";
            exit(0);
        }
    }

    void Recursive (vector<int>& cur_ind_set, int s) {
        if (cur_ind_set.size() >= s) {
            cout << "YES";
            exit(0);
        }
        int last = -1;
        if (!cur_ind_set.empty()) {
            last = cur_ind_set.back();
        }
        for (int cur_v = last + 1; cur_v < graph.size(); ++cur_v) {
            if (cur_ind_set.size() >= s) {
                cout << "YES";
                exit(0);
            }
            if (graph[cur_v].size() > graph.size() - s) {
                continue;
            }

            if (graph.size() - cur_v < s - cur_ind_set.size()) {
                return;
            }
            bool flag = true;
            for (const auto& v : cur_ind_set) {
                if (graph[cur_v].contains(v)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cur_ind_set.push_back(cur_v);
                Recursive(cur_ind_set, s);
                cur_ind_set.pop_back();
            }
        }
    }

    vector<unordered_set<int>> graph;
};

int main() {
    int n, s;
    cin >> n >> s;
    if (s == 1) {
        cout << "YES";
        exit(0);
    } else if (s > n) {
        cout << "NO";
        exit(0);
    }

    Graph g(n);
    int e;
    cin >> e;
    for (int i = 0; i < e; ++i) {
        int start_e, end_e;
        cin >> start_e >> end_e;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e);
    }
    g.Prepare(s);

    vector<int> cur_ind_set;
    g.Recursive(cur_ind_set, s);

    cout << "NO";
}


