#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

class Treap {
    struct Node {
        long long value;
        long long priority;
        Node *l = nullptr;
        Node *r = nullptr;
        long long tree_size = 1;
        long long tree_value_sum;

        Node(long long value) : value(value), priority(generator()), tree_value_sum(value * value) {}
    };

public:
    void push_back(long long value) {
        root = merge(root, new Node(value));
    }

    void insert(long long pos, long long value) {
        Node *left;
        Node *right;

        split(root, pos, left, right);

        root = merge(left, new Node(value));
        root = merge(root, right);
    }

    void erase(long long pos) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, pos, left, right);
        split(right, 1, mid, right);

        root = merge(left, right);
    }

    long long size() {
        return GetTreeSize(root);
    }

    long long GetSqSum() {
        return GetTreeValueSum(root);
    }

    void Bankrot(long long pos) {
        auto len = GetNodeByKey(pos)->value;
        if (!pos) {
            GetNodeByKey(pos + 1)->value += len;
        } else if (pos == size() - 1) {
            GetNodeByKey(pos - 1)->value += len;
        } else {
            auto len_for_first = len / 2;
            auto len_for_second = len - len_for_first;
            GetNodeByKey(pos - 1)->value += len_for_first;
            GetNodeByKey(pos + 1)->value += len_for_second;
        }
        erase(pos);

        cout << GetSqSum() << endl;
    }

    void NewPart(long long pos) {
        auto len = GetNodeByKey(pos)->value;
        GetNodeByKey(pos)->value = len / 2;
        insert(pos + 1, len - len / 2);
        cout << GetSqSum() << endl;
    }

    Node* GetNodeByKey(long long pos) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, pos, left, right);
        split(right, 1, mid, right);

        left = merge(left, mid);
        root = merge(left, right);
        return mid;
    }

    Node* operator[](long long pos) {
        Node *left;
        Node *mid;
        Node *right;

        split(root, pos, left, right);
        split(right, 1, mid, right);

        left = merge(left, mid);
        root = merge(left, right);
        return mid;
    }

private:
    inline static minstd_rand generator;

    long long GetTreeSize(Node *n) {
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
            n->tree_value_sum = GetTreeValueSum(n->l) + GetTreeValueSum(n->r) + n->value*n->value;
        }
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

    void split(Node *n, long long k, Node *&a, Node *&b) {
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
};


int main() {
    Treap t;

    long long n, p;
    cin >> n >> p;
    for (long long i = 0; i < n; ++i) {
        long long cur_len;
        cin >> cur_len;
        t.push_back(cur_len);
    }

    long long m;
    cin >> m;
    cout << t.GetSqSum() << endl;

    for (long long i = 0; i < m; ++i) {
        long long type, pos;
        cin >> type >> pos;
        --pos;
        if (type == 1) {
            t.Bankrot(pos);
        } else {
            t.NewPart(pos);
        }
    }

    return 0;
}
