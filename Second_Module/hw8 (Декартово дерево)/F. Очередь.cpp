#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

class Treap {
public:
    void in_order() {
        print(root);
        cout << endl;
    }

    void NewPerson(int a, int c, int i) {
        Node *first, *last, *before, *after;
        split(root, size() - c, first, last);

        new_split(last, a, before, after);
        root = merge(first, merge(before, merge(new Node(a, i), after)));
    }

private:
    inline static minstd_rand generator;

    struct Node {
        int value;
        int priority;
        Node *l = nullptr;
        Node *r = nullptr;
        int tree_size = 1;
        int tree_value_max;
        int cnt;

        Node(int value, int i) : value(value), priority(generator()), tree_value_max(value), cnt(i) {}
    };

    int size() {
        return GetTreeSize(root);
    }

    int GetTreeSize(Node *n) {
        if (!n) {
            return 0;
        } else {
            return n->tree_size;
        }
    }

    int GetTreeValueMax(Node *n) {
        if (!n) {
            return -1e9;
        } else {
            return n->tree_value_max;
        }
    }

    void Update(Node *n) {
        if (n) {
            n->tree_size = GetTreeSize(n->l) + GetTreeSize(n->r) + 1;
            n->tree_value_max = max(max(GetTreeValueMax(n->l), GetTreeValueMax(n->r)), n->value);
        }
    }

    void new_split(Node *n, int k, Node *&a, Node *&b) {
        if (!n) {
            a = nullptr;
            b = nullptr;
            return;
        }
        if (max(GetTreeValueMax(n->r), n->value) < k) {
            new_split(n->l, k, a, n->l);
            b = n;
        } else {
            new_split(n->r, k, n->r, b);
            a = n;
        }
        Update(a);
        Update(b);
    }

    Node *root = nullptr;

    Node *merge(Node *a, Node *b) {
        if (!a) {
            return b;
        }
        if (!b) {
            return a;
        }

        if (a->priority > b->priority) {
            a->r = merge(a->r, b);
            Update(a);
            return a;
        } else {
            b->l = merge(a, b->l);
            Update(b);
            return b;
        }
    }

    void split(Node *n, int k, Node *&a, Node *&b) {
        if (!n) {
            a = nullptr;
            b = nullptr;
            return;
        }
        if (GetTreeSize(n->l) >= k) {
            split(n->l, k, a, n->l);
            b = n;
        } else {
            split(n->r, k - GetTreeSize(n->l) - 1, n->r, b);
            a = n;
        }
        Update(a);
        Update(b);
    }


    void print(Node *n) {
        if (!n) {
            return;
        }
        print(n->l);
        cout << n->cnt << ' ';
        print(n->r);
    }
};


int main() {
    Treap t;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;
        t.NewPerson(a, c, i + 1);
    }

    t.in_order();
    return 0;
}


