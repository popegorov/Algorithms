#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    Tree(long long vertex_count) :
            graph(vertex_count),
            n(vertex_count),
            depth_tin(vertex_count),
            depth(vertex_count),
            tin(vertex_count, -1),
            tout(vertex_count, -1) {}

    void AddEdge(long long start_v, long long end_v) {
        graph[start_v].push_back(end_v);
        graph[end_v].push_back(start_v);
    }

    void Prepare(long long root) {
        dfs(root, root, 0);
    }

    bool isAncestor(long long anc, long long child) {
        return tin[anc] <= tin[child] && tout[child] <= tout[anc];
    }

    long long Count(long long v, long long k) {
        return upper_bound(depth_tin[min(n - 1, k + depth[v])].begin(), depth_tin[min(n - 1, k + depth[v])].end(),
                           tout[v]) -
               lower_bound(depth_tin[min(n - 1, k + depth[v])].begin(), depth_tin[min(n - 1, k + depth[v])].end(),
                           tin[v]);
    }

private:

    void dfs(long long v, long long parent, long long cur_depth) {
        depth[v] = cur_depth;
        depth_tin[cur_depth].push_back(t);
        tin[v] = t++;
        for (const auto &neighbour: graph[v]) {
            if (neighbour != parent) {
                dfs(neighbour, v, cur_depth + 1);
            }
        }
        tout[v] = t++;
    }

    vector<long long> tin, tout, depth;
    long long t = 0;
    long long n;
    vector<vector<long long>> graph, depth_tin;
};

int main() {
    long long n, root;
    cin >> n;
    Tree t(n);

    for (long long i = 0; i < n; ++i) {
        long long cur_parent;
        cin >> cur_parent;
        if (cur_parent != -1) {
            --cur_parent;
            t.AddEdge(i, cur_parent);
        } else {
            root = i;
        }
    }

    t.Prepare(root);
    long long m;
    cin >> m;;

    for (long long i = 0; i < m; ++i) {
        long long v, k;
        cin >> v >> k;
        --v;
        cout << t.Count(v, k) << endl;
    }
}
