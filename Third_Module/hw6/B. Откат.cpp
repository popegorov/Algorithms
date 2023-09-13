#include <iostream>
#include <vector>

using namespace std;

class PersistentTree {
public:
    PersistentTree(int n, vector<int>& b, const vector<int>& next) : size(n), versions(n) {
        Create(&root, 0, size - 1, b);
        versions[0] = &root;
        for (int i = 1; i < size; ++i) {
            if (next[i - 1]) {
                versions[i] = Set(Set(versions[i - 1], 0, size - 1, i - 1, -1), 0, size - 1, next[i - 1], 1);
            } else {
                versions[i] = Set(versions[i - 1], 0, size - 1, i - 1, -1);
            }
        }
    }

    int Find(int l, int k) {
        return Find(versions[l], 0, size - 1, k) + 1;
    }

private:

    struct Node {
        Node(Node* l, Node* r,int value) : val(value), left(l), right(r) {}
        Node() : val(0), left(nullptr), right(nullptr) {}

        Node* left = nullptr;
        Node* right = nullptr;
        int val = 0;
    } root;

    Node* Set(Node* now, int l, int r, int q, int delta) {
        if (l == r) {
            return new Node(nullptr, nullptr, now->val + delta);
        }

        int m = (l + r) / 2;
        if (q <= m) {
            return new Node(Set(now->left, l, m, q, delta), now->right, now->val + delta);
        } else {
            return new Node(now->left, Set(now->right, m + 1, r, q, delta), now->val + delta);
        }
    }

    int Find(Node* now, int l, int r, int k) const {
        if (now->val < k) {
            return -1;
        }
        if (l == r) {
            return l;
        }

        int m = (l + r) / 2;
        if (now->left->val >= k) {
            return Find(now->left, l, m, k);
        } else {
            return Find(now->right, m + 1, r,  k - now->left->val);
        }
    }

    void Create(Node* now, int l, int r, const vector<int>& first_b) {
        if (l == r) {
            now->val = first_b[l];
            return;
        }

        int m = (l + r) / 2;

        now->left = new Node;
        Create(now->left, l, m, first_b);

        now->right = new Node;
        Create(now->right, m + 1, r, first_b);

        now->val = now->left->val + now->right->val;
    }

    vector<Node*> versions;
    int size;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<int> d(m, -1);
    vector<int> next(n);
    for(int i = 0; i < n; ++i) {
        if (d[a[i]] != -1) {
            next[d[a[i]]] = i;
        }
        d[a[i]] = i;
    }

    vector<bool> new_d(m);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        if (!new_d[a[i]]) {
            b[i] = 1;
            new_d[a[i]] = true;
        }
    }

    PersistentTree tree(n, b, next);

    int q;
    cin >> q;
    int p = 0;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        int l = (x + p) % n;
        int k = (y + p) % m + 1;
        p = tree.Find(l, k);
        cout << p << '\n';
    }
}


