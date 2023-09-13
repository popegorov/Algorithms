#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    Tree(long long vertex_count) :
            graph(vertex_count),
            up(vertex_count, vector<long long>(20)),
            tin(vertex_count, -1),
            tout(vertex_count, -1) {}

    void AddEdge(long long start_v, long long end_v) {
        graph[start_v].push_back(end_v);
        graph[end_v].push_back(start_v);
    }

    void Prepare() {
        dfs(0, 0);
    }

    bool isAncestor(long long anc, long long child) {
        return tin[anc] <= tin[child] && tout[child] <= tout[anc];
    }

    long long LCA(long long v1, long long v2) {
        if (isAncestor(v1, v2)) {
            return v1;
        }
        if (isAncestor(v2, v1)) {
            return v2;
        }
        for (long long ancestor = up[v1].size() - 1; ancestor >= 0; --ancestor) {
            if (!isAncestor(up[v1][ancestor], v2)) {
                v1 = up[v1][ancestor];
            }
        }
        return up[v1][0];
    }

private:

    void dfs(long long v, long long parent) {
        up[v][0] = parent;

        for (long long i = 1; i < up[v].size(); ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }

        tin[v] = t++;
        for (const auto &neighbour: graph[v]) {
            if (neighbour != parent) {
                dfs(neighbour, v);
            }
        }
        tout[v] = t++;
    }

    vector<long long> tin;
    vector<long long> tout;
    long long t = 0;
    vector<vector<long long>> graph;
    vector<vector<long long>> up;
};

int main() {
    long long n, m;
    cin >> n >> m;
    Tree t(n);

    for (long long i = 1; i < n; ++i) {
        long long cur_parent;
        cin >> cur_parent;
        t.AddEdge(i, cur_parent);
    }

    long long a0, a1, x, y, z;
    cin >> a0 >> a1 >> x >> y >> z;
    t.Prepare();
    long long prev_ans = 0;
    long long res = 0;

    for (long long i = 0; i < m; ++i) {
        prev_ans = t.LCA((a0 + prev_ans) % n, a1);
        res += prev_ans;
        a0 = (x * a0 + y * a1 + z) % n;
        a1 = (x * a1 + y * a0 + z) % n;
    }

    cout << res;
}
