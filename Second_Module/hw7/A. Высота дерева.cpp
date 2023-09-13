#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
    Node *left = nullptr, *right = nullptr;

    Node(int key) : key(key) {}
};

class bin_tree {
public:
    bool contains(int key) const {
        return contains(root, key);
    }

    void insert(int key) {
        insert(root, key);
    }

    int GetDepth() const {
        int depth = 0;
        getdepth(root, 1, depth);
        return depth;
    }

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

    void insert(Node *&n, int key) {
        if (!n) {
             n = new Node(key);
             return;
        }
        if (key == n->key) {
            return;
        }
        if (key < n->key) {
            insert(n->left, key);
        } else {
            insert(n->right, key);
        }
    }

    void getdepth(Node *n, int cur_depth, int &depth) const {
        if (!n) {
            return;
        }
        depth = max(depth, cur_depth);
        getdepth(n->left, cur_depth + 1, depth);
        getdepth(n->right, cur_depth + 1, depth);
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
    cout << BTS.GetDepth();
}


