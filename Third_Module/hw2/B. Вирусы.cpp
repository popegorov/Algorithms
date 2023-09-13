#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    bool isTerminal = false;
    int visited = 0;
    Node* from = nullptr;
    map<char, Node> next;
    Node* suffix_link = nullptr;
    map<char, Node*> go_links;
} root;

class Aho_Corasick {
public:

    void Prepare() {
        queue<Node*> q;
        root.suffix_link = &root;
        q.push(&root);

        while (!q.empty()) {
            auto now = q.front();
            q.pop();

            for (auto& [chr, to] : now->next) {
                if (now == &root) {
                    to.suffix_link = &root;
                } else {
                    to.suffix_link = now->suffix_link->go_links[chr];
                }
                q.push(&to);
            }

            for (char c = '0'; c < '2'; ++c) {
                if (now ->next.contains(c)) {
                    now->go_links[c] = &now->next[c];
                } else if (now == &root) {
                    now->go_links[c] = &root;
                } else {
                    now->go_links[c] = now->suffix_link->go_links[c];
                }
            }

            if (now->suffix_link->isTerminal) {
                now->isTerminal = true;
            }
        }
    }

    void NewWord(const string& word) {
        Node* now = &root;

        for (const char& c : word) {
            now = &now->next[c];
        }

        now->isTerminal = true;
    }

    void CheckForCycles (Node* now) {
        now->visited = 1;
        for (auto &[chr, to]: now->go_links) {
            if (!to->visited && !to->isTerminal) {

                to->from = now;
                CheckForCycles( to);

            } else if (to->visited == 1) {

                bool isCycle = true;
                for (Node* cycle_v = now; cycle_v != to; cycle_v = cycle_v->from) {
                    if (cycle_v->isTerminal) {
                        isCycle = false;
                        break;
                    }
                }

                if (isCycle && !to->isTerminal) {
                    cout << "TAK";
                    exit(0);
                }

            }
        }
        now->visited = 2;
    }

};

int main() {
    int n;
    cin >> n;
    Aho_Corasick g;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        g.NewWord(str);
    }
    g.Prepare();
    g.CheckForCycles(&root);
    cout << "NIE";
}


