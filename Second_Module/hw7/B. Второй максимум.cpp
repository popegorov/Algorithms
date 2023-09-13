#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
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

    int GetPrevMax() {
        auto n = root;
        while(n->right) {
            n = n->right;
        }

        if (n->left) {
            n = n->left;
            while(n->right) {
                n = n->right;
            }
            return n->key;
        } else {
            return n->parent->key;
        }
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
    cout << BTS.GetPrevMax();
}


