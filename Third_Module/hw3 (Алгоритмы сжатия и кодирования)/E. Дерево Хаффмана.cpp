#include <cmath>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    bool isLeft = false;
    string word;
};

vector<string> build (const string& code) {
    auto cur_node = new Node;
    vector<string> ans;

    for (const auto& chr : code) {
        if (chr == 'D' && !cur_node->left) {

            auto new_node = cur_node->left = new Node;
            new_node->parent = cur_node;
            new_node->word = cur_node->word + '0';
            cur_node = new_node;
            cur_node->isLeft = true;

        } else if (chr == 'D') {

            auto new_node = cur_node->right = new Node;
            new_node->parent = cur_node;
            new_node->word = cur_node->word + '1';
            cur_node = new_node;

        } else {

            ans.push_back(cur_node->word);

            cur_node = cur_node->parent;
            while (cur_node->right) {
                cur_node = cur_node->parent;
            }

            if (!cur_node->right) {
                auto new_node = cur_node->right = new Node;
                new_node->parent = cur_node;
                new_node->word = cur_node->word + '1';
                cur_node = new_node;
            }

        }
    }

    if (!cur_node->word.empty()) {
        ans.push_back(cur_node->word);
    }

    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<string> codes(n);

    for (int i = 0; i < n; ++i) {
        cin >> codes[i];

    }

    for (int i = 0; i < n; ++i) {
        auto res = build(codes[i]);
        cout << res.size() << endl;
        for (const auto& cur_code : res) {
            cout << cur_code << endl;
        }
    }
}


