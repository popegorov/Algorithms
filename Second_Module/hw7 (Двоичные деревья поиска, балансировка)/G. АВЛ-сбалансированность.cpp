#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key, depth = 0;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;

    Node(int key) : key(key) {}
};

class bin_tree {
public:
    bool contains(int key) const {
        return contains(root, key);
    }

    void insert(int key) {
        insert(root, key, nullptr);
    }

    void IsAVL() {
        CountDepth(root);
        IsAVL(root);
    }

    bool isAvl = true;

private:
    bool contains(Node *n, int key) const {
        if (!n) {
            return false;
        }
        if (key == n->key) {
            return true;
        }
        if (key < n->key) {
            return contains(n->left, key);
        } else {
            return contains(n->right, key);
        }
    }

    void insert(Node *&n, int key, Node *parent) {
        if (!n) {
            n = new Node(key);
            n->parent = parent;
            return;
        }
        if (key == n->key) {
            return;
        }
        if (key < n->key) {
            insert(n->left, key, n);
        } else {
            insert(n->right, key, n);
        }
    }

    void CountDepth(Node *n) {
        if (!n) {
            return;
        }
        CountDepth(n->left);
        CountDepth(n->right);
        if (n->left && n->right) {
            n->depth = max(n->left->depth, n->right->depth) + 1;
        } else if (n->left) {
            n->depth = n->left->depth + 1;
        } else if (n->right) {
            n->depth = n->right->depth + 1;
        } else {
            n->depth = 1;
        }
    }

    void IsAVL(Node *n) {
        if (!n) {
            return;
        }
        if (n->left && n->right && abs(n->left->depth - n->right->depth) > 1) {
            isAvl = false;
        } else if (n->left && !n->right && n->left->depth > 1) {
            isAvl = false;
        } else if (!n->left && n->right && n->right->depth > 1) {
            isAvl = false;
        }
        IsAVL(n->left);
        IsAVL(n->right);
    }

    Node *root = nullptr;
};

int main() {
    int num;
    cin >> num;
    bin_tree BTS;
    while (num) {
        BTS.insert(num);
        cin >> num;
    }
    BTS.IsAVL();

    if (BTS.isAvl) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}


