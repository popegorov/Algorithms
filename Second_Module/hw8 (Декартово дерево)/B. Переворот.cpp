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
    void push_back(int value) {
        root = merge(root, new Node(value));
    }

    void push_front(int value) {
        root = merge(new Node(value), root);
    }

    void insert(int pos, int value) {
        Node *left;
        Node *right;

        split(root, pos, left, right);

        root = merge(left, new Node(value));
        root = merge(root, right);
    }

    void erase(int l, int r) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, l, left, right);
        split(right, r - l + 1, mid, right);

        root = merge(left, right);
    }

    void in_order() {
        print(root);
        cout << endl;
    }

    int size() {
        return GetTreeSize(root);
    }

    int ValueMinBetween(int l, int r) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, l, left, right);
        split(right, r - l + 1, mid, right);
        int result = GetTreeValueMin(mid);
        left = merge(left, mid);
        root = merge(left, right);
        return result;
    }

    void Reverse(int l, int r) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, l, left, right);
        split(right, r - l + 1, mid, right);
        if (mid) {
            mid->reversed ^= true;
        }
        left = merge(left, mid);
        root = merge(left, right);
    }

private:
    inline static minstd_rand generator;

    struct Node {
        int value;
        int priority;
        Node *l = nullptr;
        Node *r = nullptr;
        int tree_size = 1;
        int tree_value_min;
        bool reversed = false;

        Node(int value) : value(value), priority(generator()), tree_value_min(value) {}
    };

    int GetTreeSize(Node *n) {
        if (!n) {
            return 0;
        } else {
            return n->tree_size;
        }
    }

    int GetTreeValueMin(Node *n) {
        if (!n) {
            return 1e9;
        } else {
            return n->tree_value_min;
        }
    }

    void Update(Node *n) {
        if (n) {
            n->tree_size = GetTreeSize(n->l) + GetTreeSize(n->r) + 1;
            n->tree_value_min = min(min(GetTreeValueMin(n->l), GetTreeValueMin(n->r)), n->value);
        }
    }

    void Push(Node* n) {
        if(n && n->reversed) {
            auto a = n->l;
            n->l = n->r;
            n->r = a;

            n->reversed = false;
            if (n->l) {
                n->l->reversed ^= true;
            }
            if (n->r) {
                n->r->reversed ^= true;
            }
        }
    }

    Node *root = nullptr;

    Node *merge(Node *a, Node *b) {
        Push(a);
        Push(b);
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
        Push(n);
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
        Push(n);
        if (!n) {
            return;
        }
        print(n->l);
        cout << n->value << ' ';
        print(n->r);
    }
};


int main() {
    Treap t;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        t.push_back(s);
    }

    for (int i = 0; i < m; ++i) {
        int type, l, r;
        cin >> type >> l >> r;
        --l;
        --r;
        if (type == 2) {
            cout << t.ValueMinBetween(l, r) << endl;
        } else {
            t.Reverse(l, r);
        }
    }
    return 0;
}


