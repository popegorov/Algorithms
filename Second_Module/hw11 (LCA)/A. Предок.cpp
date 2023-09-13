#include <iostream>
#include <vector>

using namespace std;


struct Tree {
    Tree(int vertex_count) : graph(vertex_count), tin(vertex_count, -1), tout(vertex_count, -1) {}

    void AddEdge(int start_v, int end_v) {
        graph[start_v].push_back(end_v);
        graph[end_v].push_back(start_v);
    }

    void Prepare(int root) {
        dfs(root);
    }

    bool isAncestor(int anc, int child) {
        return tin[anc] <= tin[child] && tout[child] <= tout[anc];
    }

private:

    void dfs(int v) {
        tin[v] = t++;
        for (const auto& neighbour : graph[v]) {
            if (tin[neighbour] == -1) {
                dfs(neighbour);
            }
        }
        tout[v] = t++;
    }

    vector<int> tin;
    vector<int> tout;
    int t = 0;
    vector<vector<int>> graph;
};

int main() {
    int n;
    cin >> n;
    Tree t(n);
    int root;

    for(int i = 0; i < n; ++i) {
        int cur_parent;
        cin >> cur_parent;
        if (cur_parent) {
            t.AddEdge(i, cur_parent - 1);
        } else {
            root = i;
        }
    }

    t.Prepare(root);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << t.isAncestor(a, b) << endl;
    }
}


