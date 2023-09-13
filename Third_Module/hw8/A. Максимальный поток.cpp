#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:

    Graph(int n) : graph(n), visited(n), edge_to(n) {}

    void AddEdge(int start, int end, int capacity) {
        edges.push_back({start, end, capacity});
        graph[start].push_back(edges.size() - 1);
        graph[end].push_back(edges.size() - 1);
    }

    long long MaxFlow(int start, int end) {
        long long max_flow = 0;

        while (HasPath(start, end)) {
            int delta_flow = FindMaxFlow(start, end);
            AddFlow(start, end, delta_flow);
            max_flow += delta_flow;
        }

        return max_flow;
    }
private:

    struct Edge {
        int start;
        int end;
        int capacity;
        int flow = 0;

        int Opposite(int v) {
            return start + end - v;
        }

        int CapacityTo(int v) {
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

    void DFS(int v) {
        visited[v] = true;
        for (auto cur_edge : graph[v]) {
            int neighbour = edges[cur_edge].Opposite(v);
            if (!visited[neighbour] && edges[cur_edge].CapacityTo(neighbour)) {
                edge_to[neighbour] = cur_edge;
                DFS(neighbour);
            }
        }
    }

    bool HasPath(int start, int end) {
        visited.assign(graph.size(), false);
        DFS(start);
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
    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int start_e, end_e, capacity;
        cin >> start_e >> end_e >> capacity;
        --start_e;
        --end_e;
        g.AddEdge(start_e, end_e, capacity);
    }

    cout << g.MaxFlow(0, n - 1) << endl;
}
