#include <iostream>
#include <vector>

using namespace std;

class PersistentQueue {
public:
    PersistentQueue(int n) : size(n) {
        Create(&root, 0, n - 1);
        versions.push_back({&root, 0, 0});
    }

    void Push(int prev, int val) {
        auto new_version = Set(versions[prev].version, 0, size - 1, versions[prev].tail, val);
        versions.push_back({new_version, versions[prev].head, versions[prev].tail + 1});
    }

    int Pop(int prev) {
        versions.push_back({versions[prev].version, versions[prev].head + 1, versions[prev].tail});
        return Get(versions[prev].version, 0, size - 1, versions[prev].head);
    }

private:
    struct Node {
        Node(Node* l, Node* r,int value) : val(value), left(l), right(r) {}
        Node() : val(0), left(nullptr), right(nullptr) {}

        Node* left = nullptr;
        Node* right = nullptr;
        int val = 0;
    } root;

    struct Status {
        Node* version = nullptr;
        int head = 0;
        int tail = 0;
    };

    void Create(Node* now, int l, int r) {
        if (l == r) {
            return;
        }

        int m = (l + r) / 2;

        auto left = now->left = new Node;
        Create(left, l, m);

        auto right = now->right = new Node;
        Create(right, m + 1, r);
    }

    int Get(Node* now, int l, int r, int q) const {
        if (l == r) {
            return now->val;
        }

        int m = (l + r) / 2;
        if (q <= m) {
            return Get(now->left, l, m, q);
        } else {
            return Get(now->right, m + 1, r, q);
        }
    }



    Node* Set(Node* now, int l, int r, int q, int new_val) {
        if (l == r) {
            return new Node(nullptr, nullptr, new_val);
        }

        int m = (l + r) / 2;
        if (q <= m) {
            return new Node(Set(now->left, l, m, q, new_val), now->right, 0);
        } else {
            return new Node(now->left, Set(now->right, m + 1, r, q, new_val), 0);
        }
    }

    int size;
    vector<Status> versions;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    PersistentQueue p_queue(n);

    for (int i = 1; i < n + 1; ++i) {
        int type, version;
        cin >> type >> version;
        if (type == 1) {
            int value;
            cin >> value;
            p_queue.Push(version, value);
        } else {
            cout << p_queue.Pop(version) << '\n';
        }
    }
}

