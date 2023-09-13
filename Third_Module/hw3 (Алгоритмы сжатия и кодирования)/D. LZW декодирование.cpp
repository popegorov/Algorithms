#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> code(n);
    for (int i = 0; i < n; ++i) {
        cin >> code[i];
    }

    unordered_map<int, string> dict;
    int dict_size = 128;
    for (int i = 0; i < dict_size; ++i) {
        string value;
        value += static_cast<char>(i);
        dict[i] = value;
    }

    string cur_str;
    cout << dict[code[0]];

    for (int i = 1; i < n; ++i) {
        if (dict.contains(code[i])) {
            dict[dict_size++] = dict[code[i - 1]] + dict[code[i]][0];
            cout << dict[code[i]];
        } else {
            dict[dict_size++] = dict[code[i - 1]] + dict[code[i - 1]][0];
            cout << dict[code[i]];
        }
    }
}


