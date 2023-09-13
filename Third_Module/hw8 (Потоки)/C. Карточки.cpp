#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int INF = 1e9;

class Graph {
public:

    Graph(string name) : graph(1 + 26 * 26 + 26 + 1), visited(1 + 26 * 26 + 26 + 1),
                                          edge_to(1 + 26 * 26 + 26 + 1), name(name) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                AddEdge(1 + i * 26 + j, 1 + 26 * 26 + i, INF, true);
                AddEdge(1 + i * 26 + j, 1 + 26 * 26 + j, INF, false);
            }
        }
    }

    void AddEdge(int start, int end, int capacity, bool is_front) {
        edges.push_back({start, end, capacity, is_front});
        graph[start].push_back(edges.size() - 1);
        graph[end].push_back(edges.size() - 1);
    }

    vector<string> MaxFlow(int start, int end) {
        long long max_flow = 0;

        while (HasPath(start, end)) {
            int delta_flow = FindMaxFlow(start, end);
            AddFlow(start, end, delta_flow);
            max_flow += delta_flow;
        }

        if (max_flow < name.size()) {
            cout << "IMPOSSIBLE";
            exit(0);
        } else {
            vector<string> answer;
            for (const auto& letter : name) {
                auto cur_vertex = 1 + 26 * 26 + (letter - 'a');
                for (const auto& edge : graph[cur_vertex]) {
                    if (edges[edge].flow && edges[edge].start != cur_vertex) {
                        string cur_card;
                        cur_card += 'a' + (edges[edge].start - 1) / 26;
                        cur_card += 'a' + (edges[edge].start - 1) % 26;
                        answer.push_back(cur_card);
                        --edges[edge].flow;
                        break;
                    }
                }
            }
            return answer;
        }
    }

private:

    struct Edge {
        int start;
        int end;
        int capacity;
        bool is_front;
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

        void AddFlowTo(int v, int delta_flow) {
            if (v == end) {
                flow += delta_flow;
            } else {
                flow -= delta_flow;
            }
        }
    };

    void BFS(int start) {
        visited.assign(graph.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            auto cur_v = q.front();
            q.pop();
            for (const auto &edge: graph[cur_v]) {
                auto neighbour = edges[edge].Opposite(cur_v);
                if (!visited[neighbour] && edges[edge].CapacityTo(neighbour)) {
                    edge_to[neighbour] = edge;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }

    bool HasPath(int start, int end) {
        visited.assign(graph.size(), false);
        BFS(start);
        return visited[end];
    }

    int FindMaxFlow(int start, int end) {
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

    string name;
    vector<Edge> edges;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> edge_to;
};

int main() {
    int n;
    cin >> n;
    unordered_map<string, unordered_set<int>> cards;
    for (int card_index = 1; card_index < n + 1; ++card_index) {
        string cur_card;
        cin >> cur_card;
        cards[cur_card].insert(card_index);
    }
    string name;
    cin >> name;
    unordered_map<char, int> letters;
    for (const auto& c : name) {
        ++letters[c];
    }

    if (name.size() > n) {
        cout << "NO";
        return 0;
    }
    Graph g(name);

    for (auto& [card, indexes] : cards) {
        g.AddEdge(0, 1 + (card[0] - 'a') * 26 + (card[1] - 'a'), indexes.size(), false);
    }

    for (auto& [letter, cnt] : letters) {
        g.AddEdge(1 + 26 * 26 + (letter - 'a'), 1 + 26 * 26 + 26, cnt, false);
    }

    auto matching = g.MaxFlow(0, 1 + 26 * 26 + 26);

    for (int i = 0; i < matching.size(); ++i) {
        auto index = *cards[matching[i]].begin();
        cards[matching[i]].erase(*cards[matching[i]].begin());
        if (name[i] == matching[i][0]) {
            cout << index << ' ';
        } else {
            cout << '-' << index << ' ';
        }
    }
}
