#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    Tree(long long vertex_count) :
            graph(vertex_count),
            n(vertex_count),
            up(vertex_count, vector<long long>(20)),
            min_weight(vertex_count, vector<long long>(20)),
            tin(vertex_count, -1),
            tout(vertex_count, -1) {}

    void AddEdge(long long start_v, long long end_v, long long weight) {
        graph[start_v].push_back({end_v, weight});
        graph[end_v].push_back({start_v, weight});
    }

    void Prepare(long long root) {
        dfs(root, root, 1e9);
    }

    bool isAncestor(long long anc, long long child) {
        return tin[anc] <= tin[child] && tout[child] <= tout[anc];
    }

    long long LCA(long long v1, long long v2, long long &minWeight) {
        if (isAncestor(v1, v2)) {
            return v1;
        }
        for (long long ancestor = up[v1].size() - 1; ancestor >= 0; --ancestor) {
            if (!isAncestor(up[v1][ancestor], v2)) {
                minWeight = min(minWeight, min_weight[v1][ancestor]);
                v1 = up[v1][ancestor];
            }
        }
        minWeight = min(minWeight, min_weight[v1][0]);
        return up[v1][0];
    }

private:

    void dfs(long long v, long long parent, long long cur_weight) {
        up[v][0] = parent;
        min_weight[v][0] = cur_weight;

        for (long long i = 1; i < up[v].size(); ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
            min_weight[v][i] = min(min_weight[up[v][i - 1]][i - 1], min_weight[v][i - 1]);
        }

        tin[v] = t++;
        for (const auto &[neighbour, weight]: graph[v]) {
            if (neighbour != parent) {
                dfs(neighbour, v, weight);
            }
        }
        tout[v] = t++;
    }

    vector<long long> tin, tout;
    long long t = 0;
    long long n;
    vector<vector<pair<long long, long long>>> graph;
    vector<vector<long long>> up, min_weight;
};

int main() {
    long long n;
    cin >> n;
    Tree t(n);

    for (long long i = 1; i < n; ++i) {
        long long cur_parent, cur_weight;
        cin >> cur_parent >> cur_weight;
        --cur_parent;
        t.AddEdge(i, cur_parent, cur_weight);
    }

    t.Prepare(0);
    long long m;
    cin >> m;

    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        --x;
        --y;
        long long first_min = 1e9, second_min = 1e9;
        t.LCA(x, y, first_min);
        t.LCA(y, x, second_min);
        cout << min(first_min, second_min) << endl;
    }
}


