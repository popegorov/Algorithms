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
    void push_back(int value, bool flag) {
        if (flag) {
            root1 = merge(root1, new Node(value));
        } else {
            root2 = merge(root2, new Node(value));
        }
    }

    long long ValueSumBetween(int l, int r) {
        Node *left1, *left2;
        Node *mid1, *mid2;
        Node *right1, *right2;

        int l1 = (l + 1) / 2, r1 = r / 2;
        int l2 = l / 2, r2 = (r + 1) / 2 - 1;

        split(root1, l1, left1, right1);
        split(right1, r1 - l1 + 1, mid1, right1);

        split(root2, l2, left2, right2);
        split(right2, r2 - l2 + 1, mid2, right2);

        long long result = GetTreeValueSum(mid1) + GetTreeValueSum(mid2);
        root1 = merge(merge(left1, mid1), right1);
        root2 = merge(merge(left2, mid2), right2);
        return result;
    }


    void Swap(int l, int r) {
        Node *left1, *left2;
        Node *mid1, *mid2;
        Node *right1, *right2;

        int l1 = (l + 1) / 2, r1 = r / 2;
        int l2 = l / 2, r2 = (r + 1) / 2 - 1;

        split(root1, l1, left1, right1);
        split(right1, r1 - l1 + 1, mid1, right1);

        split(root2, l2, left2, right2);
        split(right2, r2 - l2 + 1, mid2, right2);

        root1 = merge(merge(left1, mid2), right1);
        root2 = merge(merge(left2, mid1), right2);
    }

    void in_order() {
        print(root1);
        cout << endl;
        print(root2);
        cout << endl;
    }

private:
    inline static minstd_rand generator;

    struct Node {
        int value;
        int priority;
        Node *l = nullptr;
        Node *r = nullptr;
        int tree_size = 1;
        long long tree_value_sum = value;

        Node(int value) : value(value), priority(generator()) {}
    };

    int GetTreeSize(Node *n) {
        if (!n) {
            return 0;
        } else {
            return n->tree_size;
        }
    }

    long long GetTreeValueSum(Node *n) {
        if (!n) {
            return 0;
        } else {
            return n->tree_value_sum;
        }
    }

    void Update(Node *n) {
        if (n) {
            n->tree_size = GetTreeSize(n->l) + GetTreeSize(n->r) + 1;
            n->tree_value_sum = GetTreeValueSum(n->l) + GetTreeValueSum(n->r) + n->value;
        }
    }
public:
    Node *root1 = nullptr, *root2 = nullptr;
private:
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
        cout << n->value << ' ';
        print(n->r);
    }
};


int main() {
    Treap t;

    int n, m;
    cin >> n >> m;
    int cnt = 1;
    while (n != 0 || m != 0) {
        t.root1 = t.root2 = nullptr;
        cout << "Swapper " << cnt << ":\n";
        for (int i = 1; i < n + 1; ++i) {
            int a;
            cin >> a;
            t.push_back(a, i % 2);
        }

        for (int i = 0; i < m; ++i) {
            int type, l, r;
            cin >> type >> l >> r;
            --l;
            --r;
            if (type == 1) {
                t.Swap(l, r);
            } else {
                cout << t.ValueSumBetween(l, r) << endl;
            }
        }
        cin >> n >> m;
        ++cnt;
    }

    return 0;
}


