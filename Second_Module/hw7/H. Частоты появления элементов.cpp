#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key, cnt = 1;
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

    void Print() {
        Print(root);
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
            ++n->cnt;
            return;
        }
        if (key < n->key) {
            insert(n->left, key, n);
        } else {
            insert(n->right, key, n);
        }
    }

    void Print(Node *n) const {
        if (!n) {
            return;
        }
        Print(n->left);
        cout << n->key << ' ' << n->cnt << endl;
        Print(n->right);
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
    BTS.Print();
}


