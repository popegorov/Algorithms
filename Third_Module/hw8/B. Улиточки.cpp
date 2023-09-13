#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int n) : graph(n), visited(n), edge_to(n) {}

    void AddEdge(int start, int end) {
        if (start == end) {
            return;
        }
        edges.push_back({start, end, 1});
        graph[start].push_back(static_cast<int>(edges.size()) - 1);
        graph[end].push_back(static_cast<int>(edges.size()) - 1);
    }

    void FindPaths(int start, int end) {
        int max_flow = 0;
        while (HasPath(start, end)) {
            int delta_flow = FindMaxFlow(start, end);
            AddFlow(start, end, delta_flow);
            max_flow += delta_flow;
        }

        if (max_flow < 2) {
            cout << "NO";
        } else {
            cout << "YES" << endl;
            BFS2(start, end);

            cout << endl;

            BFS2(start, end);
        }
    }
private:

    struct Edge {
        int start;
        int end;
        int capacity;
        int flow = 0;

        int Opposite(int v) const {
            return start + end - v;
        }

        int CapacityTo(int v) const {
            if (v == end) {
                return capacity - flow;
            } else {
                return flow;
            }
        }

        void AddFlowTo (int v, int delta_flow) {
            if (v == end) {
                flow += delta_flow;
            } else {
                flow -= delta_flow;
            }
        }
    };

    void BFS2(int start,int end) {
        edge_to.assign(graph.size(), -1);
        visited.assign(graph.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            auto cur_v = q.front();
            q.pop();
            for (const auto& edge : graph[cur_v]) {
                auto neighbour = edges[edge].Opposite(cur_v);
                if (!visited[neighbour] && edges[edge].flow) {
                    edge_to[neighbour] = edge;
                    visited[neighbour] = true;
                    q.push(neighbour);
                    if (neighbour == end) {
                        vector<int> path;
                        for (auto v = end; v != start; v = edges[edge_to[v]].start) {
                            edges[edge_to[v]].flow = 0;
                            path.push_back(v);
                        }
                        path.push_back(start);
                        reverse(path.begin(), path.end());

                        for (const auto& v : path) {
                            cout << v + 1 << ' ';
                        }
                        return;
                    }
                }
            }
        }
    }

    void BFS(int start,int end) {
        edge_to.assign(graph.size(), -1);
        visited.assign(graph.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            auto cur_v = q.front();
            q.pop();
            for (const auto& edge : graph[cur_v]) {
                auto neighbour = edges[edge].Opposite(cur_v);
                if (!visited[neighbour] && edges[edge].CapacityTo(neighbour)) {
                    edge_to[neighbour] = edge;
                    visited[neighbour] = true;
                    q.push(neighbour);
                    if (neighbour == end) {
                        return;
                    }
                }
            }
        }
    }

    bool HasPath(int start, int end) {
        BFS(start, end);
        return visited[end];
    }

    int FindMaxFlow (int start, int end) {
        int max_flow = 1e9;
        for (int cur_v = end; cur_v != start; cur_v = edges[edge_to[cur_v]].Opposite(cur_v)) {
            max_flow = min(max_flow, edges[edge_to[cur_v]].CapacityTo(cur_v));
        }
        return max_flow;
    }

    void AddFlow(int start, int end, int delta_flow) {
        for (int cur_v = end; cur_v != start; cur_v = edges[edge_to[cur_v]].Opposite(cur_v)) {
            edges[edge_to[cur_v]].AddFlowTo(cur_v, delta_flow);
        }
    }

    vector<Edge> edges;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> edge_to;
};

int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    --start;
    --end;
    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int start_e, end_e;
        cin >> start_e >> end_e;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e);
    }

    g.FindPaths(start, end);
}
