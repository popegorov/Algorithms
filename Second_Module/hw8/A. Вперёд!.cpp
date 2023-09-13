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

    int operator[](int pos) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, pos, left, right);
        split(right, 1, mid, right);

        int result = GetTreeValueSum(mid);
        left = merge(left, mid);
        root = merge(left, right);
        return result;
    }

    void in_order() {
        print(root);
        cout << endl;
    }

    int size() {
        return GetTreeSize(root);
    }

    void cut(int l, int  r) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, l, left, right);
        split(right, r - l + 1, mid, right);

        root = merge(merge(mid, left), right);
    }

    int ValueSumBetween(int l, int r) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, l, left, right);
        split(right, r - l + 1, mid, right);
        int result = GetTreeValueSum(mid);
        left = merge(left, mid);
        root = merge(left, right);
        return result;
    }

    int ValueMaxBetween(int l, int r) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, l, left, right);
        split(right, r - l + 1, mid, right);
        int result = GetTreeValueMax(mid);
        left = merge(left, mid);
        root = merge(left, right);
        return result;
    }

    void ValueAddBetween(int l, int r, int value_add) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, l, left, right);
        split(right, r - l + 1, mid, right);
        if (mid) {
            mid->tree_value_add += value_add;
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
        int tree_value_sum;
        int tree_value_max;
        int tree_value_add = 0;

        Node(int value) : value(value), priority(generator()), tree_value_sum(value), tree_value_max(value) {}
    };

    int GetTreeSize(Node *n) {
        if (!n) {
            return 0;
        } else {
            return n->tree_size;
        }
    }

    int GetTreeValueSum(Node *n) {
        if (!n) {
            return 0;
        } else {
            return n->tree_value_sum + n->tree_value_add * n->tree_size;
        }
    }

    int GetTreeValueMax(Node *n) {
        if (!n) {
            return -1e9;
        } else {
            return n->tree_value_max + n->tree_value_add;
        }
    }

    void Update(Node *n) {
        if (n) {
            n->tree_size = GetTreeSize(n->l) + GetTreeSize(n->r) + 1;
            n->tree_value_sum = GetTreeValueSum(n->l) + GetTreeValueSum(n->r) + n->value;
            n->tree_value_max = max(max(GetTreeValueMax(n->l), GetTreeValueMax(n->r)), n->value);
        }
    }

    void Push(Node* n) {
        if(n && n->tree_value_add) {
            n->value += n->tree_value_add;
            n->tree_value_sum += n->tree_size * n->tree_value_add;
            n->tree_value_max += n->tree_value_add;
            if(n->l) {
                n->l->tree_value_add += n->tree_value_add;
            }
            if(n->r) {
                n->r->tree_value_add += n->tree_value_add;
            }
            n->tree_value_add = 0;
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
        t.push_back(i + 1);
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        t.cut(l,r);
    }

    t.in_order();
    return 0;
}


